ney-PE64-parser
========

 this is a small pe64 file analyzer in c++ with winapi, I didn't do it in the best way but hey, it's a small project like that that I thought was nice to do, the program can work in it calling with arguments or executing it as such.

## dependancies
you just need to have winapi and cmake

### install Cmake
  * Debian/Ubuntu: `sudo apt-get install cmake`
  * RedHat/Fedora: `sudo yum install cmake`
  * OSX: `brew install cmake`
  * Windows : `https://cmake.org/download/`

#### output
```
PS C:\code\cpp\neyPe64 parser> cmake-build-debug/ney.exe "C:\code\cpp\peipeiy PE64 extcrte\cmake-build-debug\libpe64.dll"

Header:
  Machine: 0x8664
  TimeDateStamp: 0x658c93d7 (UTC)
  DOS Signature: 0x5a4d
  PE Signature: 0x4550
  Base image address: 0x3a6580000
  Number of sections: 20
  File header size: 240 bytes
  Subsystem version: 5.2
  Characteristics of the DLL: DLL

Optional Header:
  Magic: 20b
  AddressOfEntryPoint: 0x1330
  SectionAlignment: 0x1000
  FileAlignment: 0x200
  SizeOfImage: 323584 bytes (0.309 MB)
  SizeOfHeaders: 1536 bytes (0.001 MB)
  SizeOfCode: 21504 bytes (0.021 MB)
  SizeOfInitializedData: 37888 bytes (0.036 MB)
  SizeOfUninitializedData: 512 bytes (0.000 MB)
  BaseOfCode: 0x1000
  DllCharacteristics: 0x160
  SizeOfStackReserve: 2097152 bytes (2.000 MB)
  SizeOfStackCommit: 4096 bytes (0.004 MB)
  SizeOfHeapReserve: 1048576 bytes (1.000 MB)
  SizeOfHeapCommit: 4096 bytes (0.004 MB)
  Major Linker Version: 2
  Major Image Version: 0
  Major subsystem version: 5
  Minor Linker Version: 28
  Minor Image Version: 0
  Minor Operating System Version: 0
  Architecture: 64-bit


Section: .text
   Virtual Size: 21176 bytes (0.020 MB)
   RVA: 0x1000
   Offset: 1536 bytes
   Raw Size: 21504 bytes (0.021 MB)
   Section Characteristics: Executable Readable
   Section Type: Code Initialized Data
   Section Flags: 0x60000060
   Base Relocation Table RVA: 0x10000

Section: .data
   Virtual Size: 112 bytes (0.000 MB)
   RVA: 0x7000
   Offset: 23040 bytes
   Raw Size: 512 bytes (0.000 MB)
   Section Characteristics: Readable Writable
   Section Type: Initialized Data
   Section Flags: 0xc0000040
   Base Relocation Table RVA: 0x10000

Section: .rdata
   Virtual Size: 4024 bytes (0.004 MB)
   RVA: 0x8000
   Offset: 23552 bytes
   Raw Size: 4096 bytes (0.004 MB)
   Section Characteristics: Readable
   Section Type: Initialized Data
   Section Flags: 0x40000040
   Base Relocation Table RVA: 0x10000

Section: .pdata
   Virtual Size: 1236 bytes (0.001 MB)
   RVA: 0x9000
   Offset: 27648 bytes
   Raw Size: 1536 bytes (0.001 MB)
   Section Characteristics: Readable
   Section Type: Initialized Data
   Section Flags: 0x40000040
   Base Relocation Table RVA: 0x10000

Section: .xdata
   Virtual Size: 1240 bytes (0.001 MB)
   RVA: 0xa000
   Offset: 29184 bytes
   Raw Size: 1536 bytes (0.001 MB)
   Section Characteristics: Readable
   Section Type: Initialized Data
   Section Flags: 0x40000040
   Base Relocation Table RVA: 0x10000

Section: .bss
   Virtual Size: 272 bytes (0.000 MB)
   RVA: 0xb000
   Offset: 0 bytes
   Raw Size: 0 bytes (0.000 MB)
   Section Characteristics: Readable Writable
   Section Type: Uninitialized Data
   Section Flags: 0xc0000080
   Base Relocation Table RVA: 0x10000

Section: .edata
   Virtual Size: 3519 bytes (0.003 MB)
   RVA: 0xc000
   Offset: 30720 bytes
   Raw Size: 3584 bytes (0.003 MB)
   Section Characteristics: Readable
   Section Type: Initialized Data
   Section Flags: 0x40000040
   Base Relocation Table RVA: 0x10000

Section: .idata
   Virtual Size: 3304 bytes (0.003 MB)
   RVA: 0xd000
   Offset: 34304 bytes
   Raw Size: 3584 bytes (0.003 MB)
   Section Characteristics: Readable Writable
   Section Type: Initialized Data
   Section Flags: 0xc0000040
   Base Relocation Table RVA: 0x10000

Section: .CRT
   Virtual Size: 88 bytes (0.000 MB)
   RVA: 0xe000
   Offset: 37888 bytes
   Raw Size: 512 bytes (0.000 MB)
   Section Characteristics: Readable Writable
   Section Type: Initialized Data
   Section Flags: 0xc0000040
   Base Relocation Table RVA: 0x10000

Section: .tls
   Virtual Size: 16 bytes (0.000 MB)
   RVA: 0xf000
   Offset: 38400 bytes
   Raw Size: 512 bytes (0.000 MB)
   Section Characteristics: Readable Writable
   Section Type: Initialized Data
   Section Flags: 0xc0000040
   Base Relocation Table RVA: 0x10000

Section: .reloc
   Virtual Size: 100 bytes (0.000 MB)
   RVA: 0x10000
   Offset: 38912 bytes
   Raw Size: 512 bytes (0.000 MB)
   Section Characteristics: Readable
   Section Type: Initialized Data
   Section Flags: 0x42000040
   Base Relocation Table RVA: 0x10000

Section: /4
   Virtual Size: 2416 bytes (0.002 MB)
   RVA: 0x11000
   Offset: 39424 bytes
   Raw Size: 2560 bytes (0.002 MB)
   Section Characteristics: Readable
   Section Type: Initialized Data
   Section Flags: 0x42000040
   Base Relocation Table RVA: 0x10000

Section: /19
   Virtual Size: 173457 bytes (0.165 MB)
   RVA: 0x12000
   Offset: 41984 bytes
   Raw Size: 173568 bytes (0.166 MB)
   Section Characteristics: Readable
   Section Type: Initialized Data
   Section Flags: 0x42000040
   Base Relocation Table RVA: 0x10000

Section: /31
   Virtual Size: 17272 bytes (0.016 MB)
   RVA: 0x3d000
   Offset: 215552 bytes
   Raw Size: 17408 bytes (0.017 MB)
   Section Characteristics: Readable
   Section Type: Initialized Data
   Section Flags: 0x42000040
   Base Relocation Table RVA: 0x10000

Section: /45
   Virtual Size: 16317 bytes (0.016 MB)
   RVA: 0x42000
   Offset: 232960 bytes
   Raw Size: 16384 bytes (0.016 MB)
   Section Characteristics: Readable
   Section Type: Initialized Data
   Section Flags: 0x42000040
   Base Relocation Table RVA: 0x10000

Section: /57
   Virtual Size: 6096 bytes (0.006 MB)
   RVA: 0x46000
   Offset: 249344 bytes
   Raw Size: 6144 bytes (0.006 MB)
   Section Characteristics: Readable
   Section Type: Initialized Data
   Section Flags: 0x42000040
   Base Relocation Table RVA: 0x10000

Section: /70
   Virtual Size: 1956 bytes (0.002 MB)
   RVA: 0x48000
   Offset: 255488 bytes
   Raw Size: 2048 bytes (0.002 MB)
   Section Characteristics: Readable
   Section Type: Initialized Data
   Section Flags: 0x42000040
   Base Relocation Table RVA: 0x10000

Section: /81
   Virtual Size: 9363 bytes (0.009 MB)
   RVA: 0x49000
   Offset: 257536 bytes
   Raw Size: 9728 bytes (0.009 MB)
   Section Characteristics: Readable 
   Section Type: Initialized Data
   Section Flags: 0x42000040
   Base Relocation Table RVA: 0x10000

Section: /97
   Virtual Size: 4501 bytes (0.004 MB)
   RVA: 0x4c000
   Offset: 267264 bytes
   Raw Size: 4608 bytes (0.004 MB)
   Section Characteristics: Readable
   Section Type: Initialized Data
   Section Flags: 0x42000040
   Base Relocation Table RVA: 0x10000

Section: /113
   Virtual Size: 1501 bytes (0.001 MB)
   RVA: 0x4e000
   Offset: 271872 bytes
   Raw Size: 1536 bytes (0.001 MB)
   Section Characteristics: Readable
   Section Type: Initialized Data
   Section Flags: 0x42000040
   Base Relocation Table RVA: 0x10000


Import Table Address: 0x3a658d000
Import Table:
        Address: 0x3a658d4e8                    DLL: dbghelp.dll                Function: SymCleanup
                Address: 0x3a658d4f6                    DLL: dbghelp.dll                Function: SymEnumSymbols
                Address: 0x3a658d508                    DLL: dbghelp.dll                Function: SymInitialize
                Address: 0x3a658d518                    DLL: dbghelp.dll                Function: SymLoadModuleEx
                Address: 0x3a658d52a                    DLL: dbghelp.dll                Function: SymUnloadModule64
                Address: 0x3a658d540                    DLL: libgcc_s_seh-1.dll                 Function: _Unwind_Resume
                Address: 0x3a658d554                    DLL: KERNEL32.dll               Function: CloseHandle
                Address: 0x3a658d562                    DLL: KERNEL32.dll               Function: CreateFileA
                Address: 0x3a658d570                    DLL: KERNEL32.dll               Function: DeleteCriticalSection
                Address: 0x3a658d588                    DLL: KERNEL32.dll               Function: EnterCriticalSection
                Address: 0x3a658d5a0                    DLL: KERNEL32.dll               Function: GetCurrentProcess
                Address: 0x3a658d5b4                    DLL: KERNEL32.dll               Function: GetFileSize
                Address: 0x3a658d5c2                    DLL: KERNEL32.dll               Function: GetLastError
                Address: 0x3a658d5d2                    DLL: KERNEL32.dll               Function: InitializeCriticalSection
                Address: 0x3a658d5ee                    DLL: KERNEL32.dll               Function: LeaveCriticalSection
                Address: 0x3a658d606                    DLL: KERNEL32.dll               Function: ReadFile
                Address: 0x3a658d612                    DLL: KERNEL32.dll               Function: Sleep
                Address: 0x3a658d61a                    DLL: KERNEL32.dll               Function: TlsGetValue
                Address: 0x3a658d628                    DLL: KERNEL32.dll               Function: VirtualProtect
                Address: 0x3a658d63a                    DLL: KERNEL32.dll               Function: VirtualQuery
                Address: 0x3a658d64a                    DLL: msvcrt.dll                 Function: __iob_func
                Address: 0x3a658d658                    DLL: msvcrt.dll                 Function: _amsg_exit
                Address: 0x3a658d666                    DLL: msvcrt.dll                 Function: _initterm
                Address: 0x3a658d672                    DLL: msvcrt.dll                 Function: _lock
                Address: 0x3a658d67a                    DLL: msvcrt.dll                 Function: _unlock
                Address: 0x3a658d684                    DLL: msvcrt.dll                 Function: abort
                Address: 0x3a658d68c                    DLL: msvcrt.dll                 Function: calloc
                Address: 0x3a658d696                    DLL: msvcrt.dll                 Function: free
                Address: 0x3a658d69e                    DLL: msvcrt.dll                 Function: fwrite
                Address: 0x3a658d6a8                    DLL: msvcrt.dll                 Function: memcpy
                Address: 0x3a658d6b2                    DLL: msvcrt.dll                 Function: realloc
                Address: 0x3a658d6bc                    DLL: msvcrt.dll                 Function: strcpy
                Address: 0x3a658d6c6                    DLL: msvcrt.dll                 Function: strlen
                Address: 0x3a658d6d0                    DLL: msvcrt.dll                 Function: strncmp
                Address: 0x3a658d6da                    DLL: msvcrt.dll                 Function: vfprintf
                Address: 0x3a658d6e8                    DLL: libstdc++-6.dll            Function: _ZNKSt9basic_iosIcSt11char_traitsIcEEcvbEv
                Address: 0x3a658d718                    DLL: libstdc++-6.dll            Function: _ZNSolsEPFRSoS_E
                Address: 0x3a658d72c                    DLL: libstdc++-6.dll            Function: _ZNSolsEPFRSt8ios_baseS0_E
                Address: 0x3a658d74c                    DLL: libstdc++-6.dll            Function: _ZNSolsEd
                Address: 0x3a658d758                    DLL: libstdc++-6.dll            Function: _ZNSolsEi
                Address: 0x3a658d764                    DLL: libstdc++-6.dll            Function: _ZNSolsEm
                Address: 0x3a658d770                    DLL: libstdc++-6.dll            Function: _ZNSolsEt
                Address: 0x3a658d77c                    DLL: libstdc++-6.dll            Function: _ZNSolsEy
                Address: 0x3a658d788                    DLL: libstdc++-6.dll            Function: _ZNSt14basic_ifstreamIcSt11char_traitsIcEE5closeEv
                Address: 0x3a658d7c0                    DLL: libstdc++-6.dll            Function: _ZNSt14basic_ifstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode
                Address: 0x3a658d804                    DLL: libstdc++-6.dll            Function: _ZNSt14basic_ifstreamIcSt11char_traitsIcEED1Ev
                Address: 0x3a658d838                    DLL: libstdc++-6.dll            Function: _ZNSt14basic_ofstreamIcSt11char_traitsIcEE5closeEv
                Address: 0x3a658d870                    DLL: libstdc++-6.dll            Function: _ZNSt14basic_ofstreamIcSt11char_traitsIcEE7is_openEv
                Address: 0x3a658d8a8                    DLL: libstdc++-6.dll            Function: _ZNSt14basic_ofstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode
                Address: 0x3a658d8ec                    DLL: libstdc++-6.dll            Function: _ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev
                Address: 0x3a658d920                    DLL: libstdc++-6.dll            Function: _ZSt17__throw_bad_allocv
                Address: 0x3a658d93c                    DLL: libstdc++-6.dll            Function: _ZSt20__throw_length_errorPKc
                Address: 0x3a658d95c                    DLL: libstdc++-6.dll            Function: _ZSt28__throw_bad_array_new_lengthv
                Address: 0x3a658d984                    DLL: libstdc++-6.dll            Function: _ZSt4cerr
                Address: 0x3a658d990                    DLL: libstdc++-6.dll            Function: _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
                Address: 0x3a658d9d0                    DLL: libstdc++-6.dll            Function: _ZSt7getlineIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE
                Address: 0x3a658da3c                    DLL: libstdc++-6.dll            Function: _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
                Address: 0x3a658da78                    DLL: libstdc++-6.dll            Function: _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKh
                Address: 0x3a658dab4                    DLL: libstdc++-6.dll            Function: _ZStlsIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_St13_Setprecision
                Address: 0x3a658db00                    DLL: libstdc++-6.dll            Function: _ZStlsIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_St5_Setw
                Address: 0x3a658db44                    DLL: libstdc++-6.dll            Function: _ZdaPv
                Address: 0x3a658db50                    DLL: libstdc++-6.dll            Function: _ZdlPv
                Address: 0x3a658db5c                    DLL: libstdc++-6.dll            Function: _ZdlPvy
                Address: 0x3a658db68                    DLL: libstdc++-6.dll            Function: _Znay
                Address: 0x3a658db70                    DLL: libstdc++-6.dll            Function: _Znwy
                Address: 0x3a658db78                    DLL: libstdc++-6.dll            Function: __gxx_personality_seh0
        Number of Functions: 66


Export Table Address: 0x3a658c000
Export Table:
        DLL Name: libpe64.dll
        Number of Functions: 63
        Number of Names: 63
        Address: 0x3a6581380            Ordinal: 1              Function: All
                Address: 0x3a65832dc            Ordinal: 2              Function: OptionalHeader
                Address: 0x3a65828a0            Ordinal: 3              Function: PrintOptionalHeader
                Address: 0x3a65853f0            Ordinal: 4              Function: _ZN9__gnu_cxx11char_traitsIcE4copyEPcPKcy
                Address: 0x3a6585480            Ordinal: 5              Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_is_localEv
                Address: 0x3a65854e0            Ordinal: 6              Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv
                Address: 0x3a6585510            Ordinal: 7              Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv
                Address: 0x3a6585520            Ordinal: 8              Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv
                Address: 0x3a6585540            Ordinal: 9              Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv
                Address: 0x3a6585560            Ordinal: 10             Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6lengthEv
                Address: 0x3a6585580            Ordinal: 11             Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv
                Address: 0x3a65855a0            Ordinal: 12             Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8capacityEv
                Address: 0x3a65855e0            Ordinal: 13             Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8max_sizeEv
                Address: 0x3a6585610            Ordinal: 14             Function: _ZNSt11char_traitsIcE4copyEPcPKcy
                Address: 0x3a6585680            Ordinal: 15             Function: _ZNSt11char_traitsIcE6assignERcRKc
                Address: 0x3a65856c0            Ordinal: 16             Function: _ZNSt15__new_allocatorIcE10deallocateEPcy
                Address: 0x3a65856f0            Ordinal: 17             Function: _ZNSt15__new_allocatorIcE8allocateEyPKv
                Address: 0x3a6585750            Ordinal: 18             Function: _ZNSt19__ptr_traits_ptr_toIPKcS0_Lb0EE10pointer_toERS0_
                Address: 0x3a6585770            Ordinal: 19             Function: _ZNSt19__ptr_traits_ptr_toIPccLb0EE10pointer_toERc
                Address: 0x3a6585790            Ordinal: 20             Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_destroyEy
                Address: 0x3a6585830            Ordinal: 21             Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv
                Address: 0x3a6585870            Ordinal: 22             Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_capacityEy
                Address: 0x3a6585890            Ordinal: 23             Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC1EPcOS3_
                Address: 0x3a65858e0            Ordinal: 24             Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD1Ev
                Address: 0x3a6585900            Ordinal: 25             Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv
                Address: 0x3a6585930            Ordinal: 26             Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEy
                Address: 0x3a6585980            Ordinal: 27             Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv
                Address: 0x3a6585990            Ordinal: 28             Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_
                Address: 0x3a6585be0            Ordinal: 29             Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEPc
                Address: 0x3a6585c00            Ordinal: 30             Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_S_copyEPcPKcy
                Address: 0x3a6585c50            Ordinal: 31             Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_
                Address: 0x3a6585d50            Ordinal: 32             Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERyy
                Address: 0x3a6585e70            Ordinal: 33             Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_lengthEy
                Address: 0x3a6585e90            Ordinal: 34             Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev
                Address: 0x3a6585f30            Ordinal: 35             Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
                Address: 0x3a6585f60            Ordinal: 36             Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSERKS4_
                Address: 0x3a6585f90            Ordinal: 37             Function: _ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_
                Address: 0x3a6586000            Ordinal: 38             Function: _ZSt11__addressofIKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEPT_RS7_
                Address: 0x3a6586010            Ordinal: 39             Function: _ZSt11__addressofIKcEPT_RS1_
                Address: 0x3a6586020            Ordinal: 40             Function: _ZSt11__addressofIcEPT_RS0_
                Address: 0x3a6586030            Ordinal: 41             Function: _ZSt12construct_atIcJRKcEEDTgsnwcvPvLi0E_T_pispcl7declvalIT0_EEEEPS3_DpOS4_
                Address: 0x3a6586080            Ordinal: 42             Function: _ZSt12setprecisioni
                Address: 0x3a6586090            Ordinal: 43             Function: _ZSt21is_constant_evaluatedv
                Address: 0x3a65860a0            Ordinal: 44             Function: _ZSt23__is_constant_evaluatedv
                Address: 0x3a65860b0            Ordinal: 45             Function: _ZSt3decRSt8ios_base
                Address: 0x3a65860e0            Ordinal: 46             Function: _ZSt3hexRSt8ios_base
                Address: 0x3a6586110            Ordinal: 47             Function: _ZSt4moveIRSaIcEEONSt16remove_referenceIT_E4typeEOS3_
                Address: 0x3a6586120            Ordinal: 48             Function: _ZSt4setwi
                Address: 0x3a6586130            Ordinal: 49             Function: _ZSt5fixedRSt8ios_base
                Address: 0x3a6586160            Ordinal: 50             Function: _ZSt7forwardIRKcEOT_RNSt16remove_referenceIS2_E4typeE
                Address: 0x3a6586170            Ordinal: 51             Function: _ZSt9addressofIKcEPT_RS1_
                Address: 0x3a6586190            Ordinal: 52             Function: _ZSt9addressofIcEPT_RS0_
                Address: 0x3a65861b0            Ordinal: 53             Function: _ZStaNRSt13_Ios_FmtflagsS_
                Address: 0x3a65861e0            Ordinal: 54             Function: _ZStanSt13_Ios_FmtflagsS_
                Address: 0x3a6586200            Ordinal: 55             Function: _ZStcoSt13_Ios_Fmtflags
                Address: 0x3a6586210            Ordinal: 56             Function: _ZStoRRSt13_Ios_FmtflagsS_
                Address: 0x3a6586240            Ordinal: 57             Function: _ZStorSt13_Ios_FmtflagsS_
                Address: 0x3a6586260            Ordinal: 58             Function: _ZnwyPv
                Address: 0x3a65834e0            Ordinal: 59             Function: edata
                Address: 0x3a6581c90            Ordinal: 60             Function: header
                Address: 0x3a65814f0            Ordinal: 61             Function: idata
                Address: 0x3a65813a3            Ordinal: 62             Function: pathfile
                Address: 0x3a6583fb9            Ordinal: 63             Function: symbol

Module: 
Base: 0x3a6580000
Size: 323584 bytes
Loaded:
Type: 4

Name: All
Address: 0x3a6581380
Size: 35 bytes

Name: pathfile
Address: 0x3a65813a3
Size: 333 bytes

Name: idata
Address: 0x3a65814f0
Size: 1952 bytes

Name: header
Address: 0x3a6581c90
Size: 3088 bytes

Name: PrintOptionalHeader
Address: 0x3a65828a0
Size: 2620 bytes

Name: OptionalHeader
Address: 0x3a65832dc
Size: 516 bytes

Name: edata
Address: 0x3a65834e0
Size: 2777 bytes

Name: symbol
Address: 0x3a6583fb9
Size: 5175 bytes

Name: ZN9__gnu_cxx11char_traitsIcE4copyEPcPKcy
Address: 0x3a65853f0
Size: 144 bytes

Name: ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_is_localEv
Address: 0x3a6585480
Size: 96 bytes

Name: ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv
Address: 0x3a65854e0
Size: 48 bytes

Name: ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv
Address: 0x3a6585510
Size: 16 bytes

Name: ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv
Address: 0x3a6585520
Size: 32 bytes

Name: ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv
Address: 0x3a6585540
Size: 32 bytes

Name: ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6lengthEv
Address: 0x3a6585560
Size: 32 bytes

Name: ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv
Address: 0x3a6585580
Size: 32 bytes

Name: ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8capacityEv
Address: 0x3a65855a0
Size: 64 bytes

Name: ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8max_sizeEv
Address: 0x3a65855e0
Size: 48 bytes

Name: ZNSt11char_traitsIcE4copyEPcPKcy
Address: 0x3a6585610
Size: 112 bytes

Name: ZNSt11char_traitsIcE6assignERcRKc
Address: 0x3a6585680
Size: 64 bytes

Name: ZNSt15__new_allocatorIcE10deallocateEPcy
Address: 0x3a65856c0
Size: 48 bytes

Name: ZNSt15__new_allocatorIcE8allocateEyPKv
Address: 0x3a65856f0
Size: 96 bytes

Name: ZNSt19__ptr_traits_ptr_toIPKcS0_Lb0EE10pointer_toERS0_
Address: 0x3a6585750
Size: 32 bytes

Name: ZNSt19__ptr_traits_ptr_toIPccLb0EE10pointer_toERc
Address: 0x3a6585770
Size: 32 bytes

Name: ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_destroyEy
Address: 0x3a6585790
Size: 160 bytes

Name: ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv
Address: 0x3a6585830
Size: 64 bytes

Name: ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_capacityEy
Address: 0x3a6585870
Size: 32 bytes

Name: ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC1EPcOS3_
Address: 0x3a6585890
Size: 80 bytes

Name: ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD1Ev
Address: 0x3a65858e0
Size: 32 bytes

Name: ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv
Address: 0x3a6585900
Size: 48 bytes

Name: ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEy
Address: 0x3a6585930
Size: 80 bytes

Name: ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv
Address: 0x3a6585980
Size: 16 bytes

Name: ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_
Address: 0x3a6585990
Size: 592 bytes

Name: ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEPc
Address: 0x3a6585be0
Size: 32 bytes

Name: ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_S_copyEPcPKcy
Address: 0x3a6585c00
Size: 80 bytes

Name: ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_
Address: 0x3a6585c50
Size: 256 bytes

Name: ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERyy
Address: 0x3a6585d50
Size: 288 bytes

Name: ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_lengthEy
Address: 0x3a6585e70
Size: 32 bytes

Name: ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev
Address: 0x3a6585e90
Size: 160 bytes

Name: ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
Address: 0x3a6585f30
Size: 48 bytes

Name: ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSERKS4_
Address: 0x3a6585f60
Size: 48 bytes

Name: ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_
Address: 0x3a6585f90
Size: 112 bytes

Name: ZSt11__addressofIKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEPT_RS7_
Address: 0x3a6586000
Size: 16 bytes

Name: ZSt11__addressofIKcEPT_RS1_
Address: 0x3a6586010
Size: 16 bytes

Name: ZSt11__addressofIcEPT_RS0_
Address: 0x3a6586020
Size: 16 bytes

Name: ZSt12construct_atIcJRKcEEDTgsnwcvPvLi0E_T_pispcl7declvalIT0_EEEEPS3_DpOS4_
Address: 0x3a6586030
Size: 80 bytes

Name: ZSt12setprecisioni
Address: 0x3a6586080
Size: 16 bytes

Name: ZSt21is_constant_evaluatedv
Address: 0x3a6586090
Size: 16 bytes

Name: ZSt23__is_constant_evaluatedv
Address: 0x3a65860a0
Size: 16 bytes

Name: ZSt3decRSt8ios_base
Address: 0x3a65860b0
Size: 48 bytes

Name: ZSt3hexRSt8ios_base
Address: 0x3a65860e0
Size: 48 bytes

Name: ZSt4moveIRSaIcEEONSt16remove_referenceIT_E4typeEOS3_
Address: 0x3a6586110
Size: 16 bytes

Name: ZSt4setwi
Address: 0x3a6586120
Size: 16 bytes

Name: ZSt5fixedRSt8ios_base
Address: 0x3a6586130
Size: 48 bytes

Name: ZSt7forwardIRKcEOT_RNSt16remove_referenceIS2_E4typeE
Address: 0x3a6586160
Size: 16 bytes

Name: ZSt9addressofIKcEPT_RS1_
Address: 0x3a6586170
Size: 32 bytes

Name: ZSt9addressofIcEPT_RS0_
Address: 0x3a6586190
Size: 32 bytes

Name: ZStaNRSt13_Ios_FmtflagsS_
Address: 0x3a65861b0
Size: 48 bytes

Name: ZStanSt13_Ios_FmtflagsS_
Address: 0x3a65861e0
Size: 32 bytes

Name: ZStcoSt13_Ios_Fmtflags
Address: 0x3a6586200
Size: 16 bytes

Name: ZStoRRSt13_Ios_FmtflagsS_
Address: 0x3a6586210
Size: 48 bytes

Name: ZStorSt13_Ios_FmtflagsS_
Address: 0x3a6586240
Size: 32 bytes

Name: ZnwyPv
Address: 0x3a6586260
Size: 0 bytes
```
