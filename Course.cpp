#include <iostream>
#include <string>


#include "Course.h"

using namespace std;
Course::Course(){
	static int no_count = 0;
	no_count ++;
	//no = no_count;
}

Course::Course(string name, int score): name(name), score(score){
	static int no_count = 0, sum = 0;
	no_count ++, sum += score;
	average = 1.0 * sum / no_count;
    cout << "Created course with name and score" << endl;
	//no = no_count;
}

void Course::input_info(){
	cout << "Input course name[8] and score(int)0-5\n";
    cin >> name;
    cin >> score;
	//cout << average << endl;
}

void Course::print_info(){
    //cout.width(8);
    //cout.setf(ios::left);
    //cout << no << score1 << score2 << score3 << endl;
    cout << name << ":"<< score << "\t";
}
float Course::get_average(){
	return average;
}    
//int Course::get_info(int course_no){
//    switch (course_no) {
//        case 0:return score1;break;
//        case 1:return score2;break;
//        case 2:return score3;break;
//        default:            break;
//    }
//    return 0;
//}

Course::~Course(){
    
}
