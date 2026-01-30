cmake_minimum_required(VERSION 4.0)
project(EventLogerBST)

set(CMAKE_CXX_STANDARD 20)

add_executable(EventLogerBST main.cpp
        Event/Event.cpp
        Event/Event.h
        Event/BSTLog.cpp
        Event/BSTLog.h
        Event/Node.cpp
        Event/Node.h)
