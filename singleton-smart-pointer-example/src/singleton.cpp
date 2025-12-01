#include "singleton.h"
#include <iostream>
#include <memory>

Singleton& Singleton::getInstance() {
    // The "Magic Static" is thread-safe in C++11.
    static std::unique_ptr<Singleton> instance(new Singleton());
    return *instance;
}

Singleton::Singleton() {
    std::cout << "Singleton created." << std::endl;
}

void Singleton::func() {
    std::cout << "Doing something..." << std::endl;
}

Singleton::~Singleton() {
    std::cout << "Singleton destroyed." << std::endl;
}