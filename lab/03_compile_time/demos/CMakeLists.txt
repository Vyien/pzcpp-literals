cmake_minimum_required(VERSION 3.22)
project(lab_03_compile_time_demos LANGUAGES CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/lab.cmake)

# Tests of the percent literal: they build and pass
add_executable(percent_tests percent_test.cpp)
target_link_libraries(percent_tests PRIVATE GTest::gtest_main)
gtest_discover_tests(percent_tests)

# Fails to compile on purpose (150_pct is rejected by the consteval literal),
# so it is not part of the default build. Build it explicitly:
#   cmake --build build --target percent_compile_error
add_executable(percent_compile_error EXCLUDE_FROM_ALL compile_error.cpp)
