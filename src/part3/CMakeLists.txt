cmake_minimum_required(VERSION 3.22)
project(part3)

set(CMAKE_CXX_STANDARD 14)

include_directories(inc)

add_executable(part3
        inc/dijkstra.h
        inc/graph.h
        inc/hauler.h
        inc/mission.h
        inc/siteconfiguration.h
        src/dijkstra.cpp
        src/graph.cpp
        src/main.cpp
        src/mission.cpp
        src/siteconfiguration.cpp)
