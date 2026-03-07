#include "singleton.h"
#include <iostream>
#include <syncstream>
#include <thread>

Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mtx;

Singleton& Singleton::getInstance() {
    if (!instance) {
        std::lock_guard<std::mutex> lock(mtx);
        if (!instance) {
            instance = new Singleton();
        }
    }
    return *instance;
}

void Singleton::delInstance() {
    if (instance) {
        std::lock_guard<std::mutex> lock(mtx);
        if (instance) {
            delete instance;
            instance = nullptr;
        }
    }
}

Singleton::Singleton() {
    std::cout << "Singleton created." << std::endl;
}

void Singleton::info() {
    std::osyncstream(std::cout) << "Current instance address: " << this << " | Current thread ID: " << std::this_thread::get_id() << '\n';
}

Singleton::~Singleton() {
    std::cout << "Singleton destroyed." << std::endl;
}