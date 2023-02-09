project(samples)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory("produce_and_consume")
add_subdirectory("shared_mutex")
add_subdirectory("threading")
add_subdirectory("type_erasure")
