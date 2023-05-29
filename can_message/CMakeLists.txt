execute_process(


#add_custom_target(
   # generate_sources_from_json  #define name
    COMMAND "python3" "generate_cpp.py" #define command
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} 
    #name which folder we want to build, and also contains CMakeLists
    # 这段代码定义了两个变量CAN_INCLUDE_DIR和CAN_SOURCES，并将它们的值设置为相应的路径。这些变量可能会在项目的其他地方使用。
    # CAN_INCLUDE_DIR变量指定了包含C++头文件的目录路径，而CAN_SOURCES变量指定了C++源代码文件的路径。
)

set(CAN_INCLUDE_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/output/include 
    PARENT_SCOPE)
set(CAN_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/output/src/min_signals.cpp
    PARENT_SCOPE)
    # PARENT_SCOP 表示将这些变量的作用域扩展到父级（上层）的CMakeLists.txt文件，以便其他子目录或项目可以访问这些变量。
