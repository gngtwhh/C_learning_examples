cmake_minimum_required(VERSION 3.26)
project(ADT_String C)

set(CMAKE_C_STANDARD 11)

add_executable(ADT_String main.c
        String.c
        String.h)
