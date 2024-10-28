cmake_minimum_required(VERSION 3.29)
project(Ecosystem_Simulation)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(Ecosystem_Simulation
        main.cpp
        main.h)
