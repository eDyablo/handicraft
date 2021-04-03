cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(handicraft)

add_subdirectory(googletest)

include_directories(
    "googletest/googlemock/include"
    "googletest/googletest/include")

add_subdirectory(coin)
add_subdirectory(spanchart)

add_subdirectory(sfml)
add_subdirectory(game)
