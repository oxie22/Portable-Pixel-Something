cmake_minimum_required(VERSION 3.20.0)
project(portable-pixel-something)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(shake-ppm
    src/main.cpp
    src/image.h
    src/image.cpp
    src/filter.h
    src/filter.cpp
)
