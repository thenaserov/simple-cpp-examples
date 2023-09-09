#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string s("This is a large string containing some numbers like 408 and (382), it also contains some phone numbers like (919) 936-8585, 117-332-1019 and +9022425483. These should all match, but ignore our lone linke 433-0988 and (281)2121 since those are not phone numbers.");
    std::cmatch matcher;

    std::regex allPhoneNumbers(R"delim()");
    return 0;
}