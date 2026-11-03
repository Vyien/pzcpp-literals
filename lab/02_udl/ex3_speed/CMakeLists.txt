cmake_minimum_required(VERSION 3.22)
project(lab_02_udl_ex3_speed LANGUAGES CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/lab.cmake)

add_executable(speed_tests tests/test_speed.cpp)
# src/ holds the file you edit; ../src/ holds the shared unit types
target_include_directories(speed_tests PRIVATE src ../src)
target_link_libraries(speed_tests PRIVATE GTest::gtest_main)
gtest_discover_tests(speed_tests)
