cmake_minimum_required(VERSION 3.15)
project(the_game_of_live)

set(CMAKE_CXX_STANDARD 14)

set(LINK_DIR D:/CLionProjects/the_game_of_live/lib)
link_directories(${LINK_DIR})
link_libraries(EasyXa.lib)
link_libraries(EasyXw.lib)

add_executable(the_game_of_live main.cpp cells.cpp cells.h)

target_link_libraries(the_game_of_live EasyXa.lib)
target_link_libraries(the_game_of_live EasyXw.lib)