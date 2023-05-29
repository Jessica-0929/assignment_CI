// #include "../../file_io/lib/include/file_io.h"
// #include <can_message/min_signals.h>
#include <iostream>
#include "file_io.h"
#include <can_message/min_signals.h>
#include <algorithm>
#include <cstring>
#include <vector>

void print_json_file(const std::list<std::string> list_string)
{
    file_io file;
    CAN_min_signals signal;
    std::string json_filename = "output.json"; // can save in varaiable, pass by argument

    file.writeLine(json_filename, "{\n\t[");

    for (std::string itr : list_string)
    // for (std::list<std::string>::iterator itr = list_string.begin(); itr != list_string.end(); itr++)
    {

        // take the keyword from each line, split the string by " "/space.
        // to get the keyword
        std::cout << itr << std::endl;
        std::string str = itr;
        char *s = new char[str.size() + 1];
        strcpy(s, str.c_str());
        char *p = strtok(s, " ");
        std::vector<std::string> words;
        while (p)
        {
            words.push_back(p);
            p = strtok(NULL, " ");
        }

        // get words[1] 无法识别？？？
        if (words[0] == "get")
        {
            std::cout << "words[1] is " << words[1] << std::endl;
            if (words[1] == "humidity")
            {
                std::string returned_string = "\t\t" + signal.get_humidity() + ",";
                file.writeLine(json_filename, returned_string);
            }

            else if (words[1] == "temperature")
            {
                std::string returned_string = "\t\t" + signal.get_temperature() + ",";
                file.writeLine(json_filename, returned_string);
            }

            else
            {
                file.writeLine(json_filename, "not match --get");
            }
        }

        else if (words[0] == "set")
        {
            if (words[1] == "humidity")
            {
                // int u_value = std::stoi(words[2]);
                uint8_t u_value = std::stoul(words[2]) & 0xFF;
                std::string returned_string = "\t\t" + signal.set_humidity(u_value) + ",";

                file.writeLine(json_filename, returned_string);
            }

            else if (words[1] == "temperature")
            {
                // int u_value = std::stoi(words[2]);
                float f_value = std::stof(words[2]);
                std::string returned_string = "\t\t" + signal.set_temperature(f_value) + ",";

                file.writeLine(json_filename, returned_string);
            }

            else if (words[1] == "stop_signal_light")
            {
                file.writeLine(json_filename, "\t\tset stop_signal_light enabled"); // or anything???
            }

            else
            {
                file.writeLine(json_filename, "not match -- set");
            }
        }

        else
        {
            file.writeLine(json_filename, "not match word[1]");
        }
    }
    file.writeLine(json_filename, "\t]\n}");
}

int main(int argc, char *argv[])
{

    file_io file;
    std::string filename = "./test_cmds.txt";

    std::string return_line;

    return_line = file.readLine(filename);

    std::list<std::string> list_string = file.readLines(filename);

    print_json_file(list_string);

    return 0;
}