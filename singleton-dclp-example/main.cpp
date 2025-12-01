#include <iostream>
#include <future>
#include "singleton.h"

/*
* Singleton with Double-Checked Locking - static pointer member variable
* Dynamic memory allocation
* Lazy initialization
* Singleton is created only after first call of getInstance() and destroyed by calling delInstance()
* DCLP is designed to add efficient thread-safety to initialization of a shared resource (such as a Singleton), but it has a problem: it’s not reliable
* DCLP can fail for different reasons
* https://www.aristeia.com/Papers/DDJ_Jul_Aug_2004_revised.pdf
* Multiple threads can read instance concurrently, and since instance is a raw pointer with no memory ordering guarantees, 
* this is a data race and triggers undefined behavior in C++.
* A pattern (Double-Checked Locking) that was obsoleted by C++11.
*/

int main()
{
    std::cout << "--- main start ---" << std::endl;

    Singleton::getInstance().func();

    auto async1 = std::async(std::launch::async, []() {
            Singleton::getInstance().func();
    });

    auto async2 = std::async(std::launch::async, []() {
            Singleton::getInstance().func();
    });

    async1.wait();
    async2.wait();

    Singleton::delInstance();

    std::cout << "--- main end ---" << std::endl;
}
