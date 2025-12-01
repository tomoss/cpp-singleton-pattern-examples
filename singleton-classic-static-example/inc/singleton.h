#pragma once
#include <iostream>

class Singleton
{
public:
    Singleton(const Singleton&) = delete; /* Deleted copy constructor. */
    Singleton& operator=(const Singleton&) = delete; /* Deleted copy assigment operator. */

    static Singleton& getInstance() {
        return instance;
    }

    void func();
    ~Singleton();

private:
    Singleton();
    static Singleton instance; /* Declared static instance as member variable. */
};