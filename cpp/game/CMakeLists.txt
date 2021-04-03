configure_file(texture/wrinkled-paper/O5GLLH0.jpg texture/wrinkled-paper COPYONLY)

add_executable(game main.cpp)

target_link_libraries(game
    sfml-graphics
    sfml-system
    sfml-window
)
