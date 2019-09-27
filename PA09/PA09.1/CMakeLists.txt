cmake_minimum_required(VERSION 3.7)
project(PA09_1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        config.h
        Heap.cpp
        Heap.h
        heapsort.cpp
        ossim.cpp
        PriorityQueue.cpp
        PriorityQueue.h
        test11.cpp
        test11hs.cpp
        test11pq.cpp)

add_executable(PA09_1 ${SOURCE_FILES})