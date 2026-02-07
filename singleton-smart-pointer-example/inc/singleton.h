#pragma once

class Singleton {
public:
    Singleton(const Singleton&) = delete;            /* Deleted copy constructor. */
    Singleton& operator=(const Singleton&) = delete; /* Deleted copy assigment operator. */

    static Singleton& getInstance();
    void func();
    ~Singleton();

private:
    Singleton();
};