cmake_minimum_required(VERSION 3.26)
project(ADT_AVLTree C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ADT_AVLTree
        AVLTree.c
        AVLTree.h
        test.c)
