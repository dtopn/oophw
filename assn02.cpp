// CPPprgmVS.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

template <typename T> class LinkedList;
template <typename T> class ListNode{
	friend class LinkedList<T>;
public:
	ListNode(const T t): data(t), next(0){}
	~ListNode();
	T read_info();
	//ListNode* getNext();
private:
	ListNode* next;
	T data;
};

template <typename T> class LinkedList {
public:
    ListNode<T> *getHead();
    ListNode<T> *getNext(ListNode<T> const *iterator);
    //void add(ListNode<T> &p);
    void add(T &val);
    void visitNode();
    LinkedList(): head(0), tail(0){}
	~LinkedList();
private:
    ListNode<T> *head, *tail;
    bool itsEmpty();
};

class Course{
public:
    Course();
    Course(std::string name, int score);//: name(name), score(score){}
    ~Course();
    void input_info();
    void print_info();
	float get_average();
    //int get_info(int course_no);
private:
    int score;
    float average;
    std::string name;
};

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
    LinkedList<Course> hisCourseList;
};


class Class{
public:
	Class();
	~Class();
    void input_info();
    void print_info();
	//void input_course();
private:
    LinkedList<Student> hisStuList;
};


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
			hisCourseList.add(*p);
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
	ListNode<Course> *p = hisCourseList.getHead();
	hisCourseList.getHead()->read_info().print_info();
	while ((p = hisCourseList.getNext(p))){
		p->read_info().print_info();
	}
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


//template <typename T>
//LinkedList<T>::LinkedList()
//{
//    head = new ListNode<T>;
//    head -> next = nullptr;
//}
/*
template <typename T> ListNode<T>* LinkedList<T>::getNext(ListNode<T> *iterator)
{
    ListNode<T> *p;
    p = head;
    int k;
    while(p && k < iterator){
        p = p -> next;
        k++;
    }
    return p;
}
*/
//template <typename T>
//void LinkedList<T>::add(ListNode<T> &p){
//    
//}

template <class T> void LinkedList<T>::add(T &val)
//void LinkedList<T>::add(ListNode<T> &p)
{
    //ListNode<T> *trver = head;
    //while((trver = getNext(trver)->next));
    //trver
    //getNext(<#ListNode<T> *iterator#>)->next =
    
    //ListNode<T> *trver,*q;
//    trver = head;
//    q = new ListNode<T>;
//    q -> data = &p;
//    while(trver -> next){
//    trver = getNext(trver);
//    }
//    getNext(trver) = q;
//    getNext(q) = nullptr;
    ListNode<T> *p = new ListNode<T>(val);    
    if (itsEmpty()) {
	    head = tail = p;
    }
    else{
        tail->next = p;
        tail = tail->next;
    }
}
    

template <typename T> bool LinkedList<T>::itsEmpty() {
    return !head;
}

template <typename T> LinkedList<T>::~LinkedList<T>() {
    //delete head;
}

template <typename T> ListNode<T>* LinkedList<T>::getHead(){
	return head;
}

template <typename T> ListNode<T>* LinkedList<T>::getNext(ListNode<T> const *iterator){
	return iterator->next;
}

//template <typename T> ListNode<T>::ListNode(){
//    ;
//}


template <typename T> ListNode<T>::~ListNode(){
	if ( next )
		delete next;
}

template <typename T> T ListNode<T>::read_info(){
	return data;
}

//template <typename T> ListNode<T>* ListNode<T>::getNext(){
//	return next;
//}



#define _nSTL_solution
void print_menu(){
	    cout << "Choose an action" << endl <<
            "[1]Show Class info" << endl <<
            "[2]Add Student to a class" << endl <<
            "[3]Undefined" << endl <<
            "[0]Exit" << endl;
}

#ifdef _nSTL_solution
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
#endif

#ifdef _STL_solution

int main(){
    Class aClass;
    cout << "Choose an action\n" << endl <<
    "[q]Show Class info" << endl <<
    "[w]Add Student to a class" << endl <<
    "[e]Add info to a student" << endl <<
    "[z]Exit" << endl;
    char buff;
    while (1) {
	cin >> buff;
        switch (buff) {
            case 'q': break;
            case 'w': aClass.input_info(); break; //add student names to class
            case '0': return 0;
            default: cout << "Illeagal input." << endl; break;
        }
    }
}

#endif