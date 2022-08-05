cmake_minimum_required(VERSION 3.10)

project(brainfuck)

set(CMAKE_CXX_FLAGS "-std=c++17 -msse4.2 -Wall -Wextra -O3 -g")

include_directories(.)

set(HEADERS
    instructions/instructions.h

    lexer.h
    parser.h

    statement.h
    statement/statement.h
    statement/decrement_cell.h
    statement/decrement_ptr.h
    statement/get_char.h
    statement/increment_cell.h
    statement/increment_ptr.h
    statement/loop.h
    statement/put_char.h

    token.h
)

set(SOURCES
    instructions/instructions.cpp

    lexer.cpp
    parser.cpp

    statement/statement.cpp
    statement/decrement_cell.cpp
    statement/decrement_ptr.cpp
    statement/get_char.cpp
    statement/increment_cell.cpp
    statement/increment_ptr.cpp
    statement/loop.cpp
    statement/put_char.cpp

    token.cpp
)

add_executable(brainfuck main.cpp ${HEADERS} ${SOURCES})