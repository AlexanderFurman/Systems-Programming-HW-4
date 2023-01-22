cmake_minimum_required(VERSION 3.21)
project(HW4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Cards)
include_directories(Players)

add_executable(HW4
        utilities.cpp
        utilities.h
        Cards/Card.cpp
        Cards/Card.h
        Cards/Barfight.cpp
        Cards/Barfight.h
        Cards/Battle.cpp
        Cards/Battle.h
        Cards/Dragon.cpp
        Cards/Dragon.h
        Cards/Gremlin.cpp
        Cards/Gremlin.h
        Cards/Mana.cpp
        Cards/Mana.h
        Cards/Merchant.cpp
        Cards/Merchant.h
        Cards/Treasure.cpp
        Cards/Treasure.h
        Cards/Well.cpp
        Cards/Well.h
        Cards/Witch.cpp
        Cards/Witch.h
        Players/Healer.cpp
        Players/Healer.h
        Players/Ninja.cpp
        Players/Ninja.h
        Players/Player.cpp
        Players/Player.h
        Players/Warrior.cpp
        Players/Warrior.h
        Exception.h
        Mtmchkin.cpp
        Mtmchkin.h
        test.cpp
        main.cpp
        )
