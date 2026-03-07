#include "singleton.h"
#include <iostream>
#include <syncstream>
#include <thread>

Singleton::Singleton() {
    std::cout << "Singleton created." << std::endl;
}

void Singleton::info() {
    std::osyncstream(std::cout) << "Current instance address: " << this << " | Current thread ID: " << std::this_thread::get_id() << '\n';
}

Singleton::~Singleton() {
    std::cout << "Singleton destroyed." << std::endl;
}