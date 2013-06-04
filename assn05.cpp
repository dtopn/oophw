#include <iostream>
#include <string>

#include "Class.h"

using namespace std;

void print_menu(){
	    cout << "Choose an action" << endl <<
            "[1]Show Class info" << endl <<
            "[2]Add Student to a class" << endl <<
            "[3]Undefined" << endl <<
            "[0]Exit" << endl;
}

int main(){
    Class aClass;
    char buff;
    while (1) {
		print_menu();
		cin >> buff;
        switch (buff) {
			case '1': aClass.print_info();	break;
            case '2': aClass.input_info();	break;//add student names to class
			case '3': //aClass.input_course();break;
			case '0': return 0;
            default: cout << "Illeagal input." << endl; break;
        }
    }
}


