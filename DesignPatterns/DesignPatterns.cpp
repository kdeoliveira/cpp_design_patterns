// DesignPatterns.cpp : Defines the entry point for the application.
//

#include "DesignPatterns.hpp"


int main()
{
#if ONDEBUG
	std::cout << "In debug mode" << std::endl;
#endif

#if CXX_WIN
	std::cout << "Windows" << std::endl;
#else
	std::cout << "Linux" << std::endl;
#endif
	return 0;
}
