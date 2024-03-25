#include <iostream>
#include <iomanip>
#include <cmath>
#include <windows.h>
#include <winnt.h>
#include "peh.hpp"


void PrintHead(const PIMAGE_OPTIONAL_HEADER64 optionalHeader) {
    std::cout << "Optional Header:\n";
    std::cout << "  Magic: " << std::hex << optionalHeader->Magic << std::dec << "\n";
    std::cout << "  AddressOfEntryPoint: 0x" << std::hex << optionalHeader->AddressOfEntryPoint << std::dec << "\n";
    std::cout << "  SectionAlignment: 0x" << std::hex << optionalHeader->SectionAlignment << std::dec << "\n";
    std::cout << "  FileAlignment: 0x" << std::hex << optionalHeader->FileAlignment << std::dec << "\n";
    std::cout << "  SizeOfImage: " << optionalHeader->SizeOfImage << " bytes (" << std::fixed << std::setprecision(3)
              << static_cast<double>(optionalHeader->SizeOfImage) / (1024 * 1024) << " MB)\n";
    std::cout << "  SizeOfHeaders: " << optionalHeader->SizeOfHeaders << " bytes (" << std::fixed << std::setprecision(3)
              << static_cast<double>(optionalHeader->SizeOfHeaders) / (1024 * 1024) << " MB)\n";
    std::cout << "  SizeOfCode: " << optionalHeader->SizeOfCode << " bytes (" << std::fixed << std::setprecision(3)
              << static_cast<double>(optionalHeader->SizeOfCode) / (1024 * 1024) << " MB)\n";
    std::cout << "  SizeOfInitializedData: " << optionalHeader->SizeOfInitializedData << " bytes (" << std::fixed << std::setprecision(3)
              << static_cast<double>(optionalHeader->SizeOfInitializedData) / (1024 * 1024) << " MB)\n";
    std::cout << "  SizeOfUninitializedData: " << optionalHeader->SizeOfUninitializedData << " bytes (" << std::fixed << std::setprecision(3)
              << static_cast<double>(optionalHeader->SizeOfUninitializedData) / (1024 * 1024) << " MB)\n";
    std::cout << "  BaseOfCode: 0x" << std::hex << optionalHeader->BaseOfCode << std::dec << "\n";
    std::cout << "  DllCharacteristics: 0x" << std::hex << optionalHeader->DllCharacteristics << std::dec << "\n";
    std::cout << "  SizeOfStackReserve: " << optionalHeader->SizeOfStackReserve << " bytes (" << std::fixed << std::setprecision(3)
              << static_cast<double>(optionalHeader->SizeOfStackReserve) / (1024 * 1024) << " MB)\n";
    std::cout << "  SizeOfStackCommit: " << optionalHeader->SizeOfStackCommit << " bytes (" << std::fixed << std::setprecision(3)
              << static_cast<double>(optionalHeader->SizeOfStackCommit) / (1024 * 1024) << " MB)\n";
    std::cout << "  SizeOfHeapReserve: " << optionalHeader->SizeOfHeapReserve << " bytes (" << std::fixed << std::setprecision(3)
              << static_cast<double>(optionalHeader->SizeOfHeapReserve) / (1024 * 1024) << " MB)\n";
    std::cout << "  SizeOfHeapCommit: " << optionalHeader->SizeOfHeapCommit << " bytes (" << std::fixed << std::setprecision(3)
              << static_cast<double>(optionalHeader->SizeOfHeapCommit) / (1024 * 1024) << " MB)\n";
    std::cout << "  Major Linker Version: " << std::hex << static_cast<int>(optionalHeader->MajorLinkerVersion) << std::dec << "\n";
    std::cout << "  Major Image Version: " << optionalHeader->MajorImageVersion << "\n";
    std::cout << "  Major subsystem version: " << optionalHeader->MajorSubsystemVersion << "\n";
    std::cout << "  Minor Linker Version: " << std::hex << static_cast<int>(optionalHeader->MinorLinkerVersion) << std::dec << "\n";
    std::cout << "  Minor Image Version: " << optionalHeader ->MinorImageVersion << "\n";
    std::cout << "  Minor Operating System Version: " << optionalHeader->MinorOperatingSystemVersion << "\n";

    if (optionalHeader->Magic == IMAGE_NT_OPTIONAL_HDR32_MAGIC) {
        std::cout << "  Architecture: 32-bit\n" << std::endl;
    } else if (optionalHeader->Magic == IMAGE_NT_OPTIONAL_HDR64_MAGIC) {
        std::cout << "  Architecture: 64-bit\n" << std::endl;
    } else {
        std::cout << "  Architecture: Unknown\n" << std::endl;
    }
}





