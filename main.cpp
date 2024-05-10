#include <iostream>
#include <fstream>
#include <windows.h>
#include <winnt.h>
#include "exp.hpp"

int main(int argc, char* argv[]) {
    std::string path;
    if (argc > 1) {
        path = argv[1];
    } else {
        std::cout << "Enter the path of your pe file: ";
        std::getline(std::cin, path);
        std::cout << std::endl;
        if (path == "exit" || path == "q" || path == "quit" || path.empty()) {
            return 0;
        }
    }
    std::ifstream file(path, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }
    IMAGE_DOS_HEADER dosHeader;
    file.read(reinterpret_cast<char*>(&dosHeader), sizeof(IMAGE_DOS_HEADER));

    if (dosHeader.e_magic != IMAGE_DOS_SIGNATURE) {
        std::cerr << "Not a valid DOS executable." << std::endl;
        return 1;
    }

    std::cout << "DOS HEADER: " << std::endl;
    std::cout << "0x00: (uint16_t) Magic Number MZ: 0x" << std::hex << dosHeader.e_magic << std::endl;
    std::cout << "0x02: (uint16_t) Bytes on last page of file: " << dosHeader.e_cblp << std::endl;
    std::cout << "0x04: (uint16_t) Pages in file: " << dosHeader.e_cp << std::endl;
    std::cout << "0x06: (uint16_t) Relocations: " << dosHeader.e_crlc << std::endl;
    std::cout << "0x08: (uint16_t) Size of header in paragraphs: " << dosHeader.e_cparhdr << std::endl;
    std::cout << "0x0a: (uint16_t) Minimum extra paragraphs needed: " << dosHeader.e_minalloc << std::endl;
    std::cout << "0x0c: (uint16_t) Maximum extra paragraphs needed: " << dosHeader.e_maxalloc << std::endl;
    std::cout << "0x0e: (uint16_t) Initial ss value: " << dosHeader.e_ss << std::endl;
    std::cout << "0x10: (uint16_t) e_sp: Initial SP value: " << dosHeader.e_sp << std::endl;
    std::cout << "0x12: (uint16_t) Checksum: " << dosHeader.e_csum << std::endl;
    std::cout << "0x14: (uint16_t) Initial ip value: " << dosHeader.e_ip << std::endl;
    std::cout << "0x16: (uint16_t) Initial cs value: " << dosHeader.e_cs << std::endl;
    std::cout << "0x18: (uint16_t) File address of relocation table: " << dosHeader.e_lfarlc << std::endl;
    std::cout << "0x1a: (uint16_t) e_ovno: Overlay number: " << dosHeader.e_ovno << std::endl;
    std::cout << "0x1c: (uint16_t[4]) Reserved words: ";
    for (unsigned short e_re : dosHeader.e_res) {
        std::cout << e_re << " ";
    }
    std::cout << std::endl;
    std::cout << "0x24: (uint16_t) OEM identifier: " << dosHeader.e_oemid << std::endl;
    std::cout << "0x26: (uint16_t) e_oeminfo: OEM information: " << dosHeader.e_oeminfo << std::endl;
    std::cout << "0x28: (uint16[10]) Reserved words2: ";
    for (unsigned short i : dosHeader.e_res2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "0x3c: (uint32_t) Pe header address: 0x" << dosHeader.e_lfanew << std::endl;
    file.seekg(dosHeader.e_lfanew);
    parse_header(file);
    std::string inp;
    std::cout << "\nget the symbol?: ";
    std::getline(std::cin, inp);
    if (inp == "yes"|| inp == "y")
        get_symbole(path.c_str());

    if (argc == 0) {
        main(argc, argv);
    }
    return 0;
}
