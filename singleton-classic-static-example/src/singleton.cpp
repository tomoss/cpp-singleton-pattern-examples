#include "singleton.h"
#include <iostream>

Singleton Singleton::instance;

Singleton::Singleton() {
    std::cout << "Singleton created." << std::endl;
}

void Singleton::func() {
    std::cout << "Doing something..." << std::endl;
}

Singleton::~Singleton() {
    std::cout << "Singleton destroyed." << std::endl;
}