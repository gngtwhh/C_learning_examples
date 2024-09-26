cmake_minimum_required(VERSION 3.26)
project(ATD_LinkedQueue C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ATD_LinkedQueue
        LinkedQueue.c
        LinkedQueue.h
        main.c)
