#ifndef PEH_HPP
#define PEH_HPP
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define MAGENTA "\033[35m"

void idata(const CHAR*, bool);

void header(HANDLE);

void edata(const CHAR*, bool);

void psI(HANDLE);

void symbole(HANDLE);

int main(int argc, char* argv[]);

#endif
