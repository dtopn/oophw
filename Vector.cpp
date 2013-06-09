#include "Vector.h"

#include <iostream>

using std::cerr;

void IndexOutofBounds::diagnostic() {
	cerr << "index " << m_badValue
		<< "out of range!"; 
}
