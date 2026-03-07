#include "singleton.h"
#include <iostream>

/*
 * Example with static member variable
 * Static memory allocation
 * Eager initialization
 * Singleton is created before main() and destroyed after main() call
 * Initialization is thread-safe - The static member is initialized before main() in a single-threaded context, so no construction race is possible.
 * The Static Initialization Order Fiasco - If the singleton instance is accessed during the initialization of another static object.
 */

int main() {
    std::cout << "--- main start ---" << std::endl;

    Singleton::getInstance().func();

    std::cout << "--- main end ---" << std::endl;
}