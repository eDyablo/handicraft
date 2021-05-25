file(GLOB test_sources
  "*/test.cpp"
)

add_executable(dtrt ${test_sources})

target_link_libraries(dtrt gmock gtest gtest_main)
