file(GLOB test_sources
  "*/test.cpp"
)

add_executable(tr ${test_sources})

target_link_libraries(tr gmock gtest gtest_main)
