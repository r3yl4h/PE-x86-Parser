cmake_minimum_required(VERSION 3.28)
project(Pe_x86_parser)

set(CMAKE_CXX_STANDARD 23)
set(DIA_SDK_PATH "C:/Program Files/Microsoft Visual Studio/2022/Professional/DIA SDK")
include_directories("${DIA_SDK_PATH}/include")

add_executable(Pe_x86_parser main.cpp
        parser.cpp
        exp.hpp
        x32/header_pe.cpp
        x64/header_pe.cpp
        x64/importT.cpp
        section_pe.cpp
        symbols.cpp
        x32/importT.cpp
        x64/exportT.cpp
        x32/exportT.cpp
)

target_link_libraries(Pe_x86_parser PRIVATE dbghelp ${LLVM_LIBS})