cmake_minimum_required(VERSION 3.31)
project(data_structures)

set(CMAKE_CXX_STANDARD 20)

add_executable(data_structures
        dsa/linkedList.h
        dsa/linkedList.cpp

        dsa/stack.h

        dsa/queue.h

        dsa/map.h

        main.cpp
)
