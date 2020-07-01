cmake_minimum_required(VERSION 3.0.0)

project(spanchart)

add_executable(spanchart span_chart_test.cpp)

target_link_libraries(spanchart googlemock googletest googletest-main)
