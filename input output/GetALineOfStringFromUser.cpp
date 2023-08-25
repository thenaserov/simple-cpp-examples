// Get a line of input from user in C++
#include <iostream>
#define MAX_LEN 60

int main() {
	char input[MAX_LEN];
	std::cin.getline(input, MAX_LEN);
	std::string input_filtered = input;
	return 0;
}