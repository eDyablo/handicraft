cmake_minimum_required(VERSION 3.5)
project(app VERSION 1.0.0 LANGUAGES CXX)
add_executable(app src/main.cpp)
set_target_properties(app PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY /usr/bin/app
)
target_link_libraries(app PUBLIC -static)
