#ifndef PE_X86_PARSER_EXP_HPP
#define PE_X86_PARSER_EXP_HPP
#include <fstream>
#include <cstdint>
#include <vector>

int parse_header(std::ifstream&);
void pars_optional_header64(IMAGE_OPTIONAL_HEADER64);
void pars_optional_header32(IMAGE_OPTIONAL_HEADER32);
int getSection(std::ifstream&, uint16_t, uint32_t);
void getImport64(std::ifstream&);
void getExport64(std::ifstream&);
void getImport32(std::ifstream&);
void getExport32(std::ifstream&);
void get_symbole(const char* path);
#endif
