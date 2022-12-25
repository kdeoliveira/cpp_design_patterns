// DesignPatterns.cpp : Defines the entry point for the application.
//

#include "DesignPatterns.hpp"
#include "Crtp.hpp"

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

	Idioms::MyFunctionality* myFunc = new Idioms::MyFunctionality(2);

	std::cout << "CRTP:" << std::endl;
	myFunc->scale(2);
	std::cout << "scale by 2: " << myFunc->getValue() <<  std::endl;

	myFunc->setToOpposite();
	std::cout << "setToOpposite: " << myFunc->getValue() << std::endl;

	myFunc->square();
	std::cout << "square: " << myFunc->getValue() << std::endl;
	return 0;
}
