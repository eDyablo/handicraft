file(GLOB test_sources
  "*/test.cpp"
)

add_executable(prstrg ${test_sources})

target_link_libraries(prstrg gmock gtest gtest_main)
