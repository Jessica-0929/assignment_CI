import json

file_name = "min_signals"
file_path = "CAN_MESSAGE.json"

with open(file_path) as json_file:
    signals_content_raw = json_file.read()
    json_dict = json.loads(signals_content_raw)


def generate_source_function_get(file_name):
    output_string = ""
    output_string = '#include "../include/can_message/min_signals.h"\n'
    output_string += "#include <sstream>\n\n"
    output_string += "CAN_{}::CAN_{}() {{\n".format(file_name, file_name)
    can_id = json_dict["id"]
    output_string += "\tm_startMsgId = {};\n".format(can_id)
    num = len(list(json_dict["signals"]))
    print(num)

    i = 2
    for element in json_dict["signals"]:
        can_name = element["name"]
        print(can_name)
        output_string += "\tm_{}GetMsgId = m_startMsgId + {}; \n".format(
            can_name, i)
        output_string += "\tm_{}SetMsgId = m_startMsgId + {} + 1;\n".format(
            can_name, i)
        i += 2
    output_string += "};\n"

    for element in json_dict["signals"]:
        can_name = element["name"]
        can_type = element["type"]
        can_length = element["length"]
        output_string += "std::string CAN_{}::get_{}() {{ \n".format(file_name, can_name)
        output_string += "\tstd::stringstream sstream; \n"
        output_string += '\tsstream << "{{\\"ID\\": " << + m_{}GetMsgId\n'.format(
            can_name)
        output_string += '\t\t\t<< ", \\"length\\":0 "\n'
        output_string += '\t\t\t<< ", \\"value\\": \\"\\" }";\n'
        output_string += "\treturn sstream.str();\n"
        output_string += "}\n"
        output_string += "std::string CAN_{}::set_{}({} newValue) {{\n".format(
            file_name, can_name, can_type)
        output_string += "\tstd::stringstream sstream;\n"
        output_string += '\tsstream << "{{\\"ID\\": " << + m_{}SetMsgId\n'.format(
            can_name)
        output_string += '\t\t\t<< ", \\"length\\":{} "\n'.format(can_length)
        output_string += '\t\t\t<< ", \\"value\\":\\""\n'
        output_string += '\t\t\t<< + newValue\n'
        output_string += '\t\t\t<< "\\"}";\n'
        output_string += "\treturn sstream.str();\n"
        output_string += "}\n"
    return output_string


def generate_header_function_get(file_name):
    output_string = ""
    output_string += "#ifndef HEADER_{}_H\n" .format((file_name).upper())
    output_string += "#define HEADER_{}_H\n\n" .format((file_name).upper())
    output_string += "#include <string>\n"
    output_string += "class CAN_{} {{\n" .format(file_name)
    output_string += "\tpublic:\n"
    output_string += "\t\tCAN_{}();\n" .format(file_name)
    for element in json_dict["signals"]:
        can_name = element["name"]
        can_type = element["type"]
        output_string += "\t\tstd::string get_{}();\n".format(can_name)
        output_string += "\t\tstd::string set_{}({} newValue);\n".format(
            can_name, can_type)
    output_string += "\tprivate:\n"
    output_string += "\t\tuint8_t m_startMsgId;\n"
    for element in json_dict["signals"]:
        can_name = element["name"]
        output_string += "\t\tuint8_t m_{}GetMsgId;\n".format(can_name)
        output_string += "\t\tuint8_t m_{}SetMsgId;\n".format(can_name)
    output_string += "};\n"
    output_string += "#endif\n"
    return output_string


if __name__ == "__main__":

    header = generate_header_function_get(file_name)
    print(header)
    with open("./output/include/can_message/min_signals.h", "w") as output_file_fd:
        output_file_fd.write(header)
    source = generate_source_function_get(file_name)
    print(source)
    with open("./output/src/min_signals.cpp", "w") as output_file_fd:
        output_file_fd.write(source)


# can_message/min_signals.h
# header should only like this
