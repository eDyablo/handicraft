add_executable(mzn
  cntclstrs/test.cpp
  ctflms/test.cpp
  fvstrslrs/test.cpp
  tmsncntrs/test.cpp
)

target_link_libraries(mzn googlemock googletest googletest-main)
