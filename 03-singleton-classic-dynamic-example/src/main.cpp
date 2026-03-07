#include "singleton.h"
#include <iostream>

/*
 * Example with static member pointer
 * Dynamic memory allocation
 * Lazy initialization
 * Singleton is created only after first call of getInstance() and destroyed by calling delInstance()
 * Not Thread-safe
 */

int main() {
    std::cout << "--- main start ---" << std::endl;

    Singleton::getInstance().info();
    Singleton::getInstance().info();
    Singleton::delInstance();

    std::cout << "--- main end ---" << std::endl;
}