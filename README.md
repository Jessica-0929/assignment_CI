1) Read and write files by using the file_io component.

2) Convert the input data by using the C++ code that generated by Python Sripts in can_messages component.

3) Call the functions in main component.

4) Do the unit test with Google Test and Github Actions and also tried a little bit with Pytest. 


# Can_message component
start with generate_cpp.py: 
a script to generate "./output/include/can_message/min_signals.h" and "./output/src/min_signal.cpp"
these two files used to convert different CAN signals to a JSON string, and return the JSON string

# File_io component
used to read and write on specific file(s)
also did a unit test by google test for this component
production code: lib/include/file_io.h, lib/src/file_io.cpp
unit test: lib/ut/ut_lib_tests.cpp, test.cpp(as the main function)

# Main_component
./commands_biglist.txt is the input data for the whole project
src/main.cpp calls file_io component to read the input data, and convert data to JSON string with can_message component, then output to ./signals_biglist.json file
did the unit test by pytest



With Azure Devops
connect: commit AB#nr
update changes: fixes AB#nr
finish the connected work item: fixed AB#1
