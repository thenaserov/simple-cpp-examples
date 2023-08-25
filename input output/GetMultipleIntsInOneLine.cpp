// Get multiple integers as input
#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::vector< int >arr;
    std::string input;
    std::getline(std::cin, input);
    std::istringstream is(input);
    int num;
    while (is >> num) arr.push_back(num);
    for (auto d : arr) {
        std::cout << d << std::endl;
    }
    return 0;
}