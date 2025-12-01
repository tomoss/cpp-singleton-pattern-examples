#include "singleton.h"
#include <iostream>

/* it's private to this file */
static Singleton* instance = nullptr;

Singleton& Singleton::getInstance() {
    if (!instance) {
        instance = new Singleton(); 
    }
    return *instance;
}

void Singleton::delInstance() {
    if (instance) {        
        delete instance;
        instance = nullptr;
    }
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


