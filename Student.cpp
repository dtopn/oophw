#include <iostream>
#include <list>

#include "Student.h"

using std::cout;
using std::endl;
using std::string;
using std::cin;

Student::Student(){
	
    cout << "Created Student" << endl;
}

Student::Student(const string buff){
	course_no = 0, score_sum = 0;
    cout << "Created Student with name" << endl;
    name = buff;
}

void Student::input_info(){
	cout << "Adding info to Stu\nInput Course name[8] and score\nuse # to end" << endl;
    string sbuff;
    int ibuff;
    while(1){
		cin >> sbuff;
		if(sbuff == "#") return;
		cin >> ibuff;
		if (sbuff.size() <= 8 && sbuff.size() >= 1 &&
			ibuff <= 5 && ibuff >= 0 ) {
			Course *p = new Course(sbuff, ibuff);
			//Course input(buff, itemp);
            hisCourseList.push_back(*p);
			//hisCourseList.add(*p);
			course_no ++, score_sum += ibuff;
			average = score_sum / course_no;
		}
		else{
			cout << "Illeagal input" << endl;
		}
	}
}

//void Student::change_info(){
//	cout << "Input name[8]\n";
//    cin >> name;
//    cout << "Creating stu info\n";
//    //hisCourseList.add(p);
//}

void Student::print_info(){
    //cout.width(8);
    //cout.setf(ios::left);
    //cout << no << score1 << score2 << score3 << endl;
    cout << name << "\t" << " average:" << average << "\t";
	list<Course>::iterator iter = hisCourseList.begin();
    //ListNode<Course> *p = hisCourseList.getHead();
    //hisCourseList.getHead()->read_info().print_info();
	while (iter != hisCourseList.end()){
		iter->print_info();
        iter++;
	}
//    while ((p = hisCourseList.getNext(p))){
//		p->read_info().print_info();
//	}
	std::cout << endl;
}
//int Student::get_info(int course_no){
//    switch (course_no) {
//        case 0:return score1;break;
//        case 1:return score2;break;
//        case 2:return score3;break;
//        default:            break;
//    }
//    return 0;
//}

Student::~Student(){
    
}
