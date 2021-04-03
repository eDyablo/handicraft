cmake_minimum_required(VERSION 3.0.0)

project(sldwnd-test)

add_executable(sldwnd-test sliding_window_test.cpp)

target_link_libraries(sldwnd-test gmock gtest gtest_main)
