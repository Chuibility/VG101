cmake_minimum_required(VERSION 3.5)
project(reversi)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES reversi.c)
add_executable(reversi ${SOURCE_FILES})