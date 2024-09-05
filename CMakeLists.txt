cmake_minimum_required(VERSION 3.8)
project(Pe_x86_parser)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories("C:/Program Files/Microsoft Visual Studio/2022/Professional/DIA SDK/include")

add_executable(Pe_x86_parser
    "src/main.cpp"
    "src/parser.cpp"
    "src/exp.hpp"
    "src/x32/header_pe.cpp"
    "src/x64/header_pe.cpp"
    "src/section_pe.cpp"
    "src/symbols.cpp"
    "src/import_table.cpp"
    "src/export_table.cpp"
)

target_link_libraries(Pe_x86_parser PRIVATE dbghelp)

