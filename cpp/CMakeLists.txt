cmake_minimum_required (VERSION 3.7.2)
project (sudoku-solver)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(sudoku-solver ${SOURCES})
