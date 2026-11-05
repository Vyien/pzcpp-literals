cmake_minimum_required(VERSION 3.22)
project(lab_02_udl_ex2_angle LANGUAGES CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/lab.cmake)

add_executable(angle_tests tests/test_angle_literals.cpp)
# src/ holds the file you edit; ../src/ holds the shared unit types
target_include_directories(angle_tests PRIVATE src ../src)
target_link_libraries(angle_tests PRIVATE GTest::gtest_main)
gtest_discover_tests(angle_tests)
