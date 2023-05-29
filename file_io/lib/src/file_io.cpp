#include <fstream>
#include "file_io.h"

file_io::file_io() {}

file_io::~file_io() {}

std::string file_io::readLine(std::string filename)
{
    std::fstream myFile;
    std::string buf;

    myFile.open(filename, std::ios::in);

    if (!(myFile.is_open()))
    {
        std::cout << "ERROR! Couldn't read the file.." << std::endl;
    }

    else
    {
        while (std::getline(myFile, buf))
        {
            myFile << buf;
        }
        myFile.close();
    }
    return buf;
}
std::list<std::string> file_io::readLines(std::string filename)
{
    std::ifstream data;
    std::list<std::string> content;

    data.open(filename, std::ios::in);

    if (data.is_open())
    {
        char buff[1024] = {0};
        while (data.getline(buff, 1023))
        {
            content.emplace_back(buff);
        }
        data.close();
    }
    else
    {
        std::cout << "Error! Cannot open the file.." << std::endl;
    }
    return content;
}

void file_io::writeLine(std::string filename, std::string data_line)
// write line by line
{
    std::fstream data;
    data.open(filename, std::ios::app);

    if (data.is_open())
    {
        data << data_line << std::endl;
        data.close();
    }
    else
    {
        std::cout << "Error! Cannot open the file.." << std::endl;
    }
}

void file_io::writeLines(std::string filename, std::list<std::string> content)
{
    std::ofstream file;
    file.open(filename, std::ios::out);

    if (file.is_open())
    {
        for (std::string line : content)
        {
            file << line << std::endl;
        }
    }
    else
    {
        std::cout << "Error! Cannot open the file.." << std::endl;
    }
    file.close();
}

/*
3 input values:
1) m_filename
2) the amount of lines         data.size()
3) the lines themselves        std::list<std::string> data

*/

//(void)lines;
/*open file using m_filename variable*/

// for (std::string eachLine : data)
// {
// write operation with eachLine
//}

// close file
