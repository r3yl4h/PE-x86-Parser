cmake_minimum_required(VERSION 3.27)
project(neyPe64_parser)

set(CMAKE_CXX_STANDARD 23)


add_executable(neyPe64_parser
        main.cpp
        header.cpp
        importMod.cpp
        exportMod.cpp
        cns.cpp
        Symbol.cpp
        peh.hpp
)

target_link_libraries(neyPe64_parser PRIVATE dbghelp)
set_target_properties(neyPe64_parser PROPERTIES OUTPUT_NAME "ney")

