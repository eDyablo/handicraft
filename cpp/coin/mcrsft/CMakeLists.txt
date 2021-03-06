add_executable(mcrsft
  test.cpp
  qstnmrkrdl/solution_test.cpp
)

target_link_libraries(mcrsft googlemock googletest googletest-main)
