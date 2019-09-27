cmake_minimum_required(VERSION 3.7)
project(PA08)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        BSTree.cpp
        BSTree.h
        HashTable.cpp
        HashTable.h
        test10.cpp
        )

add_executable(PA08 ${SOURCE_FILES})