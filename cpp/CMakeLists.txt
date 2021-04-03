cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(handicraft)

add_library(googletest googletest/googletest/src/gtest-all.cc)
target_include_directories(googletest PRIVATE googletest/googletest)
target_include_directories(googletest PUBLIC googletest/googletest/include)

add_library(googlemock googletest/googlemock/src/gmock-all.cc)
target_include_directories(googlemock PRIVATE googletest/googletest/include)
target_include_directories(googlemock PRIVATE googletest/googlemock)
target_include_directories(googlemock PUBLIC googletest/googlemock/include)

add_library(googletest-main googletest/googletest/src/gtest_main.cc)
target_include_directories(googletest-main PRIVATE googletest/googletest)
target_include_directories(googletest-main PUBLIC googletest/googletest/include)

add_subdirectory(coin)
add_subdirectory(spanchart)

add_subdirectory(sfml)
add_subdirectory(game)
add_subdirectory(lark)
