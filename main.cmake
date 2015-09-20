include(common.cmake)
aux_source_directory(. SRC_LIST)

add_executable(game ${SRC_LIST})
