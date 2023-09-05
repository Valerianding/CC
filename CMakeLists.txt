cmake_minimum_required(VERSION 3.5)
project(cc)

# C++ 17 standard support
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# clang-10
set(CMAKE_CXX_COMPILER clang)

#include_directories
include_directories(src)


#all of C++ source files
file(GLOB_RECURSE SOURCES src/*.cpp LIST_DIRECTORIES true)

add_executable(mc ${SOURCES})

## why need to manually linke stdc++???
target_link_libraries(mc stdc++)