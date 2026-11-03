cmake_minimum_required(VERSION 3.22)
project(lab_03_compile_time_ex4_color LANGUAGES CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/lab.cmake)

add_executable(color_tests tests/test_color_literal.cpp)
target_include_directories(color_tests PRIVATE src)
target_link_libraries(color_tests PRIVATE GTest::gtest_main)
gtest_discover_tests(color_tests)
