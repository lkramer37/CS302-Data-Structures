cmake_minimum_required(VERSION 3.7)
project(PA07_5)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        BSTree.cpp
        BSTree.h
        config.h
        show9.cpp
        test9.cpp)

add_executable(PA07_5 ${SOURCE_FILES})