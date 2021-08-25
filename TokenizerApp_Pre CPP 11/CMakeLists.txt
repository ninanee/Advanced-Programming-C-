cmake_minimum_required(VERSION 3.19)
project(Asg1)

set(CMAKE_CXX_STANDARD 11)

add_executable(Asg1 main.cpp TokenizerApp.cpp TokenizerApp.h IntList.cpp IntList.h Token.cpp Token.h TList.cpp TList.h)
add_executable(IntList IntList.cpp)
add_executable(Token Token.cpp)