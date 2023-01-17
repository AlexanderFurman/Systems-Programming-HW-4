cmake_minimum_required(VERSION 3.21)
project(HW3_clion)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Systems-Programming-HW-4
        Mtmchkin.h
        test.cpp
        utilities.cpp
        utilities.h
        Cards/Card.cpp
        Cards/Card.h
        Cards/Treasure.h
        Cards/Treasure.cpp
        Cards/Merchant.cpp
        Cards/Merchant.h
        Cards/Mana.cpp
        Cards/Mana.h
        Cards/Barfight.cpp
        Cards/Barfight.h
        Cards/Well.cpp
        Cards/Well.h
        Cards/Battle.cpp
        Cards/Battle.h
        Cards/Gremlin.cpp Cards/Gremlin.h Cards/Dragon.cpp Cards/Dragon.h Cards/Witch.cpp Cards/Witch.h)