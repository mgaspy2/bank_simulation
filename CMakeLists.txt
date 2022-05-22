cmake_minimum_required(VERSION 3.22)
project(VCP_Bank_simulation)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(VCP_Bank_simulation
        Account.cpp
        Account.h
        Bank.cpp
        Bank.h
        Currency.h
        main.cpp)
