#include <iostream>
#include "file_io.h"

int main(void)
{
    file_io file;
    std::string line("I am programmer");
    std::string filename = "test.txt";
    file.writeLine("test.txt", line);

    std::string return_line;
    return_line = file.readLine(filename);

    std::cout << return_line << std::endl;

    // file_io num1("test.txt");
    // if we use out then it prints out "Our group is Zeus" otherwise if we dont use out it prints " I am a programmer".
    //  num1.file_write_string(line.c_str());

    return 0;
}