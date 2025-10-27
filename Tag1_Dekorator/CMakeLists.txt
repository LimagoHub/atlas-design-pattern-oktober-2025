cmake_minimum_required(VERSION 3.31)
project(Tag1_Dekorator)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tag1_Dekorator main.cpp
        math/CalculatorImpl.h
        client/CalcClient.h
        math/CalculatorLogger.h
        math/CalculatorFactory.h)
