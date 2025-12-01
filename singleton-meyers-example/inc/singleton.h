#pragma once

class Singleton {
public:
    Singleton(const Singleton&) = delete; /* Deleted copy constructor. */
    Singleton& operator=(const Singleton&) = delete; /* Deleted copy assigment operator. */

    static Singleton& getInstance() {
        static Singleton instance; /* Static local variable is thread safe >= C++11 */
        return instance;
    }

    void func();
    ~Singleton();

private:
    Singleton();
};