include(common.cmake)
aux_source_directory(./test SRC_LIST)
aux_source_directory(./common SRC_LIST)

add_executable(testing ${SRC_LIST})
