cmake_minimum_required(VERSION 3.21)
project(ft_container)

set(CMAKE_CXX_STANDARD 98)

add_executable(ft_container main.cpp main.cpp test/test_vector.cpp include/vector.hpp)
