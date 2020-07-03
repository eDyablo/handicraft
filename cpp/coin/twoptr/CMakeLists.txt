cmake_minimum_required(VERSION 3.0.0)

project(twoptr-test)

add_executable(twoptr-test two_pointers_test.cpp)

target_link_libraries(twoptr-test googlemock googletest googletest-main)
