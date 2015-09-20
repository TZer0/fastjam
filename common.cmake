unset(SRC_LIST)

aux_source_directory(./engine SRC_LIST)

if (${WIN32})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DWINDOWS")
aux_source_directory(SDL2/src SRC_LIST)
aux_source_directory(SDL2/src/event SRC_LIST)
aux_source_directory(SDL2/src/render/opengl SRC_LIST)
include_directories(SDL2/include)
include_directories(SDL2/include/SDL)
endif()
