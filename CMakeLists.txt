cmake_minimum_required(VERSION 3.23)
project(MatrixCalculator2_0)

set(CMAKE_CXX_STANDARD 17)

add_executable(MatrixCalculator2_0 main.cpp Controller/Controller.cpp Controller/Controller.h Calculator/Calculator.cpp Calculator/Calculator.h Matrix/Matrix.cpp Matrix/Matrix.h)
