#include "singleton.h"
#include <iostream>
#include <thread>
#include <vector>

/*
 * Leaky Singleton - Example with static local pointer
 * Dynamic memory allocation
 * Lazy initialization
 * Singleton is created only after first call of getInstance() and never destroyed.
 * Initialization is Thread-safe - Thread safety is guaranteed since C++11.
 */

int main() {
    std::cout << "--- main start ---" << std::endl;

    std::vector<std::thread> threads;

    // Launch 10 threads
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back([]() { Singleton::getInstance().info(); });
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "--- main end ---" << std::endl;
}