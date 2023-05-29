import pytest
import subprocess
from os import path
# 有时需要详细写明这种include方式

# run the pytest:

# python3 - m pytest - s test_mc.py
#

# python3 - m pytest - rA test_mc.py
# report All


def test_mc():
    inputfile_content = """get temperature"""

    expected_read_content = """
{
    "cmds" : [
    {"ID": 102, "length":0 , "value": "" },
    ]
}
"""

    input_filename = "input.txt"
    output_filename = "output.txt"
    print(inputfile_content)

    with open(input_filename, "w") as fd:
        fd.write(inputfile_content)

    mc_filename = path.join(
        path.curdir,
        "../..",
        "build/main_component/main_component"
    )

    # 如果您-s在运行 Pytest 时已经在使用该选项并且您仍然在控制台输出中看到b'\n'，
    # 则可能是print()您的测试函数中的语句没有正确处理二进制数据。
    # 这时可以使用decode如下这种方式

    with open(output_filename, "w") as fd:  # ???
        read_output = fd.read()

    mc_process = subprocess.run(
        args=[mc_filename, input_filename, output_filename],
        capture_output=True
    )

    captured_output = mc_process.stdout.decode()
    print(captured_output)

    read_output = ""

    with open(output_filename) as fd:  # ???
        read_output = fd.read()

    print(f'_{read_output}_')
    print(f'_{expected_read_content}_')

    assert read_output == expected_read_content


# print one . per test case


# def test_fika():
#    assert True


# def help_func(arg):
#    return arg
# to check if the pytest take as a test case or not. (not a case as it should be not)


# def test_fail():
#    assert False == False
