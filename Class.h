#ifndef CLASS_H
#define CLASS_H

#include <list>
using std::list;
//#include "LinkedList.h"
#include "Student.h"

class Class{
public:
	Class();
	~Class();
    void input_info();
    void print_info();
	//void input_course();
private:
    list<Student> hisStuList;
};

#endif //CLASS_H
