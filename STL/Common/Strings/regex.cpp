#include <iostream>
#include <string>
#include <regex>


int main() {
    std::string s("This is a large string containing some numbers like 408 and (382), it also contains some phone numbers like (919) 936-8585, 117-332-1019 and +9022425483. These should all match, but ignore our lone linke 433-0988 and (281)2121 since those are not phone numbers.");
    std::cmatch matcher;
    // simply you make an object of std::regex and then you use the while below to match your expressions!
    std::regex allPhoneNumbers(R"delim((\+\d{1,3})?[\.\-\)\(]*([0-9]{3})[\.\-\)\(\ ]*([0-9]{3})[\.\-\)\(\ ]*([0-9]{4}))delim");

    while (std::regex_search(s.c_str(), matcher, allPhoneNumbers, std::regex_constants::match_default)) {
        std::cout << "Matches : " << std::endl;
        std::cout << "[ " << matcher[0] << " ]" << std::endl;

        s = matcher.suffix().str();
    }
    return 0;
}