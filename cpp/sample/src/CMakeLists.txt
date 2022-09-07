cmake_minimum_required(VERSION 3.5)
project(sample VERSION 1.0.0 LANGUAGES CXX)
set(BUILD_SHARED_LIBS OFF)
add_subdirectory(googleflags)
add_subdirectory(googlelog)
add_executable(sample sample/main.cpp)
set_target_properties(sample PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY /sample/out
)
target_link_libraries(sample glog::glog gflags::gflags -static)
