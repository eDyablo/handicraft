file(GLOB test_sources
  "*/test.cpp"
)

add_executable(mzn ${test_sources})

target_link_libraries(mzn gmock gtest gtest_main)
