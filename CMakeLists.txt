cmake_minimum_required(VERSION 3.30)
project(mbss)

set(CMAKE_CXX_STANDARD 23)

add_compile_options(-std=c++23 -Wall -O2)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

aux_source_directory(./src SRC_LIST)

include_directories(./inc)

add_executable(mbss src/main.cpp)
