#ifndef STUDENT_H
#define STUDENT_H

#include <list>
using std::list;
//#include "LinkedList.h"

#include "Course.h"

#include <string>

class Student{
public:
    Student();
    Student(const std::string buff); //const??
    void input_info();
    void print_info();
	//int get_info(int course_no);
    ~Student();
private:
    int course_no, score_sum;
    std::string name;
    float average;
    list<Course> hisCourseList;
};

#endif //STUDENT_H
