PE-x86-parser
========


This is a C++ project utilizing WinAPI that parses PE32 and PE64 files. While it may not be the most optimized version, I found it to be an engaging endeavor. You can operate the program by supplying arguments or running it without any, prompting you to input the file path for analysis.

## dependancies
you just need to have winapi, cmake and DIA SDK
 ### Cmake:
  * Unix:  `sudo apt-get install cmake`
  * RedHat/Fedora:  `sudo yum install cmake`
  * OSX:  `brew install cmake`
  * Windows : https://cmake.org/download/
 ### Dia2:
 * https://learn.microsoft.com/en-us/visualstudio/debugger/debug-interface-access/getting-started-debug-interface-access-sdk?view=vs-2022
 
and for dia you will just need to include the dia sdk include path to the cmakelist file which is generally located at the path: `C:/Program Files/Microsoft Visual Studio/2022/Professional/DIA SDK/include`

## for cli option
```
Usage: Pe_x86_parser.exe <file(s)> <option(s)>
Option:
  -s  --symbols  For get the symbols
```
## dos header
```
C:\code\cpp\Pe_x86_parser\cmake-build-debug>.\Pe_x86_parser "C:\code\cpp\libpe64\cmake-build-debug\libpe64.dll" -s
DOS HEADER:
0x00: (uint16_t) Magic Number MZ: 0x5a4d
0x02: (uint16_t) Bytes on last page of file: 90
0x04: (uint16_t) Pages in file: 3
0x06: (uint16_t) Relocations: 0
0x08: (uint16_t) Size of header in paragraphs: 4
0x0a: (uint16_t) Minimum extra paragraphs needed: 0
0x0c: (uint16_t) Maximum extra paragraphs needed: ffff
0x0e: (uint16_t) Initial ss value: 0
0x10: (uint16_t) e_sp: Initial SP value: b8
0x12: (uint16_t) Checksum: 0
0x14: (uint16_t) Initial ip value: 0
0x16: (uint16_t) Initial cs value: 0
0x18: (uint16_t) File address of relocation table: 40
0x1a: (uint16_t) e_ovno: Overlay number: 0
0x1c: (uint16_t[4]) Reserved words: 0 0 0 0
0x24: (uint16_t) OEM identifier: 0
0x26: (uint16_t) e_oeminfo: OEM information: 0
0x28: (uint16[10]) Reserved words2: 0 0 0 0 0 0 0 0 0 0
0x3c: (uint32_t) Pe header address: 0x80
```
## file header
```
FILE HEADER:
0x00: (uint32_t) Pe signature: 0x4550
0x04: (uint16_t) Machine: 0x8664
0x06: (uint16_t) Number of Sections: 20
0x08: (uint32_t) TimeDateStamp: 661dca1b
0x0C: (uint32_t) PointerToSymbolTable: 0x79800
0x10: (uint32_t) NumberOfSymbols: 1715
0x14: (uint16_t) SizeOfOptionalHeader: f0
0x16: (uint16_t) Characteristics: 2026
```
## optional header
```
OPTIONAL HEADER64:
0x18: (uint16_t) Magic: 0x20b
0x1A: (uinht8_t) MajorLinkerVersion: 2
0x1B: (uint16_t) MinorLinkerVersion: 28
0x1C: (uint32_t) SizeOfCode: 20600
0x20: (uint32_t) SizeOfInitializedData: 2a000
0x24: (uint32_t) SizeOfUninitializedData: c00
0x28: (uint32_t) AddressOfEntryPoint: 1330
0x2C: (uint32_t) BaseOfCode: 1000
0x34: (uint64_t) ImageBase: 3a6580000
0x38: (uint32_t) SectionAlignment: 1000
0x3C: (uint32_t) FileAlignment: 200
0x40: (uint16_t) MajorOperatingSystemVersion: 4
0x42: (uint16_t) MinorOperatingSystemVersion: 0
0x44: (uint16_t) MajorImageVersion: 0
0x46: (uint16_t) MinorImageVersion: 0
0x48: (uint16_t) MajorSubsystemVersion: 5
0x4A: (uint16_t) MinorSubsystemVersion: 2
0x4C: (uint32_t) Reserved1
0x50: (uint32_t) SizeOfImage: 85000
0x54: (uint32_t) SizeOfHeaders: 600
0x58: (uint32_t) CheckSum: c827c
0x5C: (uint16_t) Subsystem: 3
0x5E: (uint16_t) DllCharacteristics: 160
0x60: (uint64_t) SizeOfStackReserve: 200000
0x68: (uint64_t) SizeOfStackCommit: 1000
0x70: (uint64_t) SizeOfHeapReserve: 100000
0x78: (uint64_t) SizeOfHeapCommit: 1000
0x80: (uint32_t) LoaderFlags: 0
0x84: (uint32_t) NumberOfRvaAndSizes: 10
0x88: (uint32_t) ExportDirectory VA: 2e000
0x8C: (uint32_t) ExportDirectory Size: 72
0x90: (uint32_t) ImportDirectory VA: 2f000
0x94: (uint32_t) ImportDirectory Size: e10
0x98: (uint32_t) ResourceDirectory VA: 0
0x9C: (uint32_t) ResourceDirectory Size: 0
0xA0: (uint32_t) ExceptionDirectory VA: 29000
0xA4: (uint32_t) ExceptionDirectory Size: 10d4
0xA8: (uint32_t) SecurityDirectory VA: 0
0xAC: (uint32_t) SecurityDirectory Size: 0
0xB0: (uint32_t) BaseRelocationTable VA: 32000
0xB4: (uint32_t) BaseRelocationTable Size: 914
0xB8: (uint32_t) DebugDirectory VA: 0
0xBC: (uint32_t) DebugDirectory Size: 0
0xC0: (uint32_t) ArchitectureSpecificData VA: 0
0xC4: (uint32_t) ArchitectureSpecificData Size: 0
0xC8: (uint32_t) RVAofGP VA: 0
0xCC: (uint32_t) RVAofGP Size: 0
0xD0: (uint32_t) TLSDirectory VA: 23d60
0xD4: (uint32_t) TLSDirectory Size: 28
0xD8: (uint32_t) LoadConfigurationDirectory VA: 0
0xDC: (uint32_t) LoadConfigurationDirectory Size: 0
0xE0: (uint32_t) BoundImportDirectoryinheaders VA: 0
0xE4: (uint32_t) BoundImportDirectoryinheaders Size: 0
0xE8: (uint32_t) ImportAddressTable VA: 2f310
0xEC: (uint32_t) ImportAddressTable Size: 298
0xF0: (uint32_t) DelayLoadImportDescriptors VA: 0
0xF4: (uint32_t) DelayLoadImportDescriptors Size: 0
0xF8: (uint32_t) COMRuntimedescriptor VA: 0
0xFC: (uint32_t) COMRuntimedescriptor Size: 0
```
## section table
```
----------------------------------------------------------------------
SECTION TABLE:

 Name: .text
    VSize: 0x205c0 - Va: 0x1000
    SizeOfRawData: 0x20600 - PtrToRawData: 0x600
    PtrToReloc: 0x0 - PtrToLinenum: 0x0
    NumberOfReloc: 0 - NumberOfLinenum: 0
    Characteristics: 60000060

-----------------------------------
 Name: .data
    VSize: 0xa0 - Va: 0x22000
    SizeOfRawData: 0x200 - PtrToRawData: 0x20c00
    PtrToReloc: 0x0 - PtrToLinenum: 0x0
    NumberOfReloc: 0 - NumberOfLinenum: 0
    Characteristics: c0000040

-----------------------------------
 Name: .rdata
    VSize: 0x518c - Va: 0x23000
    SizeOfRawData: 0x5200 - PtrToRawData: 0x20e00
    PtrToReloc: 0x0 - PtrToLinenum: 0x0
    NumberOfReloc: 0 - NumberOfLinenum: 0
    Characteristics: 40000040

-----------------------------------
 Name: .pdata
    VSize: 0x10d4 - Va: 0x29000
    SizeOfRawData: 0x1200 - PtrToRawData: 0x26000
    PtrToReloc: 0x0 - PtrToLinenum: 0x0
    NumberOfReloc: 0 - NumberOfLinenum: 0
    Characteristics: 40000040

-----------------------------------
 Name: .xdata
    VSize: 0x12ec - Va: 0x2b000
    SizeOfRawData: 0x1400 - PtrToRawData: 0x27200
    PtrToReloc: 0x0 - PtrToLinenum: 0x0
    NumberOfReloc: 0 - NumberOfLinenum: 0
    Characteristics: 40000040

-----------------------------------
 Name: .bss
    VSize: 0xb30 - Va: 0x2d000
    SizeOfRawData: 0x0 - PtrToRawData: 0x0
    PtrToReloc: 0x0 - PtrToLinenum: 0x0
    NumberOfReloc: 0 - NumberOfLinenum: 0
    Characteristics: c0000080

-----------------------------------
 Name: .edata
    VSize: 0x72 - Va: 0x2e000
    SizeOfRawData: 0x200 - PtrToRawData: 0x28600
    PtrToReloc: 0x0 - PtrToLinenum: 0x0
    NumberOfReloc: 0 - NumberOfLinenum: 0
    Characteristics: 40000040

-----------------------------------
 Name: .idata
    VSize: 0xe10 - Va: 0x2f000
    SizeOfRawData: 0x1000 - PtrToRawData: 0x28800
    PtrToReloc: 0x0 - PtrToLinenum: 0x0
    NumberOfReloc: 0 - NumberOfLinenum: 0
    Characteristics: c0000040

-----------------------------------
 Name: .CRT
    VSize: 0x58 - Va: 0x30000
    SizeOfRawData: 0x200 - PtrToRawData: 0x29800
    PtrToReloc: 0x0 - PtrToLinenum: 0x0
    NumberOfReloc: 0 - NumberOfLinenum: 0
    Characteristics: c0000040

-----------------------------------
 Name: .tls
    VSize: 0x10 - Va: 0x31000
    SizeOfRawData: 0x200 - PtrToRawData: 0x29a00
    PtrToReloc: 0x0 - PtrToLinenum: 0x0
    NumberOfReloc: 0 - NumberOfLinenum: 0
    Characteristics: c0000040

-----------------------------------
 Name: .reloc
    VSize: 0x914 - Va: 0x32000
    SizeOfRawData: 0xa00 - PtrToRawData: 0x29c00
    PtrToReloc: 0x0 - PtrToLinenum: 0x0
    NumberOfReloc: 0 - NumberOfLinenum: 0
    Characteristics: 42000040

-----------------------------------
 Name: .debug_aranges
    VSize: 0xa80 - Va: 0x33000
    SizeOfRawData: 0xc00 - PtrToRawData: 0x2a600
    PtrToReloc: 0x0 - PtrToLinenum: 0x0
    NumberOfReloc: 0 - NumberOfLinenum: 0
    Characteristics: 42000040

-----------------------------------
 Name: .debug_info
    VSize: 0x32b9d - Va: 0x34000
    SizeOfRawData: 0x32c00 - PtrToRawData: 0x2b200
    PtrToReloc: 0x0 - PtrToLinenum: 0x0
    NumberOfReloc: 0 - NumberOfLinenum: 0
    Characteristics: 42000040

-----------------------------------
 Name: .debug_abbrev
    VSize: 0x4ebe - Va: 0x67000
    SizeOfRawData: 0x5000 - PtrToRawData: 0x5de00
    PtrToReloc: 0x0 - PtrToLinenum: 0x0
    NumberOfReloc: 0 - NumberOfLinenum: 0
    Characteristics: 42000040

-----------------------------------
 Name: .debug_line
    VSize: 0x88f6 - Va: 0x6c000
    SizeOfRawData: 0x8a00 - PtrToRawData: 0x62e00
    PtrToReloc: 0x0 - PtrToLinenum: 0x0
    NumberOfReloc: 0 - NumberOfLinenum: 0
    Characteristics: 42000040

-----------------------------------
 Name: .debug_frame
    VSize: 0x25d8 - Va: 0x75000
    SizeOfRawData: 0x2600 - PtrToRawData: 0x6b800
    PtrToReloc: 0x0 - PtrToLinenum: 0x0
    NumberOfReloc: 0 - NumberOfLinenum: 0
    Characteristics: 42000040

-----------------------------------
 Name: .debug_str
    VSize: 0xcbc - Va: 0x78000
    SizeOfRawData: 0xe00 - PtrToRawData: 0x6de00
    PtrToReloc: 0x0 - PtrToLinenum: 0x0
    NumberOfReloc: 0 - NumberOfLinenum: 0
    Characteristics: 42000040

-----------------------------------
 Name: .debug_line_str
    VSize: 0x28b6 - Va: 0x79000
    SizeOfRawData: 0x2a00 - PtrToRawData: 0x6ec00
    PtrToReloc: 0x0 - PtrToLinenum: 0x0
    NumberOfReloc: 0 - NumberOfLinenum: 0
    Characteristics: 42000040

-----------------------------------
 Name: .debug_loclists
    VSize: 0x7648 - Va: 0x7c000
    SizeOfRawData: 0x7800 - PtrToRawData: 0x71600
    PtrToReloc: 0x0 - PtrToLinenum: 0x0
    NumberOfReloc: 0 - NumberOfLinenum: 0
    Characteristics: 42000040

-----------------------------------
 Name: .debug_rnglists
    VSize: 0x8c2 - Va: 0x84000
    SizeOfRawData: 0xa00 - PtrToRawData: 0x78e00
    PtrToReloc: 0x0 - PtrToLinenum: 0x0
    NumberOfReloc: 0 - NumberOfLinenum: 0
    Characteristics: 42000040

-----------------------------------
```
## Import Table:
```
dll name : dbghelp.dll
        iat : 0x2f310 - func name : SymCleanup
        iat : 0x2f318 - func name : SymEnumSymbols
        iat : 0x2f320 - func name : SymGetModuleInfo64
        iat : 0x2f328 - func name : SymInitialize
        iat : 0x2f330 - func name : SymLoadModuleEx
        iat : 0x2f338 - func name : SymUnloadModule64


dll name : libgcc_s_seh-1.dll
        iat : 0x2f348 - func name : _Unwind_Resume


dll name : KERNEL32.dll
        iat : 0x2f358 - func name : CloseHandle
        iat : 0x2f360 - func name : CreateFileA
        iat : 0x2f368 - func name : DeleteCriticalSection
        iat : 0x2f370 - func name : EnterCriticalSection
        iat : 0x2f378 - func name : GetCurrentProcess
        iat : 0x2f380 - func name : GetFileSize
        iat : 0x2f388 - func name : GetLastError
        iat : 0x2f390 - func name : InitializeCriticalSection
        iat : 0x2f398 - func name : IsDBCSLeadByteEx
        iat : 0x2f3a0 - func name : LeaveCriticalSection
        iat : 0x2f3a8 - func name : MultiByteToWideChar
        iat : 0x2f3b0 - func name : ReadFile
        iat : 0x2f3b8 - func name : Sleep
        iat : 0x2f3c0 - func name : TlsGetValue
        iat : 0x2f3c8 - func name : VirtualProtect
        iat : 0x2f3d0 - func name : VirtualQuery
        iat : 0x2f3d8 - func name : WideCharToMultiByte


dll name : msvcrt.dll
        iat : 0x2f3e8 - func name : ___lc_codepage_func
        iat : 0x2f3f0 - func name : ___mb_cur_max_func
        iat : 0x2f3f8 - func name : __iob_func
        iat : 0x2f400 - func name : _amsg_exit
        iat : 0x2f408 - func name : _errno
        iat : 0x2f410 - func name : _initterm
        iat : 0x2f418 - func name : _lock
        iat : 0x2f420 - func name : _unlock
        iat : 0x2f428 - func name : abort
        iat : 0x2f430 - func name : calloc
        iat : 0x2f438 - func name : fputc
        iat : 0x2f440 - func name : free
        iat : 0x2f448 - func name : fwrite
        iat : 0x2f450 - func name : isxdigit
        iat : 0x2f458 - func name : localeconv
        iat : 0x2f460 - func name : malloc
        iat : 0x2f468 - func name : memchr
        iat : 0x2f470 - func name : memcpy
        iat : 0x2f478 - func name : memmove
        iat : 0x2f480 - func name : memset
        iat : 0x2f488 - func name : realloc
        iat : 0x2f490 - func name : strerror
        iat : 0x2f498 - func name : strlen
        iat : 0x2f4a0 - func name : strncmp
        iat : 0x2f4a8 - func name : vfprintf
        iat : 0x2f4b0 - func name : wcslen


dll name : libstdc++-6.dll
        iat : 0x2f4c0 - func name : _ZNKSt9basic_iosIcSt11char_traitsIcEEcvbEv
        iat : 0x2f4c8 - func name : _ZNSolsEPFRSoS_E
        iat : 0x2f4d0 - func name : _ZNSolsEPFRSt8ios_baseS0_E
        iat : 0x2f4d8 - func name : _ZNSolsEi
        iat : 0x2f4e0 - func name : _ZNSolsEm
        iat : 0x2f4e8 - func name : _ZNSolsEt
        iat : 0x2f4f0 - func name : _ZNSolsEy
        iat : 0x2f4f8 - func name : _ZNSt14basic_ifstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode
        iat : 0x2f500 - func name : _ZNSt14basic_ifstreamIcSt11char_traitsIcEED1Ev
        iat : 0x2f508 - func name : _ZNSt14basic_ofstreamIcSt11char_traitsIcEE5closeEv
        iat : 0x2f510 - func name : _ZNSt14basic_ofstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode
        iat : 0x2f518 - func name : _ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev
        iat : 0x2f520 - func name : _ZSt17__throw_bad_allocv
        iat : 0x2f528 - func name : _ZSt20__throw_length_errorPKc
        iat : 0x2f530 - func name : _ZSt28__throw_bad_array_new_lengthv
        iat : 0x2f538 - func name : _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
        iat : 0x2f540 - func name : _ZSt7getlineIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE
        iat : 0x2f548 - func name : _ZSt9terminatev
        iat : 0x2f550 - func name : _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
        iat : 0x2f558 - func name : _ZStlsIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_St5_Setw
        iat : 0x2f560 - func name : _ZTVN10__cxxabiv117__class_type_infoE
        iat : 0x2f568 - func name : _ZTVN10__cxxabiv120__si_class_type_infoE
        iat : 0x2f570 - func name : _ZdaPv
        iat : 0x2f578 - func name : _ZdlPv
        iat : 0x2f580 - func name : _ZdlPvy
        iat : 0x2f588 - func name : _Znay
        iat : 0x2f590 - func name : _Znwy
        iat : 0x2f598 - func name : __gxx_personality_seh0
```
## export table
```
-------------------------------------------------------------------------------------------------
Export Table Address: 0x2e000
name: libpe64.dll
Number of Functions: 3
Number of Names: 3
Export Func:
        Address : 0x146b - Name : extrn_pars
        Address : 0x14a8 - Name : extrn_pars32
        Address : 0x304b - Name : symbole

```
## symbol
```
Module:
  Base: 0x3a6580000
  Size: 544768 bytes
  Loaded:
  Type: 4


 Name: extrn_pars
     Address: 0x3a658146b
     Size: 3d bytes - Value: 0
     TagStr: SymTagPublicSymbol
     Reserved: 0x903dbfb368
     Scope: 0x0 - NameLen: 0xa
     Flags: 200 - Tag: 0xa


 Name: extrn_pars32
     Address: 0x3a65814a8
     Size: 1ba3 bytes - Value: 0
     TagStr: SymTagPublicSymbol
     Reserved: 0x903dbfb368
     Scope: 0x0 - NameLen: 0xc
     Flags: 200 - Tag: 0xa


 Name: symbole
     Address: 0x3a658304b
     Size: 0 bytes - Value: 0
     TagStr: SymTagPublicSymbol
     Reserved: 0x903dbfb368
     Scope: 0x0 - NameLen: 0x7
     Flags: 200 - Tag: 0xa
```
