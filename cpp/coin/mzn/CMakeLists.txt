add_executable(mzn
  cntclstrs/solution_test.cpp
  ctflms/solution_test.cpp
  fvstrslrs/solution_test.cpp
  tmsncntrs/solution_test.cpp
)

target_link_libraries(mzn googlemock googletest googletest-main)
