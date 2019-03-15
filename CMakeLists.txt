cmake_minimum_required(VERSION 3.13)

set(This Morse)

project(${This} CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(PortAudio REQUIRED)

set(Headers
    src/morse.hpp
    src/sine.h
)
set(Sources
    src/morse.cpp
    src/main.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)