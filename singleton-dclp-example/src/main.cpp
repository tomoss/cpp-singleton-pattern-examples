#include "singleton.h"
#include <iostream>
#include <thread>
#include <vector>

/*
 * Example with DOUBLE-CHECKED LOCKING PATTERN (DCLP)
 * Dynamic memory allocation
 * Lazy initialization
 * Singleton is created only after first call of getInstance() and destroyed by calling delInstance()
 * DCLP is designed to add efficient thread-safety to initialization of a shared resource (such as a Singleton), but it has a problem: it’s not reliable
 * DCLP can fail for different reasons: Multiple threads can read instance concurrently,
 * and since instance is a raw pointer with no memory ordering guarantees, this is a data race and triggers undefined behavior in C++.
 * This pattern (Double-Checked Locking) was obsoleted by C++11.
 * https://www.aristeia.com/Papers/DDJ_Jul_Aug_2004
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
