cmake_minimum_required(VERSION 3.7.2)

project(toolset)

include_directories(src/include)

add_subdirectory(src/cntln)
add_subdirectory(src/cntwrd)
add_subdirectory(src/rvln)
add_subdirectory(src/rvwrd)
add_subdirectory(src/wrdsz)
