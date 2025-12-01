#include <iostream>
#include "singleton.h"

/*
* Example with STATIC MEMBER VARIABLE
* Dynamic memory allocation
* Lazy initialization
* Singleton is created only after first call of getInstance() and destroyed by calling delInstance()
* Thread-safety not guaranteed
*/

int main()
{
    std::cout << "--- main start ---" << std::endl;

    Singleton::getInstance().func();
    Singleton::getInstance().func();
    Singleton::delInstance();

    std::cout << "--- main end ---" << std::endl;
}