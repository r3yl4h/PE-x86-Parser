#ifndef PEH_HPP
#define PEH_HPP
#include <windows.h>

void idata(HANDLE);

void header(HANDLE);

void edata(const CHAR* path);

void psI(HANDLE hFile);

void symbole(HANDLE);

int main(int argc, char* argv[]);

#endif
