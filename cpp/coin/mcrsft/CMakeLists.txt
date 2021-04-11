file(GLOB test_sources
  "*/test.cpp"
)

add_executable(mcrsft ${test_sources})

target_link_libraries(mcrsft gmock gtest gtest_main)
