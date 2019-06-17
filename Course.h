#include <iostream>
#include <cmath>
//dangerous to use it because we don't know all the variables that are used here so we might have collision!!!
using namespace std;

#ifndef COURSE_H
#define COURSE_H

class Course {

protected:

	int course_num; // unique number for every course
	string course_name; // course name is a string
	int hw_tot_num; // HW counting starts at 0
	float hw_weigh; // HW weight from final grade, between 0 to 1
	int exam_grade; // final course exam grade
	int* hw_grades_arr; // array holds the HW's grades

public:
	Course();
	Course(int course_num_, string course_name_, int hw_tot_num_, float hw_weigh_); // regular constractor
	Course(const Course& rhs); // copy constructor
	
	virtual ~Course(); // detructor

	Course& operator=(const Course& rhs); // assignment operator

	int getNum(); // returns the course number
	string* getName(); // returns a pointer to a copy of the course name string
	int getExamGrade(); // returns the course final exam grade 
	int getHwGrade(int hw_num_); // get HW number, returns its grade 
	int getHwNum(); // returns the total HW's number
	float getHwWeigh(); // returns the HW weight relative to the final grade
	float getHwAverage(); //returns all HW grades average
	virtual int getCourseGrade(); // returns final course grade
	int setExamGrade(int exam_grade_); // adds the  exame grade to the course. 1=success, 0=failure
	int setHwGrade(int hw_num_, int hw_grade_); // adds the hw_grade to hw_num. 1=success, 0=failure 

};

#endif // !COURSE_H