// DesignPatterns.cpp : Defines the entry point for the application.
//

#include "DesignPatterns.hpp"



using namespace std;

int main()
{
#if ONDEBUG
	cout << "In debug mode" << endl;
#endif

#if CXX_WIN
	cout << "Windows" << endl;
#endif
	return 0;
}
