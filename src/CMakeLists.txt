cmake_minimum_required(VERSION 3.5)

project(src VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(IS_DEBUG_BUILD CMAKE_BUILD_TYPE STREQUAL "Debug")

# Indication to the code that this is a debug build
if (${IS_DEBUG_BUILD})
    add_compile_definitions(__DEBUG__)
endif ()

add_executable(src cpu.cpp cpu.h memory_ram.cpp memory_ram.h opcodes.h aliases.h main.cpp)

install(TARGETS src
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
