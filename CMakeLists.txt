cmake_minimum_required(VERSION 3.27)
project(untitled1 C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled1
        lexer.h
        lexer.c
        main.c
        lex.yy.c
)
