#include <iosfwd>
#include <vector>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>

void getExport32(std::ifstream &file) {
    if (!file.is_open()) {
        std::cerr << "Unable to open file." << std::endl;
        return;
    }

    file.seekg(0, std::ios::end);
    std::streampos fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<char> fileContent(fileSize);
    file.read(fileContent.data(), fileSize);

    auto* dosHeader = reinterpret_cast<PIMAGE_DOS_HEADER>(fileContent.data());
    auto* ntHeaders = reinterpret_cast<PIMAGE_NT_HEADERS32>(fileContent.data() + dosHeader->e_lfanew);

    PIMAGE_OPTIONAL_HEADER32 optHeader32 = &ntHeaders->OptionalHeader;
    PIMAGE_DATA_DIRECTORY exportTable = &optHeader32->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT];

    if (exportTable->VirtualAddress != 0 && exportTable->Size != 0) {
        PIMAGE_SECTION_HEADER sectionHeader = IMAGE_FIRST_SECTION(ntHeaders);

        for (int i = 0; i < ntHeaders->FileHeader.NumberOfSections; ++i) {
            if (exportTable->VirtualAddress >= sectionHeader[i].VirtualAddress &&
                exportTable->VirtualAddress < sectionHeader[i].VirtualAddress + sectionHeader[i].SizeOfRawData) {
                auto* exportDir = reinterpret_cast<PIMAGE_EXPORT_DIRECTORY>(
                        fileContent.data() + exportTable->VirtualAddress - sectionHeader[i].VirtualAddress +
                        sectionHeader[i].PointerToRawData);
                std::cout << "\n-------------------------------------------------------------------------------------------------" << std::endl;
                std::cout << "Export Table Address: 0x" << std::hex << sectionHeader[i].VirtualAddress << std::dec << std::endl;
                std::cout << "Export Table:\n";
                std::cout << "\tDLL Name: " << reinterpret_cast<const char*>(fileContent.data() + exportDir->Name - sectionHeader[i].VirtualAddress + sectionHeader[i].PointerToRawData) << std::endl;
                std::cout << "\tNumber of Functions: " << exportDir->NumberOfFunctions << std::endl;
                std::cout << "\tNumber of Names: " << exportDir->NumberOfNames << std::endl;

                auto* addrFunc = reinterpret_cast<DWORD*>(fileContent.data() + exportDir->AddressOfFunctions - sectionHeader[i].VirtualAddress + sectionHeader[i].PointerToRawData);
                auto* addrOrd = reinterpret_cast<WORD*>(fileContent.data() + exportDir->AddressOfNameOrdinals - sectionHeader[i].VirtualAddress + sectionHeader[i].PointerToRawData);
                auto* addrNames = reinterpret_cast<DWORD*>(fileContent.data() + exportDir->AddressOfNames - sectionHeader[i].VirtualAddress + sectionHeader[i].PointerToRawData);

                for (DWORD j = 0; j < exportDir->NumberOfNames; ++j) {
                    DWORD addr_rva = addrFunc[addrOrd[j]];
                    char* funcN = reinterpret_cast<char*>(fileContent.data() + addrNames[j] - sectionHeader[i].VirtualAddress + sectionHeader[i].PointerToRawData);
                    std::cout << "\tAddress: 0x" << std::hex << addr_rva + optHeader32->ImageBase << std::dec << std::setw(20)
                              << "\tOrdinal: " << addrOrd[j] + exportDir->Base << std::setw(20)
                              << "\tFunction: " << (funcN ? funcN : "Ordinal") << std::setw(20) << std::endl;
                }
                break;
            }
        }
    } else {
        std::cout << "Export Table is not found." << std::endl;
    }
    std::cout << "\n";
}