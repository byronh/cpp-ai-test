
include_directories(${CMAKE_SOURCE_DIR}/engine/include )

link_directories(${CMAKE_BINARY_DIR}/engine)

add_executable(main main.cpp)
target_link_libraries(main engine)
