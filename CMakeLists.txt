cmake_minimum_required(VERSION 3.28)
project(Word_Hunt_Solver)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Word_Hunt_Solver
        main.cpp
        Trie.h)
