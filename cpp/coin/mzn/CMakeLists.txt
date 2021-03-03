add_executable(mzn tmsncntrs/solution_test.cpp scene_partitioning_test.cpp)

target_link_libraries(mzn googlemock googletest googletest-main)