void header(HANDLE hFile) {
    SetFilePointer(hFile, 0, nullptr, FILE_BEGIN);
    DWORD fileSize = GetFileSize(hFile, nullptr);
    BYTE* fileContent = new BYTE[fileSize];

    if (!ReadFile(hFile, fileContent, fileSize, nullptr, nullptr)) {
        std::cerr << "Error reading file." << std::endl;
        delete[] fileContent;
        return;
    }


    auto dosHdr = reinterpret_cast<PIMAGE_DOS_HEADER>(fileContent);

    if (dosHdr->e_magic == IMAGE_DOS_SIGNATURE && dosHdr->e_lfanew != 0) {
        auto ntHdrs = reinterpret_cast<PIMAGE_NT_HEADERS>(fileContent + dosHdr->e_lfanew);
        PIMAGE_OPTIONAL_HEADER64 optHead64 = &ntHdrs->OptionalHeader;
        DWORD entryptr = ntHdrs->OptionalHeader.AddressOfEntryPoint;

        std::cout << "\nHeader:\n";
        std::cout << "Address of WinMain: 0x" << std::hex << entryptr + optHead64->ImageBase << std::dec << "\n";
        std::cout << "  Machine: 0x" << std::hex << ntHdrs->FileHeader.Machine << std::dec << "\n";
        std::cout << "  TimeDateStamp: 0x" << std::hex << ntHdrs->FileHeader.TimeDateStamp << std::dec << " (UTC)\n";
        std::cout << "  DOS Signature: 0x" << std::hex << dosHdr->e_magic << std::dec << "\n";
        std::cout << "  PE Signature: 0x" << std::hex << ntHdrs->Signature << std::dec << "\n";
        std::cout << "  Base image address: 0x" << std::hex << ntHdrs->OptionalHeader.ImageBase << std::dec << "\n";
        std::cout << "  Number of sections: " << ntHdrs->FileHeader.NumberOfSections << "\n";
        std::cout << "  File header size: " << ntHdrs->FileHeader.SizeOfOptionalHeader << " bytes\n";
        std::cout << "  Subsystem version: " << ntHdrs->OptionalHeader.MajorSubsystemVersion << "." << ntHdrs->OptionalHeader.MinorSubsystemVersion << "\n";
        std::cout << "  Characteristics of the DLL: " << ((ntHdrs->FileHeader.Characteristics & IMAGE_FILE_DLL) ? "DLL" : "NONE") << "\n";
        std::cout << "\n";
        PrintHead(optHead64);

        if (ntHdrs->Signature == IMAGE_NT_SIGNATURE) {
            for (int i = 0; i < ntHdrs->FileHeader.NumberOfSections; ++i) {
                PIMAGE_SECTION_HEADER section = IMAGE_FIRST_SECTION(ntHdrs) + i;
                std::cout << "\nSection: " << section->Name << std::endl;
                std::cout << "   Virtual adress : 0x" << std::dec << section->VirtualAddress << std::dec << std::endl;
                std::cout << "   Virtual Size: " << section->Misc.VirtualSize << " bytes (" << std::fixed << std::setprecision(3)
                          << static_cast<double>(section->Misc.VirtualSize) / (1024 * 1024) << " MB)\n";
                std::cout << "   RVA: 0x" << std::hex << section->VirtualAddress << std::dec << std::endl;
                std::cout << "   Offset of raw data: 0x" << std::hex << section->PointerToRawData << std::dec << " \n";
                std::cout << "   Raw Size: " << section->SizeOfRawData << " bytes (" << std::fixed << std::setprecision(3)
                          << static_cast<double>(section->SizeOfRawData) / (1024 * 1024) << " MB)\n";
                std::cout << "   Section Characteristics: ";
                if (section->Characteristics & IMAGE_SCN_MEM_EXECUTE)
                    std::cout << "Executable ";
                if (section->Characteristics & IMAGE_SCN_MEM_READ)
                    std::cout << "Readable ";
                if (section->Characteristics & IMAGE_SCN_MEM_WRITE)
                    std::cout << "Writable ";
                std::cout << std::endl;
                std::cout << "   Section Type: ";
                if (section->Characteristics & IMAGE_SCN_CNT_CODE)
                    std::cout << "Code ";
                if (section->Characteristics & IMAGE_SCN_CNT_INITIALIZED_DATA)
                    std::cout << "Initialized Data ";
                if (section->Characteristics & IMAGE_SCN_CNT_UNINITIALIZED_DATA)
                    std::cout << "Uninitialized Data ";
                std::cout << "\n   Section Flags: 0x" << std::hex << section->Characteristics << std::dec << "\n";
                std::cout << "   Base Relocation Table RVA: 0x" << std::hex << ntHdrs->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress << std::dec << std::endl;
            }
        }
        std::cout << "\n";
    } else {
        std::cout << "Invalid PE file." << std::endl;
    }
    delete[] fileContent;
}











