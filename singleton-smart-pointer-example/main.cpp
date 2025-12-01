#include "singleton.h"
#include <iostream>
#include <vector>
#include <thread>

/*
* Singleton with local static unique pointer
* Dynamic memory allocation
* Lazy initialization
* Singleton is created in the first call of getInstance() and destroyed automatically after main() call
* Thread-safety IS guaranteed (C++11+)
*/

int main()
{
    std::cout << "--- main start ---" << std::endl;

    std::vector<std::thread> threads;
    
    // Launch 10 threads
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back([]() {
            Singleton::getInstance().func();
        });
    }
    
    for (auto& t : threads) {
        t.join();
    }

    std::cout << "--- main end ---" << std::endl;
}