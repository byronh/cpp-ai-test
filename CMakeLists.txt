cmake_minimum_required(VERSION 2.8.4)
project(cpp_ai)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

add_definitions(
    -std=c++11
)

add_subdirectory(engine)
add_subdirectory(game)
