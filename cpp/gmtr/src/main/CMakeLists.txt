cmake_minimum_required(VERSION 3.7.2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(gmtrm VERSION 0.1.0 LANGUAGES CXX)

add_executable(gmtrm main.cxx)

set_target_properties(gmtrm PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${gmtr_BINARY_DIR}/bin"
)

target_link_libraries(gmtrm PUBLIC)
