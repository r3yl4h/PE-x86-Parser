cmake_minimum_required(VERSION 3.27)
project(neyPe64_parser)

set(CMAKE_CXX_STANDARD 23)
find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})


add_executable(neyPe64_parser
        main.cpp
        header.cpp
        importMod.cpp
        exportMod.cpp
        cns.cpp
        Symbol.cpp
        peh.hpp
)

llvm_map_components_to_libnames(LLVM_LIBS core support)
target_link_libraries(neyPe64_parser PRIVATE dbghelp ${LLVM_LIBS})
set_target_properties(neyPe64_parser PROPERTIES OUTPUT_NAME "ney")

