cmake_minimum_required(VERSION 3.16)
project(gamaclox C)

set(CMAKE_C_STANDARD 11)

add_executable(gamaclox main.c common.h chunk.h chunk.c memory.c memory.h debug.c debug.h value.h value.c line.c line.h vm.c vm.h compiler.c compiler.h scanner.c scanner.h)