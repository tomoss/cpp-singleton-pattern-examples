#include "singleton.h"
#include <iostream>
#include <thread>
#include <vector>

/*
 * Meyer’s Singleton - Example with STATIC LOCAL VARIABLE
 * Static memory allocation
 * Lazy initialization
 * Singleton is created only after first call of getInstance() and destroyed after main() call
 * Thread-safe - Thread safety is guaranteed since C++11.
 * A function-local static variable is initialized exactly once, even in a multi-threaded environment.
 * This is the best and simplest way to implement a singleton in C++11 and later.
 */

int main() {
    std::cout << "--- main start ---" << std::endl;

    std::vector<std::thread> threads;

    // Launch 10 threads
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back([]() { Singleton::getInstance().func(); });
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "--- main end ---" << std::endl;
}