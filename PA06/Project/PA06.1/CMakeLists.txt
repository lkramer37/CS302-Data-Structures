cmake_minimum_required(VERSION 3.7)
project(PA06_1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        config.h
        ExpressionTree.cpp
        ExpressionTree.h
        show8.cpp
        test8.cpp)

add_executable(PA06_1 ${SOURCE_FILES})