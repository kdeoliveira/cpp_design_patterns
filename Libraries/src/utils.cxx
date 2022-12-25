#include "lib.hpp"


namespace Lib{
	extern "C" SHARED_EXPORT int square(A&);

	int square(A& a) {
		return a.getX()*a.getX();
	}
}

