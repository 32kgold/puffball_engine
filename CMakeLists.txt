cmake_minimum_required(VERSION 3.29)
project(PuffballEngine)

add_subdirectory(modules)
add_subdirectory(core)

add_executable(PuffballEngine main.cpp)
