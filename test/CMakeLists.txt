cmake_minimum_required(VERSION 3.21)
project(google_test)

set(CMAKE_CXX_STANDARD 98)

add_subdirectory(google_test)
include_directories(google_test/googletest/include)
add_executable(google_test test_vector.cpp)
target_link_libraries(google_test gtest gtest_main)
