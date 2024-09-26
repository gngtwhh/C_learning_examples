cmake_minimum_required(VERSION 3.26)
project(ADT_BinaryTree C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ADT_BinaryTree
        BinaryTree.c
        BinaryTree.h
        test.c)
