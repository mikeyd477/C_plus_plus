#include "EE_Course.h"
#include "CS_Course.h"
#include "Person.h"
#include "Proj.h"
#ifndef STUDENT_H
#define STUDENT_H
class Student : public Person {
	//For more compact syntax of pointer of pointer
	typedef EE_Course* EE_CoursePtr;
	typedef CS_Course* CS_CoursePtr;
protected:
	EE_CoursePtr* ee_courses = new EE_CoursePtr[MAX_COURSE_NUM];
	CS_CoursePtr* cs_courses = new CS_CoursePtr[MAX_COURSE_NUM];
	//Will have to be static counter!
	int ee_courses_num;
	int cs_courses_num;
public:
	int getCourseCnt();
	int addEE_Course(EE_CoursePtr EE_Course_new);
	int addCS_Course(CS_CoursePtr CS_Course_new);
	int remCourse(int Course_num);
	EE_CoursePtr getEE_Course(int EE_Course_num);
	CS_CoursePtr getCS_Course(int CS_Course_num);
	int getAvg();
	void print();


};



#endif