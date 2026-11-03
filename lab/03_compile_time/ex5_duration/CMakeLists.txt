cmake_minimum_required(VERSION 3.22)
project(lab_03_compile_time_ex5_duration LANGUAGES CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/lab.cmake)

add_executable(duration_tests tests/test_duration_literal.cpp)
target_include_directories(duration_tests PRIVATE src)
target_link_libraries(duration_tests PRIVATE GTest::gtest_main)
gtest_discover_tests(duration_tests)
