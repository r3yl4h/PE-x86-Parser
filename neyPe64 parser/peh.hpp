#ifndef PEH_HPP
#define PEH_HPP
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define MAGENTA "\033[35m"

#include <windows.h>

void idata(HANDLE);

void header(HANDLE);

void edata(const CHAR* path);

void psI(HANDLE hFile);

void symbole(HANDLE);

int main(int argc, char* argv[]);

#endif
