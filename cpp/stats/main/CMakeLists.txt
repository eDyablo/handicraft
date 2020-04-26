cmake_minimum_required(VERSION 3.7.2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(stats VERSION 0.1.0 LANGUAGES CXX)

add_executable(stats stats.cpp)

target_link_libraries(stats PUBLIC)
