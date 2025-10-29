cmake_minimum_required(VERSION 3.31)
project(Tag02Composite)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tag02Composite main.cpp
        composite/AbstractBankNode.h
        composite/Konto.h
        composite/KontoGruppe.h)
