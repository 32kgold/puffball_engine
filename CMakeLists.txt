cmake_minimum_required(VERSION 3.29)
project(PuffballEngine)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(modules)
add_subdirectory(core)

add_executable(PuffballEngine main.cpp)
