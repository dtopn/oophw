#ifndef COURSE_H
#define COURSE_H


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



#endif //COURSE_H
