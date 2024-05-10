#include <iostream>
#include <fstream>
#include <windows.h>
#include "exp.hpp"

int parse_header(std::ifstream& file) {
    int last_pos = file.tellg();
    IMAGE_NT_HEADERS file_header;
    file.read(reinterpret_cast<char*>(&file_header), sizeof(IMAGE_NT_HEADERS));
    if (!file) {
        std::cerr << "Error reading file header." << std::endl;
        return 1;
    }
    std::cout << "\nFILE HEADER: " << std::endl;
    std::cout << "0x0: (uint32_t) Pe signature: 0x" << file_header.Signature << std::endl;
    std::cout << "0x4: (uint16_t) Machine: 0x" << file_header.FileHeader.Machine << std::endl;
    std::cout << "0x6: (uint16_t) Number of Sections: " << std::dec << file_header.FileHeader.NumberOfSections << std::hex << std::endl;
    std::cout << "0x8: (uint32_t) TimeDateStamp: " << file_header.FileHeader.TimeDateStamp << std::endl;
    std::cout << "0xC: (uint32_t) PointerToSymbolTable: 0x" << file_header.FileHeader.PointerToSymbolTable << std::endl;
    std::cout << "0x10: (uint32_t) NumberOfSymbols: " << file_header.FileHeader.NumberOfSymbols << std::endl;
    std::cout << "0x14: (uint16_t) SizeOfOptionalHeader: " << file_header.FileHeader.SizeOfOptionalHeader << std::endl;
    std::cout << "0x16: (uint16_t) Characteristics: " << file_header.FileHeader.Characteristics << std::endl;
    if (file_header.FileHeader.Machine == 0x8664) {
        pars_optional_header64(file_header.OptionalHeader);
        getSection(file, file_header.FileHeader.NumberOfSections, file_header.FileHeader.PointerToSymbolTable + (file_header.FileHeader.NumberOfSymbols * 18));
        getImport64(file);
    }else if (file_header.FileHeader.Machine == 0x14c) {
        IMAGE_NT_HEADERS32 file_header32;
        file.seekg(last_pos, std::ios::beg);
        file.read(reinterpret_cast<char*>(&file_header32), sizeof(IMAGE_NT_HEADERS32));
        pars_optional_header32(file_header32.OptionalHeader);
        getSection(file, file_header.FileHeader.NumberOfSections, file_header.FileHeader.PointerToSymbolTable + (file_header.FileHeader.NumberOfSymbols * 18));
        getImport32(file);
    }
    return 0;
}