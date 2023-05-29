// #include "../../file_io/lib/include/file_io.h"
// #include <can_message/min_signals.h>
#include <iostream>
#include "file_io.h"
#include <can_message/min_signals.h>
#include <algorithm>
#include <cstring>
#include <vector>

#define FILE "test_cmds.txt"
#define JSON "../main_component/text.json"

std::string parseData_printJson(std::string &data)
{
    CAN_min_signals signal;

    std::string str;
    if (!data.find("set temperature"))
    {
        std::string::size_type pos = data.find(' ', 4);
        str = data.substr(pos);
        str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());
        // str = signal.set_temperature(stoi(str));
        uint8_t u_value = std::stoul(str) & 0xFF;
        str = signal.set_temperature(u_value);
    }
    else if (!data.find("get temperature"))
    {
        str = signal.get_temperature();
    }
    else if (!data.find("set humidity"))
    {
        std::string::size_type pos = data.find(' ', 4);
        str = data.substr(pos);
        str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());
        // str = signal.set_humidity(stoi(str));
        uint8_t u_value = std::stoul(str) & 0xFF;
        str = signal.set_humidity(u_value);
    }
    else if (!data.find("get humidity"))
    {
        str = signal.get_humidity();
    }
    else if (!data.find("get front_sensor_status"))
    {
        str = signal.get_front_sensor_status();
    }
    else if (!data.find("get flow_rate"))
    {
        str = signal.get_flow_rate();
    }
    else if (!data.find("get flow_meter_sensor_status"))
    {
        str = signal.get_flow_meter_sensor_status();
    }
    else if (!data.find("get light_intensity"))
    {
        str = signal.get_light_intensity();
    }
    else if (!data.find("get light_intensity_sensor_status"))
    {
        str = signal.get_light_intensity_sensor_status();
    }
    else if (!data.find("get water_level"))
    {
        str = signal.get_water_level();
    }
    else if (!data.find("get water_level_sensor_status"))
    {
        str = signal.get_water_level_sensor_status();
    }
    else if (!data.find("get soil_moisture"))
    {
        str = signal.get_soil_moisture();
    }
    else
    {
        str = "not match";
    }
    return str;
}
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Sorry, you should call" << std::endl
                  << argv[0] << "input_file output_file" << std::endl;
        return 1;
    }
    std::string input_filename(argv[1]);
    std::string output_filename(argv[2]);

    file_io myFile;
    // std::cout << argv[argc - 1];
    std::list<std::string> myData = myFile.readLines(FILE);
    myFile.writeLine(JSON, "{\n\t\"cmds\" : [");
    for (auto data : myData)
    {
        std::cout << parseData_printJson(data);
        std::string str = "\t\t" + parseData_printJson(data) + ",";
        myFile.writeLine(JSON, str);
    }
    myFile.writeLine(JSON, "\t]\n}");
    return 0;
}
