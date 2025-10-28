cmake_minimum_required(VERSION 3.31)
project(Tag2_04Template)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tag2_04Template main.cpp
        processor/AbstractFileprocessor.h
        processor/CharacterCounter.h
        processor/LineCounter.h)
