#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdint.h>
#include <vector>
#include <algorithm>
#include <string>
#include "exp.hpp"



struct IaByName {
    uint16_t Hint;
    char Name[260];
};



void get_import(const IMAGE_DATA_DIRECTORY& idt_entry, const std::vector<IMAGE_SECTION_HEADER>& sectionv, uint16_t machine, std::ifstream& file) {
    if (idt_entry.Size != 0 && idt_entry.VirtualAddress != 0) {
        auto rsec = std::find_if(sectionv.begin(), sectionv.end(), [&](const IMAGE_SECTION_HEADER& sec) {
            return finder(sec, idt_entry);
            });

        size_t size_entry = (machine == 0x014C) ? 4 : (machine == 0x8664 || machine == 0x0200) ? 8 : 0;
        uint64_t real_offs = idt_entry.VirtualAddress - rsec->VirtualAddress + rsec->PointerToRawData;
        file.seekg(real_offs, std::ios::beg);

        size_t count = idt_entry.Size / sizeof(IMAGE_IMPORT_DESCRIPTOR);

        for (size_t i = 0; i < count; i++) {
            IMAGE_IMPORT_DESCRIPTOR idt;
            file.read(reinterpret_cast<char*>(&idt), sizeof(IMAGE_IMPORT_DESCRIPTOR));
            auto last_pos = file.tellg();

            if (idt.Name == 0) {
                break;
            }

            real_offs = idt.Name - rsec->VirtualAddress + rsec->PointerToRawData;
            file.seekg(real_offs, std::ios::beg);

            char byte_name[256];
            file.read(byte_name, 256);
            std::string dll_name(byte_name);

            std::cout << "\n\ndll name : " << dll_name << std::endl;

            uint64_t thunk = idt.OriginalFirstThunk - rsec->VirtualAddress + rsec->PointerToRawData;
            uint64_t iat = idt.FirstThunk - rsec->VirtualAddress + rsec->PointerToRawData;

            while (true) {
                file.seekg(thunk, std::ios::beg);

                if (size_entry == 4) {
                    IMAGE_THUNK_DATA32 thunk_data;
                    file.read(reinterpret_cast<char*>(&thunk_data), sizeof(IMAGE_THUNK_DATA32));

                    if (thunk_data.u1.AddressOfData == 0) {
                        break;
                    }

                    uint64_t func_offs = thunk_data.u1.AddressOfData - rsec->VirtualAddress + rsec->PointerToRawData;
                    file.seekg(func_offs, std::ios::beg);

                    IaByName iabyname;
                    file.read(reinterpret_cast<char*>(&iabyname), 262);
                    std::string func_name(iabyname.Name);

                    std::cout << "\tiat : 0x" << std::hex << iat - rsec->PointerToRawData + rsec->VirtualAddress << " - func name : " << func_name << std::endl;

                    thunk += sizeof(IMAGE_THUNK_DATA32);
                    iat += size_entry;

                }
                else if (size_entry == 8) {
                    IMAGE_THUNK_DATA64 thunk_data;
                    file.read(reinterpret_cast<char*>(&thunk_data), sizeof(IMAGE_THUNK_DATA64));

                    if (thunk_data.u1.AddressOfData == 0) {
                        break;
                    }

                    uint64_t func_offs = thunk_data.u1.AddressOfData - rsec->VirtualAddress + rsec->PointerToRawData;
                    file.seekg(func_offs, std::ios::beg);

                    IaByName iabyname;
                    file.read(reinterpret_cast<char*>(&iabyname), 262);
                    std::string func_name(iabyname.Name);
                    std::cout << "\tiat : 0x" << std::hex << iat - rsec->PointerToRawData + rsec->VirtualAddress << " - func name : " << func_name << std::endl;

                    thunk += sizeof(IMAGE_THUNK_DATA64);
                    iat += size_entry;
                }
            }

            file.seekg(last_pos, std::ios::beg);
        }
    }
    else {
        std::cerr << "idt not found" << std::endl;
    }
}
