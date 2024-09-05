#ifndef PE_X86_PARSER_EXP_HPP
#define PE_X86_PARSER_EXP_HPP
#include <fstream>
#include <cstdint>
#include <vector>
#include <stdint.h>
#include <Windows.h>


bool finder(const IMAGE_SECTION_HEADER&, const IMAGE_DATA_DIRECTORY&);
int parse_header(std::ifstream&);
void print_opt64(IMAGE_OPTIONAL_HEADER64);
void print_opt32(IMAGE_OPTIONAL_HEADER32);
std::vector<IMAGE_SECTION_HEADER> getSection(std::ifstream&, uint16_t, uint32_t);
void get_export(const IMAGE_DATA_DIRECTORY&, const std::vector<IMAGE_SECTION_HEADER>&, uint16_t, std::ifstream&);
void get_import(const IMAGE_DATA_DIRECTORY&, const std::vector<IMAGE_SECTION_HEADER>&, uint16_t, std::ifstream&);
void get_symbole(const char* path);
#endif
