
include_directories(${CMAKE_SOURCE_DIR}/engine/include)
include_directories(${CMAKE_SOURCE_DIR}/game/include)

link_directories(${CMAKE_BINARY_DIR}/engine)

file(GLOB_RECURSE game_code
    ${CMAKE_SOURCE_DIR}/game/main.cpp
	${CMAKE_SOURCE_DIR}/game/src/*.cpp
)

add_executable(main ${game_code})
target_link_libraries(main engine)
