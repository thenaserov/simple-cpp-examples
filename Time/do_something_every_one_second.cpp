#include <iostream>
#include <chrono>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

// TheNaserov
int main() {
	auto start = std::chrono::steady_clock::now();
	while (true) {
		auto end = std::chrono::steady_clock::now();
		auto diff = end - start;
		if (std::chrono::duration_cast<std::chrono::seconds>(diff).count() >= 1) {
			std::cout << "doing sth" << std::endl;
			start = std::chrono::steady_clock::now();
		}
	}
	return 0;
}

// This is the worst way to do so!
