#include <iostream>
#include <windows.h>
#include <dbghelp.h>
#include "peh.hpp"

void symbole(HANDLE hFile) {
    if (!SymInitialize(GetCurrentProcess(), nullptr, TRUE)) {
        std::cerr << "SymInit failed. Error: " << GetLastError() << std::endl;
        return;
    }

    HANDLE hProc = GetCurrentProcess();
    DWORD64 baseAddr = SymLoadModuleEx(hProc, hFile, nullptr, nullptr, 0, 0, nullptr, 0);

    if (baseAddr == 0) {
        std::cerr << "File load failed. Error: " << GetLastError() << std::endl;
        SymCleanup(hProc);
        return;
    }

    IMAGEHLP_MODULE64 modInfo;
    modInfo.SizeOfStruct = sizeof(IMAGEHLP_MODULE64);

    if (SymGetModuleInfo64(hProc, baseAddr, &modInfo)) {
        std::cout << "Module: " << modInfo.ModuleName << std::endl;
        std::cout << "Base: 0x" << std::hex << modInfo.BaseOfImage << std::dec << std::endl;
        std::cout << "Size: " << modInfo.ImageSize << " bytes" << std::endl;
        std::cout << "Loaded: " << modInfo.LoadedImageName << std::endl;
        std::cout << "Type: " << modInfo.SymType << "\n" << std::endl;

        if (!SymEnumSymbols(hProc, baseAddr, nullptr, [](PSYMBOL_INFO pInfo, ULONG Size, PVOID Context) -> BOOL {
            std::cout << "Symbol Name: " << pInfo->Name << std::endl;
            std::cout << "Address: 0x" << std::hex << pInfo->Address << std::dec << std::endl;
            std::cout << "Size: " << pInfo->Size << " bytes" << std::endl;
            std::cout << std::endl;
            return TRUE;
        }, nullptr)) {
            std::cerr << "Enum symbols failed. Error: " << GetLastError() << std::endl;
        }

        std::cout << std::endl;
    } else {
        std::cerr << "Module info failed. Error: " << GetLastError() << std::endl;
    }

    SymUnloadModule64(hProc, baseAddr);
    SymCleanup(hProc);
}
