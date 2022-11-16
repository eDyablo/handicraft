cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(epc)

file(GLOB test_sources
  "*_test.cpp"
)

add_executable(epc ${test_sources})

target_link_libraries(epc gmock gtest gtest_main)
