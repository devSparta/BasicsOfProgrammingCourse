cmake_minimum_required(VERSION 3.23)
project(libs C)

set(CMAKE_C_STANDARD 99)

add_executable(libs main.c dataStructures/vector/vector.c dataStructures/vector/vector.h)

add_library(dataStructures
        dataStructures/vector/vector.c
        )