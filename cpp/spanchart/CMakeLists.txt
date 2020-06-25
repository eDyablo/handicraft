cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 17)

project(spanchart VERSION 0.1.0)

add_library(spanchart SHARED span_chart_test.cpp)
