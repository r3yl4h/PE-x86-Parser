#include <iostream>
#include <windows.h>
#include <wintrust.h>
#include "peh.hpp"

void psI(HANDLE hFile) {

    DWORD fileSize = GetFileSize(hFile, nullptr);
    BYTE* fileContent = new BYTE[fileSize];
    DWORD bytesRead;

    if (!ReadFile(hFile, fileContent, fileSize, &bytesRead, nullptr)) {
        std::cerr << "Error reading the file." << std::endl;
        delete[] fileContent;
        return;
    }

    auto dosHdr = reinterpret_cast<PIMAGE_DOS_HEADER>(fileContent);
    auto ntHdrs = reinterpret_cast<PIMAGE_NT_HEADERS>(fileContent + dosHdr->e_lfanew);

    if (dosHdr->e_magic != IMAGE_DOS_SIGNATURE || ntHdrs->Signature != IMAGE_NT_SIGNATURE) {
        delete[] fileContent;
        return;
    }

    PIMAGE_OPTIONAL_HEADER optHdr = &ntHdrs->OptionalHeader;
    PIMAGE_DATA_DIRECTORY secDir = &optHdr->DataDirectory[IMAGE_DIRECTORY_ENTRY_SECURITY];

    if (secDir->VirtualAddress != 0 && secDir->Size != 0) {
        auto* certData = reinterpret_cast<WIN_CERTIFICATE*>(fileContent + secDir->VirtualAddress);
        std::cout << "\nSecurity Information:\n";
        std::cout << "  Certificate Type: " << certData->wCertificateType << "\n";
        std::cout << "  Certificate Length: " << certData->dwLength << "\n";
        std::cout << "  Certificate Revision: " << certData->wRevision << std::endl;
    }
    delete[] fileContent;
}
