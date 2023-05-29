CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

PROJECT(PoC) # proof of concept

#set(SourcesLib lib/scr/file_io.cpp)
#set(SourcesApp app/src/test.cpp)

#include_directories(lib/include)

add_subdirectory(file_io)
add_subdirectory(can_message)

message(STATUS "Generated Include path = ${CAN_INCLUDE_DIR}, sources = ${CAN_SOURCES}")

add_subdirectory(main_component)