#include <iostream>
#include <fstream>
#include <iomanip>
#include <cxxabi.h>
#include <vector>
#include <windows.h>

void getImport32(std::ifstream &file) {
    file.seekg(0, std::ios::end);
    std::streampos fileSize = file.tellg();
    file.seekg(0, std::ios::beg);
    std::vector<char> fileContent(fileSize);
    if (!file.read(fileContent.data(), fileSize)) {
        std::cerr << "Error reading file." << std::endl;
        return;
    }
    auto dosHeader = reinterpret_cast<PIMAGE_DOS_HEADER>(fileContent.data());
    auto ntHeaders = reinterpret_cast<PIMAGE_NT_HEADERS32>(fileContent.data() + dosHeader->e_lfanew);
    PIMAGE_OPTIONAL_HEADER32 optHeader32 = &ntHeaders->OptionalHeader;
    PIMAGE_DATA_DIRECTORY importTable = &optHeader32->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
    if (importTable->VirtualAddress != 0 && importTable->Size != 0) {
        PIMAGE_SECTION_HEADER sectionHeader = IMAGE_FIRST_SECTION(ntHeaders);
        for (int i = 0; i < ntHeaders->FileHeader.NumberOfSections; ++i) {
            if (importTable->VirtualAddress >= sectionHeader[i].VirtualAddress && importTable->VirtualAddress < sectionHeader[i].VirtualAddress + sectionHeader[i].SizeOfRawData) {
                std::cout << std::hex << " Import Section address: 0x" << sectionHeader[i].VirtualAddress << std::dec << std::endl;
                std::cout << std::hex << " Import Table:" << std::endl;
                auto importDesc = reinterpret_cast<PIMAGE_IMPORT_DESCRIPTOR>(
                        fileContent.data() + importTable->VirtualAddress - sectionHeader[i].VirtualAddress +
                        sectionHeader[i].PointerToRawData);

                while (importDesc->Name != 0) {
                    const char* dllName = reinterpret_cast<const char*>(fileContent.data() + importDesc->Name - sectionHeader[i].VirtualAddress + sectionHeader[i].PointerToRawData);
                    auto thunkData = reinterpret_cast<PIMAGE_THUNK_DATA32>(fileContent.data() + importDesc->OriginalFirstThunk - sectionHeader[i].VirtualAddress + sectionHeader[i].PointerToRawData);

                    while (thunkData->u1.AddressOfData != 0) {
                        char* name_func = nullptr;
                        if (!(thunkData->u1.Ordinal & IMAGE_ORDINAL_FLAG32)) {
                            auto importByName = reinterpret_cast<PIMAGE_IMPORT_BY_NAME>(fileContent.data() + thunkData->u1.AddressOfData - sectionHeader[i].VirtualAddress + sectionHeader[i].PointerToRawData);
                            name_func = importByName->Name;
                        }
                        std::cout << "\tAddress: 0x" << std::hex << thunkData->u1.Function + optHeader32->ImageBase << std::dec << std::setw(20)
                                  << "\tDLL: " << dllName << std::setw(20) << " \tFunction: " << (name_func ? name_func : "Ordinal") << std::setw(20) << std::endl;
                        ++thunkData;
                    }
                    ++importDesc;
                }
                break;
            }
        }
    } else {
        std::cout << "Import Table not found, maybe not a PE file." << std::endl;
    }
    std::cout << "\n";
}