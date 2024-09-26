cmake_minimum_required(VERSION 3.26)
project(C)

set(CMAKE_C_STANDARD 11)

add_executable(BracketMatching
        SqStack.c
        SqStack.h
        main.c)
