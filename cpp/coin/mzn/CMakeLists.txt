file(GLOB test_sources
  "*/test.cpp"
)

add_executable(mzn ${test_sources})

target_link_libraries(mzn googlemock googletest googletest-main)
