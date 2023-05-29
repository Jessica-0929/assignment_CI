cmake_minimum_required(VERSION 3.10)

project(myProject)

# tell CMake to search for header files in lib/include folder
include_directories(lib/include)
set(FILE_IO_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/include PARENT_SCOPE)

set(SourcesLib lib/src/file_io.cpp)       # because file_io.cpp in lib folder
set(SourcesApp app/src/test.cpp)          # test.cpp in app folder

# tell CMake to build a library form source code
add_library(file_io_lib ${SourcesLib})            # because of set

# this is our application 
add_executable(application ${SourcesApp})        # because of set

# link our library to an executable file
target_link_libraries(application file_io_lib)


#include CMake module to be able to download GoogleTest code.
include(FetchContent)

# Declare git repo and tag to fetch:
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.0
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

#Download or check that googletest is downloaded:
FetchContent_MakeAvailable(googletest)

# Build our Unit Tests
add_executable(lib_ut_tests lib/ut/tests.cpp lib/ut/ut_lib_tests.cpp)
target_link_libraries(lib_ut_tests gtest gtest_main file_io_lib) 

#add_executable(lib_ut_tests lib/ut/tests.cpp)
#target_link_libraries(lib_ut_tests gtest gtest_main) 


# or file_io??
