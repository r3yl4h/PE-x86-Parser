#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>
#include "peh.hpp"

using namespace std;
bool showMsg = true;


HANDLE open(const char* path, int argc, char* argv[]) {
    HANDLE hFile = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (hFile == INVALID_HANDLE_VALUE){
        CloseHandle(hFile);
        delete[] path;
        cout << "the file does not exist or we were unable to open it" << endl;
        if (argc == 1) {
            main(argc, argv);
        }
    }

    return hFile;
}



int main(int argc, char* argv[]) {
    string paths;
    bool symbol = false;
    bool demangle = false;

    if (argc > 1) {
        paths = argv[1];
    }


    else {
        if (showMsg) {
            cout << MAGENTA << "\n __   __                                                     _ \n"
                               " \\ \\ / /  _   _   _ __     __ _   _ __ ___     __ _   _ __  (_)\n"
                               "  \\ V /  | | | | | '_ \\   / _` | | '_ ` _ \\   / _` | | '__| | |\n"
                               "   | |   | |_| | | | | | | (_| | | | | | | | | (_| | | |    | |\n"
                               "   |_|    \\__,_| |_| |_|  \\__,_| |_| |_| |_|  \\__,_| |_|    |_|" << "\n\n\n";

            cout << "hi, this is a small pe file analyzer. Don't hesitate to join the discord server:\n"
                    "https://discord.gg/420sec, my discord username is \"lunapeiy\"" << RESET << endl;
            showMsg = false;
        }

        cout << GREEN << "\nEnter the path of your PE file: " ;
        getline(cin, paths);
        cout << RESET;
        if (paths == "exit"|| paths == "q"|| paths == "quit" || paths.empty()) {
            cout << "goodbye" << endl;
            return 0;
        }
        paths.erase(remove(paths.begin(), paths.end(), '\"'), paths.end());

        string test;
        cout << "print the symbol [y/n]?: ";
        getline(cin, test);
        if (test == "y"|| test== "true"|| test == "yes" || test=="oui"){
            symbol = true;
        }

        string demangled;
        cout << "demangle function [y/n]?: ";
        getline(cin, demangled);
        if (demangled == "y" || demangled=="true"||demangled == "yes") {
            demangle = true;
        }

    }
    const char *path = paths.c_str();
    HANDLE hFile = open(path, argc, argv);

    header(hFile);
    idata(path, demangle);
    edata(path, demangle);

    if (symbol)
     symbole(hFile);
    psI(hFile);

    CloseHandle(hFile);
    cout << "\n" << endl;

    if (argc == 1) {
        main(argc, argv);
    }

    return 0;
}
