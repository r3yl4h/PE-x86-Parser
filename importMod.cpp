#include <iostream>
#include <windows.h>
#include <iomanip>
#include "peh.hpp"

void idata(const CHAR* path) {
    bool addrid = true;
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
    PIMAGE_DATA_DIRECTORY importTable = &optHeader64->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];

    int functionCount = 0;

    if (importTable->VirtualAddress != 0 && importTable->Size != 0) {
        PIMAGE_SECTION_HEADER sectionHeader = IMAGE_FIRST_SECTION(ntHeaders);

        for (int i = 0; i < ntHeaders->FileHeader.NumberOfSections; ++i) {
            if (importTable->VirtualAddress >= sectionHeader[i].VirtualAddress && importTable->VirtualAddress < sectionHeader[i].VirtualAddress + sectionHeader[i].SizeOfRawData) {

                auto importDescriptor = reinterpret_cast<PIMAGE_IMPORT_DESCRIPTOR>(
                        fileContent + importTable->VirtualAddress - sectionHeader[i].VirtualAddress +
                        sectionHeader[i].PointerToRawData);

                while (importDescriptor->Name != 0) {
                    const char* dllName = reinterpret_cast<const char*>(fileContent + importDescriptor->Name - sectionHeader[i].VirtualAddress + sectionHeader[i].PointerToRawData);
                    auto thunkData = reinterpret_cast<PIMAGE_THUNK_DATA64>(fileContent + importDescriptor->OriginalFirstThunk - sectionHeader[i].VirtualAddress + sectionHeader[i].PointerToRawData);


                    while (thunkData->u1.AddressOfData != 0) {
                        const char* funcName = nullptr;
                        if (!(thunkData->u1.Ordinal & IMAGE_ORDINAL_FLAG64)) {
                            auto importByName = reinterpret_cast<PIMAGE_IMPORT_BY_NAME>(fileContent + thunkData->u1.AddressOfData - sectionHeader[i].VirtualAddress + sectionHeader[i].PointerToRawData);
                            funcName = importByName->Name;
                        }
                        auto funcAddr = thunkData->u1.Function + optHeader64->ImageBase;

                        if(addrid){
                            auto baseIdata = funcAddr & 0xFFFFF000;
                            std::cout << "\nImport Table Address: 0x" << std::hex << std::setw(8) << std::setfill('0') << baseIdata << std::dec << std::endl;
                            std::cout << std::dec << std::setw(0) << std::setfill(' ');
                            std::cout << "Import Table:\n";
                            addrid = false;
                        }

                        std::cout << "\tAddress: 0x" << std::hex << funcAddr << std::dec << std::setw(20)
                                  << "\tDLL: " << dllName << std::setw(20) << " \tFunction: " << (funcName ? funcName : "Ordinal") << std::setw(20) << std::endl;

                        ++thunkData;
                        ++functionCount;
                    }
                    ++importDescriptor;
                }
                std::cout << "\tNumber of Functions: " << functionCount << std::endl;
                break;
            }
        }
    } else {
        std::cout << "Import Table not found, maybe not a PE file." << std::endl;
    }

    std::cout << "\n";

    delete[] fileContent;
}