#include "singleton.h"
#include <iostream>

/*
 * Example with STATIC MEMBER VARIABLE
 * Static memory allocation
 * Eager initialization
 * Singleton is created before main() and destroyed after main() call
 * Thread-safety not guaranteed
 */

int main() {
    std::cout << "--- main start ---" << std::endl;

    Singleton::getInstance().func();

    std::cout << "--- main end ---" << std::endl;
}