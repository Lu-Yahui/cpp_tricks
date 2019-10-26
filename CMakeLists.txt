cmake_minimum_required(VERSION 3.0)
project(cpp_tricks)

set(CMAKE_CXX_FLAGS "-std=c++11")

add_executable(perfect_forwarding 
    modern_cpp_features/perfect_forwarding.cpp
)