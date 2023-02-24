cmake_minimum_required(VERSION 3.23)
project(thaotacchuot)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(thaotacchuot
        framework.h
        Resource.h
        targetver.h
        thaotacchuot.cpp
        thaotacchuot.h)
