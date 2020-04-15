cmake_minimum_required(VERSION 3.5)
project(app VERSION 1.0.0 LANGUAGES CXX)
add_executable(calc src/main.cpp)
set_target_properties(calc PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY /usr/bin/calc
)
target_link_libraries(calc PUBLIC -static)
