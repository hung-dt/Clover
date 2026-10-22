#------------------------------------------------------------------------------
#   Author: HungDT
#   Date  : 2020-08-25
#
#   Main CMake project file
#------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.23.0)

#------------------------------------------------------------------------------
# Prohibit in-source build

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
    message(FATAL_ERROR
        "DO NOT build in-source!!!\n"
        "Please remove CMakeCache.txt and the CMakeFiles/ directory. Then build out-of-source.")
endif()

project(Clover
    VERSION 0.0.1
    DESCRIPTION "Game Engine Clover in C++"
    LANGUAGES C CXX)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

#------------------------------------------------------------------------------
# Import cmake modules
#------------------------------------------------------------------------------

# include(ClangFormat)
# include(CppCheck)

#------------------------------------------------------------------------------
# Fix for C++23 support for MinGW:
# Starting with GCC 14, features like C++23 <print>/std::println, <stacktrace>,
# experimental C++ Modules (import std;), and C++26 Contracts are bundled inside
# libstdc++exp.a. Because MinGW uses GCC, it requires this library to resolve
# undefined references during compilation.

if(WIN32 AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_STANDARD_LIBRARIES "${CMAKE_CXX_STANDARD_LIBRARIES} -lstdc++exp")
endif()

#------------------------------------------------------------------------------
# External libraries/packages

add_subdirectory(extern)

#------------------------------------------------------------------------------
# Other project's CMakeLists.txt
#------------------------------------------------------------------------------

add_subdirectory(Clover)
add_subdirectory(Sandbox)

# examples
if (BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

# tests
if (BUILD_TESTS)
    add_subdirectory(tests)
endif()
