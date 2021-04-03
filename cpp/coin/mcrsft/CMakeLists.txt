add_executable(mcrsft
  qldgtsmprmxsm/test.cpp
  qstnmrkrdl/test.cpp
  cmnmngr/test.cpp
)

target_link_libraries(mcrsft gmock gtest gtest_main)
