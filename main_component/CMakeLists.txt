set(SOURCES src/main.cpp)

include_directories(${CAN_INCLUDE_DIR})
include_directories(${FILE_IO_INCLUDE_DIR})

add_executable(main_component ${SOURCES} ${CAN_SOURCES})

# it tells to CMake to build the target "generate_sources_from_json" BEFORE "main component" 
# add_dependencies(main_component generate_sources_from_json)

target_link_libraries(main_component file_io_lib)
# file_io ??