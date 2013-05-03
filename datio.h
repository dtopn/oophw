#include "dtype.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
using std::getline;
#include <map>
using std::map;

typedef map<long int, string> DAT;

extern int odat(char *a);
extern int idat(char *a);

extern int iparse(DAT &da);
extern int oparse(DAT da);


template <typename T> int ostd(const T a) {
	cout << a;
    return 0;
}

template <typename T> int istd(T &a) {
	cin >> a;
    return 0;
}
