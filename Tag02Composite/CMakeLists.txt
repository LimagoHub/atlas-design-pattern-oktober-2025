cmake_minimum_required(VERSION 3.31)
project(Tag02Composite)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tag02Composite main.cpp
        composite/AbstractNode.h
        composite/Leaf.h
        composite/Node.h)
