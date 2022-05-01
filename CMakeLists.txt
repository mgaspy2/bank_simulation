cmake_minimum_required(VERSION 3.22)
project(VCP_Bank_simulation)

set(CMAKE_CXX_STANDARD 23)

add_executable(VCP_Bank_simulation main.cpp Account.cpp Account.h Bank.cpp Bank.h Currency.h)
