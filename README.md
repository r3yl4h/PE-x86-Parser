PE-x64-parser
========

 this is a small pe32 and pe64 file analyzer in c++ with winapi, I didn't do it in the best way but hey, it's a small project like that that I thought was nice to do, the program can work in it calling with arguments or executing it as such.
(each file contains a code between unique quotes, this is why certain variables are redefined each time)
## dependancies
you just need to have winapi, cmake and DIA SDK
  * Unix:  `sudo apt-get install cmake`
  * RedHat/Fedora:  `sudo yum install cmake`
  * OSX:  `brew install cmake`
  * Windows : https://cmake.org/download/

and for dia you will just need to include the dia sdk include path to the cmakelist file which is generally located at the path: `C:/Program Files/Microsoft Visual Studio/2022/Professional/DIA SDK/include`

## dos header
```
C:\code\cpp\Pe_x86_parser\cmake-build-debug>.\Pe_x86_parser "C:\code\cpp\nrc project cnsl cpp\cmake-build-debug\nrc_project_cnsl_cpp.exe"
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
0x0: (uint32_t) Pe signature: 0x4550
0x4: (uint16_t) Machine: 0x8664
0x6: (uint16_t) Number of Sections: 20
0x8: (uint32_t) TimeDateStamp: 653acb80
0xC: (uint32_t) PointerToSymbolTable: 0x58400
0x10: (uint32_t) NumberOfSymbols: b7b
0x14: (uint16_t) SizeOfOptionalHeader: f0
0x16: (uint16_t) Characteristics: 26
```
## optional header
```
OPTIONAL HEADER64:
0x18: (uint16_t) Magic: 0x20b
0x1A: (uinht8_t) MajorLinkerVersion: 2
0x1B: (uint16_t) MinorLinkerVersion: 28
0x1C: (uint32_t) SizeOfCode: 4000
0x20: (uint32_t) SizeOfInitializedData: 9400
0x24: (uint32_t) SizeOfUninitializedData: 200
0x28: (uint32_t) AddressOfEntryPoint: 13f0
0x2C: (uint32_t) BaseOfCode: 1000
0x34: (uint64_t) ImageBase: 140000000
0x38: (uint32_t) SectionAlignment: 1000
0x3C: (uint32_t) FileAlignment: 200
0x40: (uint16_t) MajorOperatingSystemVersion: 4
0x42: (uint16_t) MinorOperatingSystemVersion: 0
0x44: (uint16_t) MajorImageVersion: 0
0x46: (uint16_t) MinorImageVersion: 0
0x48: (uint16_t) MajorSubsystemVersion: 5
0x4A: (uint16_t) MinorSubsystemVersion: 2
0x4C: (uint32_t) Reserved1
0x50: (uint32_t) SizeOfImage: 64000
0x54: (uint32_t) SizeOfHeaders: 600
0x58: (uint32_t) CheckSum: 77077
0x5C: (uint16_t) Subsystem: 3
0x5E: (uint16_t) DllCharacteristics: 160
0x60: (uint64_t) SizeOfStackReserve: 200000
0x68: (uint64_t) SizeOfStackCommit: 1000
0x70: (uint64_t) SizeOfHeapReserve: 100000
0x78: (uint64_t) SizeOfHeapCommit: 1000
0x80: (uint32_t) LoaderFlags: 0
0x84: (uint32_t) NumberOfRvaAndSizes: 10
0x88: (uint32_t) ExportDirectory VA: 0
0x8C: (uint32_t) ExportDirectory Size: 0
0x90: (uint32_t) ImportDirectory VA: b000
0x94: (uint32_t) ImportDirectory Size: 1e4c
0x98: (uint32_t) ResourceDirectory VA: f000
0x9C: (uint32_t) ResourceDirectory Size: 4e8
0xA0: (uint32_t) ExceptionDirectory VA: 8000
0xA4: (uint32_t) ExceptionDirectory Size: 6c0
0xA8: (uint32_t) SecurityDirectory VA: 0
0xAC: (uint32_t) SecurityDirectory Size: 0
0xB0: (uint32_t) BaseRelocationTable VA: 10000
0xB4: (uint32_t) BaseRelocationTable Size: e8
0xB8: (uint32_t) DebugDirectory VA: 0
0xBC: (uint32_t) DebugDirectory Size: 0
0xC0: (uint32_t) ArchitectureSpecificData VA: 0
0xC4: (uint32_t) ArchitectureSpecificData Size: 0
0xC8: (uint32_t) RVAofGP VA: 0
0xCC: (uint32_t) RVAofGP Size: 0
0xD0: (uint32_t) TLSDirectory VA: 6560
0xD4: (uint32_t) TLSDirectory Size: 28
0xD8: (uint32_t) LoadConfigurationDirectory VA: 0
0xDC: (uint32_t) LoadConfigurationDirectory Size: 0
0xE0: (uint32_t) BoundImportDirectoryinheaders VA: 0
0xE4: (uint32_t) BoundImportDirectoryinheaders Size: 0
0xE8: (uint32_t) ImportAddressTable VA: b420
0xEC: (uint32_t) ImportAddressTable Size: 3b8
0xF0: (uint32_t) DelayLoadImportDescriptors VA: 0
0xF4: (uint32_t) DelayLoadImportDescriptors Size: 0
0xF8: (uint32_t) COMRuntimedescriptor VA: 0
0xFC: (uint32_t) COMRuntimedescriptor Size: 0
```
## Import Table:
```
 Import Section address: 0xb000
 Import Table:
        Address: 0xb7d8         DLL: libgcc_s_seh-1.dll         Function: _Unwind_Resume
        Address: 0xb7ec         DLL: KERNEL32.dll       Function: DeleteCriticalSection
        Address: 0xb804         DLL: KERNEL32.dll       Function: EnterCriticalSection
        Address: 0xb81c         DLL: KERNEL32.dll       Function: GetLastError
        Address: 0xb82c         DLL: KERNEL32.dll       Function: InitializeCriticalSection
        Address: 0xb848         DLL: KERNEL32.dll       Function: LeaveCriticalSection
        Address: 0xb860         DLL: KERNEL32.dll       Function: SetUnhandledExceptionFilter
        Address: 0xb87e         DLL: KERNEL32.dll       Function: Sleep
        Address: 0xb886         DLL: KERNEL32.dll       Function: TlsGetValue
        Address: 0xb894         DLL: KERNEL32.dll       Function: VirtualProtect
        Address: 0xb8a6         DLL: KERNEL32.dll       Function: VirtualQuery
        Address: 0xb8b6         DLL: KERNEL32.dll       Function: __C_specific_handler
        Address: 0xb8ce         DLL: msvcrt.dll         Function: __getmainargs
        Address: 0xb8de         DLL: msvcrt.dll         Function: __initenv
        Address: 0xb8ea         DLL: msvcrt.dll         Function: __iob_func
        Address: 0xb8f8         DLL: msvcrt.dll         Function: __set_app_type
        Address: 0xb90a         DLL: msvcrt.dll         Function: __setusermatherr
        Address: 0xb91e         DLL: msvcrt.dll         Function: _amsg_exit
        Address: 0xb92c         DLL: msvcrt.dll         Function: _cexit
        Address: 0xb936         DLL: msvcrt.dll         Function: _commode
        Address: 0xb942         DLL: msvcrt.dll         Function: _fmode
        Address: 0xb94c         DLL: msvcrt.dll         Function: _initterm
        Address: 0xb958         DLL: msvcrt.dll         Function: _onexit
        Address: 0xb962         DLL: msvcrt.dll         Function: abort
        Address: 0xb96a         DLL: msvcrt.dll         Function: calloc
        Address: 0xb974         DLL: msvcrt.dll         Function: exit
        Address: 0xb97c         DLL: msvcrt.dll         Function: fprintf
        Address: 0xb986         DLL: msvcrt.dll         Function: free
        Address: 0xb98e         DLL: msvcrt.dll         Function: fwrite
        Address: 0xb998         DLL: msvcrt.dll         Function: malloc
        Address: 0xb9a2         DLL: msvcrt.dll         Function: memcmp
        Address: 0xb9ac         DLL: msvcrt.dll         Function: memcpy
        Address: 0xb9b6         DLL: msvcrt.dll         Function: signal
        Address: 0xb9c0         DLL: msvcrt.dll         Function: strlen
        Address: 0xb9ca         DLL: msvcrt.dll         Function: strncmp
        Address: 0xb9d4         DLL: msvcrt.dll         Function: vfprintf
        Address: 0xb9e0         DLL: libstdc++-6.dll    Function: _ZNKSt10filesystem7__cxx1118directory_iteratordeEv
        Address: 0xba18         DLL: libstdc++-6.dll    Function: _ZNKSt10filesystem7__cxx114path5_List13_Impl_deleterclEPNS2_5_ImplE
        Address: 0xba60         DLL: libstdc++-6.dll    Function: _ZNKSt25__codecvt_utf8_utf16_baseIwE10do_unshiftERiPcS2_RS2_
        Address: 0xbaa0         DLL: libstdc++-6.dll    Function: _ZNKSt25__codecvt_utf8_utf16_baseIwE11do_encodingEv
        Address: 0xbad8         DLL: libstdc++-6.dll    Function: _ZNKSt25__codecvt_utf8_utf16_baseIwE13do_max_lengthEv
        Address: 0xbb10         DLL: libstdc++-6.dll    Function: _ZNKSt25__codecvt_utf8_utf16_baseIwE16do_always_noconvEv
        Address: 0xbb4c         DLL: libstdc++-6.dll    Function: _ZNKSt25__codecvt_utf8_utf16_baseIwE5do_inERiPKcS3_RS3_PwS5_RS5_
        Address: 0xbb90         DLL: libstdc++-6.dll    Function: _ZNKSt25__codecvt_utf8_utf16_baseIwE6do_outERiPKwS3_RS3_PcS5_RS5_
        Address: 0xbbd4         DLL: libstdc++-6.dll    Function: _ZNKSt25__codecvt_utf8_utf16_baseIwE9do_lengthERiPKcS3_y
        Address: 0xbc10         DLL: libstdc++-6.dll    Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE3endEv
        Address: 0xbc50         DLL: libstdc++-6.dll    Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4dataEv
        Address: 0xbc90         DLL: libstdc++-6.dll    Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4findERKS4_y
        Address: 0xbcd8         DLL: libstdc++-6.dll    Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv
        Address: 0xbd18         DLL: libstdc++-6.dll    Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5beginEv
        Address: 0xbd5c         DLL: libstdc++-6.dll    Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv
        Address: 0xbda0         DLL: libstdc++-6.dll    Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEcvSt17basic_string_viewIcS2_EEv
        Address: 0xbdf8         DLL: libstdc++-6.dll    Function: _ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE4sizeEv
        Address: 0xbe38         DLL: libstdc++-6.dll    Function: _ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE5c_strEv
        Address: 0xbe7c         DLL: libstdc++-6.dll    Function: _ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEcvSt17basic_string_viewIwS2_EEv
        Address: 0xbed4         DLL: libstdc++-6.dll    Function: _ZNKSt7__cxx1119basic_ostringstreamIcSt11char_traitsIcESaIcEE3strEv
        Address: 0xbf1c         DLL: libstdc++-6.dll    Function: _ZNKSt9basic_iosIcSt11char_traitsIcEEcvbEv
        Address: 0xbf4c         DLL: libstdc++-6.dll    Function: _ZNSolsEPFRSoS_E
        Address: 0xbf60         DLL: libstdc++-6.dll    Function: _ZNSolsEi
        Address: 0xbf6c         DLL: libstdc++-6.dll    Function: _ZNSt10filesystem6statusERKNS_7__cxx114pathE
        Address: 0xbf9c         DLL: libstdc++-6.dll    Function: _ZNSt10filesystem7__cxx1116filesystem_errorC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt10error_code
        Address: 0xc014         DLL: libstdc++-6.dll    Function: _ZNSt10filesystem7__cxx1116filesystem_errorD1Ev
        Address: 0xc048         DLL: libstdc++-6.dll    Function: _ZNSt10filesystem7__cxx1118directory_iteratorC1ERKNS0_4pathENS_17directory_optionsEPSt10error_code
        Address: 0xc0b0         DLL: libstdc++-6.dll    Function: _ZNSt10filesystem7__cxx1118directory_iteratorppEv
        Address: 0xc0e4         DLL: libstdc++-6.dll    Function: _ZNSt10filesystem7__cxx114path14_M_split_cmptsEv
        Address: 0xc118         DLL: libstdc++-6.dll    Function: _ZNSt10filesystem7__cxx114path5_ListC1Ev
        Address: 0xc144         DLL: libstdc++-6.dll    Function: _ZNSt12__shared_ptrINSt10filesystem7__cxx114_DirELN9__gnu_cxx12_Lock_policyE2EEC1EOS5_
        Address: 0xc1a0         DLL: libstdc++-6.dll    Function: _ZNSt12__shared_ptrINSt10filesystem7__cxx114_DirELN9__gnu_cxx12_Lock_policyE2EEC1Ev
        Address: 0xc1f8         DLL: libstdc++-6.dll    Function: _ZNSt14basic_ifstreamIcSt11char_traitsIcEEC1EPKwSt13_Ios_Openmode
        Address: 0xc23c         DLL: libstdc++-6.dll    Function: _ZNSt14basic_ifstreamIcSt11char_traitsIcEED1Ev
        Address: 0xc270         DLL: libstdc++-6.dll    Function: _ZNSt25__codecvt_utf8_utf16_baseIwED2Ev
        Address: 0xc29c         DLL: libstdc++-6.dll    Function: _ZNSt3_V216generic_categoryEv
        Address: 0xc2bc         DLL: libstdc++-6.dll    Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv
        Address: 0xc304         DLL: libstdc++-6.dll    Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_capacityEy
        Address: 0xc34c         DLL: libstdc++-6.dll    Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC1EPcRKS3_
        Address: 0xc39c         DLL: libstdc++-6.dll    Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv
        Address: 0xc3e8         DLL: libstdc++-6.dll    Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEy
        Address: 0xc434         DLL: libstdc++-6.dll    Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsEPcPKcS7_
        Address: 0xc484         DLL: libstdc++-6.dll    Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4backEv
        Address: 0xc4c4         DLL: libstdc++-6.dll    Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5clearEv
        Address: 0xc504         DLL: libstdc++-6.dll    Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5frontEv
        Address: 0xc544         DLL: libstdc++-6.dll    Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6resizeEy
        Address: 0xc588         DLL: libstdc++-6.dll    Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEPc
        Address: 0xc5cc         DLL: libstdc++-6.dll    Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERyy
        Address: 0xc614         DLL: libstdc++-6.dll    Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_
        Address: 0xc654         DLL: libstdc++-6.dll    Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS3_
        Address: 0xc694         DLL: libstdc++-6.dll    Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev
        Address: 0xc6d0         DLL: libstdc++-6.dll    Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
        Address: 0xc70c         DLL: libstdc++-6.dll    Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE4backEv
        Address: 0xc74c         DLL: libstdc++-6.dll    Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE5clearEv
        Address: 0xc78c         DLL: libstdc++-6.dll    Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE5frontEv
        Address: 0xc7cc         DLL: libstdc++-6.dll    Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE6resizeEy
        Address: 0xc810         DLL: libstdc++-6.dll    Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEC1EOS4_
        Address: 0xc850         DLL: libstdc++-6.dll    Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEC1Ev
        Address: 0xc88c         DLL: libstdc++-6.dll    Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEED1Ev
        Address: 0xc8c8         DLL: libstdc++-6.dll    Function: _ZNSt7__cxx1119basic_ostringstreamIcSt11char_traitsIcESaIcEEC1Ev
        Address: 0xc90c         DLL: libstdc++-6.dll    Function: _ZNSt7__cxx1119basic_ostringstreamIcSt11char_traitsIcESaIcEED1Ev
        Address: 0xc950         DLL: libstdc++-6.dll    Function: _ZNSt7codecvtIwciEC2Ey
        Address: 0xc96c         DLL: libstdc++-6.dll    Function: _ZSt19__throw_logic_errorPKc
        Address: 0xc98c         DLL: libstdc++-6.dll    Function: _ZSt3cin
        Address: 0xc998         DLL: libstdc++-6.dll    Function: _ZSt4cout
        Address: 0xc9a4         DLL: libstdc++-6.dll    Function: _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
        Address: 0xc9e4         DLL: libstdc++-6.dll    Function: _ZSt7getlineIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE
        Address: 0xca50         DLL: libstdc++-6.dll    Function: _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
        Address: 0xca8c         DLL: libstdc++-6.dll    Function: _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
        Address: 0xcac4         DLL: libstdc++-6.dll    Function: _ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE
        Address: 0xcb2c         DLL: libstdc++-6.dll    Function: _ZTVN10__cxxabiv117__class_type_infoE
        Address: 0xcb54         DLL: libstdc++-6.dll    Function: _ZTVN10__cxxabiv120__si_class_type_infoE
        Address: 0xcb80         DLL: libstdc++-6.dll    Function: _ZTVN10__cxxabiv121__vmi_class_type_infoE
        Address: 0xcbac         DLL: libstdc++-6.dll    Function: _ZTVSt25__codecvt_utf8_utf16_baseIwE
        Address: 0xcbd4         DLL: libstdc++-6.dll    Function: _ZdlPvy
        Address: 0xcbe0         DLL: libstdc++-6.dll    Function: __cxa_allocate_exception
        Address: 0xcbfc         DLL: libstdc++-6.dll    Function: __cxa_free_exception
        Address: 0xcc14         DLL: libstdc++-6.dll    Function: __cxa_throw
        Address: 0xcc24         DLL: libstdc++-6.dll    Function: __gxx_personality_seh0
```
## export table
```
-------------------------------------------------------------------------------------------------
Export Table Address: 0x2e000
Export Table:
        DLL Name: libpe64.dll
        Number of Functions: 3
        Number of Names: 3
        Address: 0x146b                 Ordinal: 1              Function: extrn_pars
                Address: 0x14a8                 Ordinal: 2              Function: extrn_pars32
                Address: 0x304b                 Ordinal: 3              Function: symbole
```
## symbol
```
get the symbol?(y|yes):y
 Module:
  Base: 0x3a6580000
  Size: 544768 bytes
  Loaded:
  Type: 4


 Name: extrn_pars
     Address: 0x3a658146b
     Size: 3d bytes - Value: 0
     TagStr: SymTagPublicSymbol
     Reserved: 0x5d4fffb8d8
     Scope: 0x0 - NameLen: 0xa
     Flags: 200 - Tag: 0xa


 Name: extrn_pars32
     Address: 0x3a65814a8
     Size: 1ba3 bytes - Value: 0
     TagStr: SymTagPublicSymbol
     Reserved: 0x5d4fffb8d8
     Scope: 0x0 - NameLen: 0xc
     Flags: 200 - Tag: 0xa


 Name: symbole
     Address: 0x3a658304b
     Size: 0 bytes - Value: 0
     TagStr: SymTagPublicSymbol
     Reserved: 0x5d4fffb8d8
     Scope: 0x0 - NameLen: 0x7
     Flags: 200 - Tag: 0xa
```

