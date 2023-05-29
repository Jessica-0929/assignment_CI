import json


def wrtie_output(filename, data):
    with open(filename, "w") as file_fd:
        file_fd.writeline(data)


def generage_include_guard_class_decl_ctor(file_name):
    top = []  # empty list, include guard, class declaration and constructor
    bottom = ""  # empty string, ending of include guard
    return top, bottom


def generate_source_function_get(file_name, json_dict):
    output_string = ""
    output_string = '#include "./output/include/can_message/min_signals.h"\n'
    output_string += "#include <sstream>\n\n"
    output_string += "CAN_{}::CAN_{}() {{\n".format(file_name, file_name)
    can_id = json_dict["id"]
    output_string += "\tm_startMsgId = {};\n".format(can_id)
    num = len(list(json_dict["signals"]))

    for i, element in zip([1, num], json_dict["signals"]):

        can_name = element["name"]
        output_string += "\tm_{}GetMsgId = m_startMsgId + {}; \n".format(
            can_name, 2*i)
        output_string += "\tm_{}SetMsgId = m_startMsgId + {} + 1;\n".format(
            can_name, 2*i)
    output_string += "};\n"

    for element in json_dict["signals"]:
        can_name = element["name"]
        can_type = element["type"]
        can_length = element["length"]
        output_string += "std::string CAN_{}::get_{}() {{ \n".format(file_name, can_name)
        output_string += "\tstd::stringstream sstream; \n"
        output_string += '\tsstream << "{{\\"ID\\": " << m_{}GetMsgId\n'.format(
            can_name)
        output_string += '\t\t\t<< ", \\"length\\":0 "\n'
        output_string += '\t\t\t<< ", \\"value\\": \\"\\" }";\n'
        output_string += "\treturn sstream.str();\n"
        output_string += "}\n"
        output_string += "std::string CAN_{}::set_{}({} newValue) {{\n".format(
            file_name, can_name, can_type)
        output_string += "\tstd::stringstream sstream;\n"
        output_string += '\tsstream << "{{\\"ID\\": " << m_{}GetMsgId\n'.format(
            can_name)
        output_string += '\t\t\t<< ", \\"length\\":{} "\n'.format(can_length)
        output_string += '\t\t\t<< ", \\"value\\":\\"\n'
        output_string += '\t\t\t<< newValue\n'
        output_string += '\t\t\t<< \\"}";\n'
        output_string += "\treturn sstream.str();\n"
        output_string += "}\n"
    return output_string


def generate_header_function_get(file_name):
    output_string = ""
    # += good to be used to same type of data / easy convertable type,
    # if not, should use .append(not care about the type in Python
    #
    #
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

    input_filename = "min_signals"
    # can be argument or variable
    json_dict = {}
    with open(input_filename) as file_fd:
        json_raw_content = file_fd.read()
        json_dict = json.loads(json_raw_content)
    print(json_dict)
    json_filename = input_filename.replace(
        ".json", "")   # get the name from the file
    print(json_filename)

    header_content = generate_header_function_get(json_filename, json_dict)
    # TODO: create a string with filename for a header
    # TODO: create a string with filename for a source file

    file_path = "CAN_MESSAGE.json"

    with open(file_path) as json_file:
        signals_content_raw = json_file.read()
        json_dict = json.loads(signals_content_raw)
    # json_dict = json.load(json_file) two ways

    header = generate_header_function_get(file_name)
    print(header)
    with open("./output/include/can_message/min_signals.h", "w") as output_file_fd:
        output_file_fd.write(header)
    source = generate_source_function_get(file_name)
    print(source)
    with open("min_signals.cpp", "w") as output_file_fd:
        output_file_fd.write(source)
