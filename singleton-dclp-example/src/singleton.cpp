#include "singleton.h"
#include <iostream>

Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mtx;


Singleton& Singleton::getInstance() {
    if (!instance)
    {
        std::lock_guard<std::mutex> lock(mtx);
        if (!instance)
        {
            instance = new Singleton();
        }
    }
    return *instance;
}

void Singleton::delInstance() {
    if (instance)
    {
        std::lock_guard<std::mutex> lock(mtx);
        if (instance)
        {
            delete instance;
            instance = nullptr;
        }
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