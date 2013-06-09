#include <iostream>
#include "Vector.h"

using namespace std;

int main () {
	

	Vector<int> v_i;
	Vector<int> v_i20(20);
	
	cout << "Assign value to v_i20:\n";
	for (int i = 0; i < v_i20.size(); i++) {
		v_i20[i] = i;
	}
	
	cout << "Assign value to v_i and exception throwed:" << char(10);
	try {
		for (int i = 0; i < v_i20.size(); i++) {
			v_i[i] = i;
		}
	}
	catch (...) {cout << "Exception happened\n";}

	try {
		cout << "Inflate v_i to 20\n";
		v_i.inflate(20);
		cout << "Assign value to v_i(inflated)\n";
		for (int i = 0; i < v_i20.size(); i++) {
			v_i[i] = i;
		}
	}
	catch (...) {cout << "Exception happened\n";}

	try {	
		cout << "Inflate to 30 elements\n";
		v_i20.inflate(10);
		for (int i = 0; i < v_i20.size(); i++) {
			v_i20[i] = 30 - i;
		}
	}	
	catch (...) {cout << "Exception happened\n";}

	try {
		cout << "Copy and print all elements\n";
		Vector<int> v_cp(v_i20);
		for (int i = 0; i < v_cp.size(); i++) {
			cout << v_cp[i] << ' ';
		}
	}
	catch (...) {cout << "Exception happened\n";}
	

	return 0;
}
