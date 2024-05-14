#include <iostream>
#include <chrono>
#include <thread> // Include the thread library for sleep functions

int main() {
    auto start = std::chrono::steady_clock::now();
    while (true) {
        auto end = std::chrono::steady_clock::now();
        auto diff = end - start;
        if (std::chrono::duration_cast<std::chrono::seconds>(diff).count() >= 1) {
            std::cout << "doing sth" << std::endl;
            start = std::chrono::steady_clock::now();
        }
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Sleep for 1 second
    }
    return 0;
}
