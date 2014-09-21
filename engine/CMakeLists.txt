find_package(SFML COMPONENTS graphics window system REQUIRED)

include_directories(include ${SFML_INCLUDE_DIRS})

link_directories(${SFML_LIBRARIES})

file(GLOB_RECURSE engine_code
	src/*.cpp
)

add_library(engine ${engine_code})
target_link_libraries(engine ${SFML_LIBRARIES})
