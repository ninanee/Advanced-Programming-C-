cmake_minimum_required(VERSION 3.19)
project(5421A4)

set(CMAKE_CXX_STANDARD 14)

add_executable(5421A4 ShapeTest-Driver.cpp Shape.cpp Shape.h Rectangle.cpp Rectangle.h Rhombus.cpp Rhombus.h Triangle.cpp Triangle.h AcuteTriangle.cpp AcuteTriangle.h RightTriangle.cpp RightTriangle.h Canvas.cpp Canvas.h)