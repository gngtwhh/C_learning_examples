cmake_minimum_required(VERSION 3.27)
project(ADT_AdjacencyList C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ADT_AdjacencyList
        AdjacencyList.c
        AdjacencyList.h
        test.c)
