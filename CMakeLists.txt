cmake_minimum_required(VERSION 3.24)
project(tic_tac_toe C)

set(CMAKE_C_STANDARD 11)

add_executable(tic_tac_toe main.c communication.c communication.h game.c game.h utility.h)
