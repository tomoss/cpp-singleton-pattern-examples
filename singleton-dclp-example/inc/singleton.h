#pragma once

#include <mutex>

class Singleton {
public:
    Singleton(Singleton& other) = delete; /* Deleted copy constructor. */
    Singleton& operator=(const Singleton&) = delete; /* Deleted copy assigment operator. */

    static Singleton& getInstance();
    static void delInstance();

    void func();

private:
    Singleton();
    ~Singleton();
    static Singleton* instance;
    static std::mutex mtx;
};