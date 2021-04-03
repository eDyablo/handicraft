cmake_minimum_required(VERSION 3.0.0)

project(spanchart-test)

add_executable(spanchart-test span_chart_test.cpp)

target_link_libraries(spanchart-test gmock gtest gtest_main)
