cmake_minimum_required(VERSION 3.5)
project(cube-tc-imba)

set(CMAKE_C_COMPILER gcc)

set(SOURCE_FILES cube.c)
add_executable(cube-tc-imba ${SOURCE_FILES})