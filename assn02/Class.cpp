#include <iostream>
#include <string>

#include "Class.h"

using namespace std;

Class::Class(){
//	static int no_count = 0;
//	no_count ++;
//	no = no_count;
//	score1 = score2 = score3 = 0;
    cout << "Class created\n";
}


void Class::input_info(){
    string buff;
    cout << "Input name[8]" << endl;
    cin >> buff;
    if (buff.size() <= 8 && buff.size() >= 1) {
        //Student *p = new Student(buff);
		//hisStuList.add(*p);
		Student temp(buff);
		temp.input_info();
		hisStuList.add(temp);
    }
    else{
        cout << "Illeagal Input, return to main menu." << endl;
    }
}

void Class::print_info(){
	ListNode<Student> *p = hisStuList.getHead();
	hisStuList.getHead()->read_info().print_info();
	while ((p = hisStuList.getNext(p))){
		p->read_info().print_info();
	}
}

//int Class::get_info(int course_no){
//    switch (course_no) {
//        case 0:return score1;break;
//        case 1:return score2;break;
//        case 2:return score3;break;
//        default:            break;
//    }
//    return 0;
//}

//void Class::input_course(){
//
//}

Class::~Class(){
    
}