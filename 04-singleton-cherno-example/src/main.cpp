#include "singleton.h"
#include <iostream>

/*
 * Example from Cherno with static global variable in cpp file
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