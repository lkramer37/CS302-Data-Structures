cmake_minimum_required(VERSION 3.8)
project(PA07_2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        BSTree.cpp
        BSTree.h
        config.h
        database.cpp
        show9.cpp
        test9.cpp)

add_executable(PA07_2 ${SOURCE_FILES})