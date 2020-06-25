cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 17)

project(spanchart VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(ntrvlmp SHARED span_chart_test.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
