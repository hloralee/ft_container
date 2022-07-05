cmake_minimum_required(VERSION 3.19)
project(ft_container)

set(CMAKE_CXX_STANDARD 98)

add_executable(ft_container test.cpp include/map.hpp include/utils/bidirectional_iterator.hpp)
