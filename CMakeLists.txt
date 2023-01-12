cmake_minimum_required(VERSION 3.21)
project(HW3_clion)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Systems-Programming-HW-4
        Mtmchkin.h
        test.cpp
        utilities.cpp
        utilities.h)