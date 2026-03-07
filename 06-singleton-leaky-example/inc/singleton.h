#pragma once

class Singleton {
public:
    Singleton(const Singleton&) = delete;            /* Deleted copy constructor. */
    Singleton& operator=(const Singleton&) = delete; /* Deleted copy assigment operator. */

    static Singleton& getInstance() {
        /* Static local variable is thread safe >= C++11 */
        static Singleton* instance = new Singleton();
        return *instance;
    }

    void info();

private:
    Singleton();
    ~Singleton(); // This will NEVER be called
};