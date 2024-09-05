#include <iostream>
#include <fstream>
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
    std::cout << "0x00: (uint32_t) Pe signature: 0x" << file_header.Signature << std::endl;
    std::cout << "0x04: (uint16_t) Machine: 0x" << file_header.FileHeader.Machine << std::endl;
    std::cout << "0x06: (uint16_t) Number of Sections: " << std::dec << file_header.FileHeader.NumberOfSections << std::hex << std::endl;
    std::cout << "0x08: (uint32_t) TimeDateStamp: " << file_header.FileHeader.TimeDateStamp << std::endl;
    std::cout << "00xC: (uint32_t) PointerToSymbolTable: 0x" << file_header.FileHeader.PointerToSymbolTable << std::endl;
    std::cout << "0x10: (uint32_t) NumberOfSymbols: " << file_header.FileHeader.NumberOfSymbols << std::endl;
    std::cout << "0x14: (uint16_t) SizeOfOptionalHeader: " << file_header.FileHeader.SizeOfOptionalHeader << std::endl;
    std::cout << "0x16: (uint16_t) Characteristics: " << file_header.FileHeader.Characteristics << std::endl;
    IMAGE_DATA_DIRECTORY idt;
    IMAGE_DATA_DIRECTORY edt;
    std::vector<IMAGE_SECTION_HEADER> sectionv;
    if (file_header.FileHeader.Machine == 0x8664) {
        print_opt64(file_header.OptionalHeader);
        sectionv = getSection(file, file_header.FileHeader.NumberOfSections, file_header.FileHeader.PointerToSymbolTable + (file_header.FileHeader.NumberOfSymbols * 18));
        idt = file_header.OptionalHeader.DataDirectory[1];
        edt = file_header.OptionalHeader.DataDirectory[0];
    }else if (file_header.FileHeader.Machine == 0x14c) {
        IMAGE_NT_HEADERS32 file_header32;
        file.seekg(last_pos, std::ios::beg);
        file.read(reinterpret_cast<char*>(&file_header32), sizeof(IMAGE_NT_HEADERS32));
        print_opt32(file_header32.OptionalHeader);
        sectionv = getSection(file, file_header.FileHeader.NumberOfSections, file_header.FileHeader.PointerToSymbolTable + (file_header.FileHeader.NumberOfSymbols * 18));
        idt = file_header32.OptionalHeader.DataDirectory[1];
        edt = file_header32.OptionalHeader.DataDirectory[0];
    }
    get_import(idt, sectionv, file_header.FileHeader.Machine, file);
    get_export(edt, sectionv, file_header.FileHeader.Machine, file);
    return 0;
}