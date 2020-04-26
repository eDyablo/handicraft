cmake_minimum_required(VERSION 3.7.2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(rvln VERSION 0.1.0 LANGUAGES CXX)

add_executable(rvln rvln.cpp)

set_target_properties(rvln PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${toolset_BINARY_DIR}/bin"
)

target_link_libraries(rvln PUBLIC)
