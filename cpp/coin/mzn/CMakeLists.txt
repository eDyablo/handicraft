add_executable(mzn
  fvstrslrs/solution_test.cpp
  scene_partitioning_test.cpp
  tmsncntrs/solution_test.cpp
)

target_link_libraries(mzn googlemock googletest googletest-main)
