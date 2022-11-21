cmake_minimum_required(VERSION 3.22)
project(5LIG0_AS1)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/part1/inc)

add_executable(5LIG0_AS1
        src/part1/inc/mission.h
        src/part1/inc/siteconfiguration.h
        src/part1/src/main.cpp
        src/part1/src/mission.cpp
        src/part1/src/siteconfiguration.cpp)
