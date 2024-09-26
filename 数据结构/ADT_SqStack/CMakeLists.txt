cmake_minimum_required(VERSION 3.26)
project(ADT_SqStack C)

set(CMAKE_C_STANDARD 11)

add_executable(ADT_SqStack main.c
        SqStack.c
        SqStack.h)
