cmake_minimum_required(VERSION 3.10)

# project name
project(CI)

set(CMAKE_CXX_STANDARD 17)

add_executable(i main.cpp token.cpp lox.cpp scanner.cpp)
