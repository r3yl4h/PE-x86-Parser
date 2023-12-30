#include <iostream>
#include <iomanip>
#include <windows.h>
#include "peh.hpp"

void edata(const CHAR* path) {
    HANDLE hFile = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

    if (hFile == INVALID_HANDLE_VALUE){
        CloseHandle(hFile);
        std::cout << "the file does not exist or we were unable to open it" << std::endl;
    }

    DWORD fileSize = GetFileSize(hFile, nullptr);
    BYTE* fileContent = new BYTE[fileSize];
    DWORD bytesRead;

    if (!ReadFile(hFile, fileContent, fileSize, &bytesRead, nullptr)) {
        std::cerr << "Error reading file." << std::endl;
        delete[] fileContent;
        return;
    }

    auto dosHeader = reinterpret_cast<PIMAGE_DOS_HEADER>(fileContent);
    auto ntHeaders = reinterpret_cast<PIMAGE_NT_HEADERS>(fileContent + dosHeader->e_lfanew);

    PIMAGE_OPTIONAL_HEADER64 optHeader64 = &ntHeaders->OptionalHeader;
    PIMAGE_DATA_DIRECTORY exportTable = &optHeader64->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT];

    if (exportTable->VirtualAddress != 0 && exportTable->Size != 0) {
        PIMAGE_SECTION_HEADER sectionHeader = IMAGE_FIRST_SECTION(ntHeaders);
        std::cout << "\nExport Table Address: 0x" << std::hex << exportTable->VirtualAddress + optHeader64->ImageBase << std::dec << std::endl;

        for (int i = 0; i < ntHeaders->FileHeader.NumberOfSections; ++i) {
            if (exportTable->VirtualAddress >= sectionHeader[i].VirtualAddress &&
                exportTable->VirtualAddress < sectionHeader[i].VirtualAddress + sectionHeader[i].SizeOfRawData) {
                auto exportDir = reinterpret_cast<PIMAGE_EXPORT_DIRECTORY>(
                        fileContent + exportTable->VirtualAddress - sectionHeader[i].VirtualAddress +
                        sectionHeader[i].PointerToRawData);

                std::cout << "Export Table:\n";
                std::cout << "\tDLL Name: " << reinterpret_cast<const char*>(fileContent + exportDir->Name - sectionHeader[i].VirtualAddress + sectionHeader[i].PointerToRawData) << std::endl;
                std::cout << "\tNumber of Functions: " << exportDir->NumberOfFunctions << std::endl;
                std::cout << "\tNumber of Names: " << exportDir->NumberOfNames << std::endl;

                auto* addrFunc = reinterpret_cast<DWORD*>(fileContent + exportDir->AddressOfFunctions - sectionHeader[i].VirtualAddress + sectionHeader[i].PointerToRawData);
                auto* addrOrd = reinterpret_cast<WORD*>(fileContent + exportDir->AddressOfNameOrdinals - sectionHeader[i].VirtualAddress + sectionHeader[i].PointerToRawData);
                auto* addrNames = reinterpret_cast<DWORD*>(fileContent + exportDir->AddressOfNames - sectionHeader[i].VirtualAddress + sectionHeader[i].PointerToRawData);

                for (DWORD j = 0; j < exportDir->NumberOfNames; ++j) {
                    DWORD functionRVA = addrFunc[addrOrd[j]];
                    std::cout << "\tAddress: 0x" << std::hex << optHeader64->ImageBase + functionRVA << std::dec << std::setw(20)
                              << "\tOrdinal: " << addrOrd[j] + exportDir->Base << std::setw(20)
                              << " \tFunction: " << reinterpret_cast<const char*>(fileContent + addrNames[j] - sectionHeader[i].VirtualAddress + sectionHeader[i].PointerToRawData) << std::setw(20) << std::endl;
                }
                break;
            }
        }
    } else {
        std::cout << "Export Table is not found." << std::endl;
    }

    std::cout << "\n";

    delete[] fileContent;
}
