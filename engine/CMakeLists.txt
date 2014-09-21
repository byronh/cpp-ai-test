file(GLOB_RECURSE engine_code
	src/*.cpp
)

add_library(engine ${engine_code})
