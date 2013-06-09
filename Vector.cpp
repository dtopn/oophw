#include "Vector.h"

#include <iostream>

using std::cerr;

void IndexOutofBounds::diagnostic() {
	cerr << "Index " << m_badValue
		<< " out of range"; 
}
