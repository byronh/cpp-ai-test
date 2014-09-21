find_package(SFML COMPONENTS graphics window system REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/engine/include ${SFML_INCLUDE_DIRS} )

link_directories(${CMAKE_BINARY_DIR}/engine)

add_executable(main main.cpp)
target_link_libraries(main engine ${SFML_LIBRARIES})
