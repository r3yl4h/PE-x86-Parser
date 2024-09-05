#include <iostream>
#include <algorithm>
#include "exp.hpp"

void get_export(const IMAGE_DATA_DIRECTORY& edt_entry, const std::vector<IMAGE_SECTION_HEADER>& sectionv, uint16_t machine, std::ifstream& file) {
	if (edt_entry.VirtualAddress && edt_entry.Size) {
		auto rsec = std::find_if(sectionv.begin(), sectionv.end(), [&](const IMAGE_SECTION_HEADER& sec) {
            return finder(sec, edt_entry);
            });

		IMAGE_EXPORT_DIRECTORY export_dir = { 0 };
		int pos_edt = edt_entry.VirtualAddress - rsec->VirtualAddress + rsec->PointerToRawData;
		file.seekg(pos_edt, std::ios::beg);
		file.read(reinterpret_cast<char*>(&export_dir), sizeof(IMAGE_EXPORT_DIRECTORY));
		std::cout << "\n-------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "Export Table Address: 0x" << std::hex << rsec->VirtualAddress << std::dec << std::endl;
		int pos_name = export_dir.Name - rsec->VirtualAddress + rsec->PointerToRawData;
		file.seekg(pos_name, std::ios::beg);
		char* name = new char[260];
		file.read(name, 260);

		std::cout << "name: " << name << std::endl;
		std::cout << "Number of Functions: " << export_dir.NumberOfFunctions << std::endl;
		std::cout << "Number of Names: " << export_dir.NumberOfNames << std::endl;
		
		delete[] name;

		uint32_t* addr_func = new uint32_t[export_dir.NumberOfFunctions];
		int pos_funcptr = export_dir.AddressOfFunctions - rsec->VirtualAddress + rsec->PointerToRawData;
		file.seekg(pos_funcptr, std::ios::beg);
		file.read(reinterpret_cast<char*>(addr_func), 4 * export_dir.NumberOfFunctions);

		uint32_t* addr_name = new uint32_t[export_dir.NumberOfNames];
		pos_name = export_dir.AddressOfNames - rsec->VirtualAddress + rsec->PointerToRawData;
		file.seekg(pos_name, std::ios::beg);
		file.read(reinterpret_cast<char*>(addr_name), 4 * export_dir.NumberOfNames);
		std::cout << "Export Func:\n";
		for (int i = 0; i < export_dir.NumberOfFunctions; i++) {
			uint32_t addr_rva = addr_func[i];
			pos_name = addr_name[i] - rsec->VirtualAddress + rsec->PointerToRawData;
			file.seekg(pos_name, std::ios::beg);
			char* name = new char[260];
			file.read(name, 260);
			std::cout << std::hex << "\tAddress : 0x" << addr_rva << " - Name : " << name << std::dec << std::endl;
			delete[] name;
		}
	}
}