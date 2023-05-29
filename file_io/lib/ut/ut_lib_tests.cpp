#include <gtest/gtest.h>
#include "../include/file_io.h"

TEST(file_io_test, WriteLineToEmptyFile)
{
    file_io file; // file_io class from library

    std::string filename = "file.txt";
    std::string data_line = " google test data line. ";

    file.writeLine(filename, data_line);
    std::string output = file.readLine(filename);

    EXPECT_EQ(data_line, output);

    // more code t write to a file

    // read a file by C++ functions (for example: fread or ifstream)
    // compare the content
}

/*
Rules for a Test Case:
1. Input data (for example: filename, or text written), should be defined as a variable
2. Expected data (for example, text written) shoul be defined as a variable
OR
    read by c/C++ function (ex. fread, ifstream)

3. In the end of the test case (if a file opened via C/C++ function), the file should be closed.
TEST()
{
    // file opened
    // test....
    // file should be closed
}



*/

/* List of test cases to implement:

1. Read line from file, which doesn't exist, throws an Exception
2. Read lines(all content) from file, which doesn't exist,  throws an Exception
3. write line to file, which doesn't exist,  should create a file
4. write line (all content) to file, which doesn't exists, create a file
5. if file exists, write line to file should <...> (1. append, or 2. override)
6. if file exists  write lines (all content) to file should <...> (1. append, or 2. override)
7. if a user provided an empty string for filename -> throw an exception
8. when we have finished to use file_io component, the file should be closed. (we can open it via c++ funcitons)
9. after "read" functions (if file doesn't exist) file should not exist.

*/