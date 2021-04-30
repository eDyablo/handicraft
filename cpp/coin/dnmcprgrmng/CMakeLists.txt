file(GLOB test_sources
  "*/test.cpp"
)

add_executable(dnmcprgrmng ${test_sources})

target_link_libraries(dnmcprgrmng gmock gtest gtest_main)
