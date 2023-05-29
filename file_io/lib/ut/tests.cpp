#include <gtest/gtest.h>

/*
A task: Top write a function, which simplifies a full phone number:
-removes acode of the country (+46, +10, +1, +91 .etc)
-removes possible dashes (999-999-99  -> 99999999)
-removes spaces in between numbers (99 99  ->  9999)
*/
std::string SimplifyPhoneNumber(std::string phoneNumber)
{
    if (phoneNumber.empty())
    {
        return "ERROR";
    }
    return phoneNumber.substr(1);
}

TEST(PhoneNumberChecks, InputIsNotOutput)
{
    std::string fakeNumber("+50 11 999 12-34");
    std::string expectedNumber("0119991234");
    std::string output = SimplifyPhoneNumber(fakeNumber);
    EXPECT_NE(fakeNumber, output);
}

TEST(PhoneNumberChecks, ReturnErrorOnEmptyString)
{
    std::string fakeNumber("");
    std::string expectedResult("ERROR");
    std::string output = SimplifyPhoneNumber(fakeNumber);
    EXPECT_EQ(output, expectedResult);
}