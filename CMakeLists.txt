cmake_minimum_required(VERSION 3.30)
project(mbss)

set(CMAKE_CXX_STANDARD 23)

find_package(toml11 REQUIRED)

add_executable(mbss main.cpp
        input.hpp
        Constraint.hpp
        output.hpp
        RigidBody.hpp)

target_link_libraries(mbss toml11::toml11)