#include <iostream>
#include "singleton.h"

/*
* Meyer’s Singleton - Example with static local variable
* Static memory allocation
* Lazy initialization
* Singleton is created only after first call of getInstance() and destroyed after main() call
* Thread-safe - Thread safety is guaranteed since C++11. A function-local static variable is initialized exactly once, even in a multi-threaded environment.
*/

int main()
{
	std::cout << "--- main start ---" << std::endl;

	Singleton::getInstance().func();

	std::cout << "--- main end ---" << std::endl;
}