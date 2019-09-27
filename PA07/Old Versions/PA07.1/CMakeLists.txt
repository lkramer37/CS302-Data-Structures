cmake_minimum_required(VERSION 3.7)
project(PA07)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        BSTree.h
        config.h
        database.cpp
        show9.cpp
        test9.cpp BSTree.cpp)

add_executable(PA07 ${SOURCE_FILES})