cmake_minimum_required(VERSION 3.22)
project(lab_02_udl_ex1_distance LANGUAGES CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/lab.cmake)

add_executable(distance_tests tests/test_distance_literals.cpp)
# src/ holds the file you edit; ../src/ holds the shared unit types
target_include_directories(distance_tests PRIVATE src ../src)
target_link_libraries(distance_tests PRIVATE GTest::gtest_main)
gtest_discover_tests(distance_tests)
