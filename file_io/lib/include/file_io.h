#ifndef FILE_IO
#define FILE_IO

#include <iostream>
#include <filesystem>
#include <list>
#include <string>

class file_io
{

public:
    file_io();

    ~file_io();

    std::string readLine(std::string filename);

    std::list<std::string> readLines(std::string filename);

    void writeLine(std::string filename, std::string data_line);

    void writeLines(std::string filename, std::list<std::string> content);
};

#endif