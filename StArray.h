#include "Student.h"

using namespace std;

#ifndef STARRAY_H
#define STARRAY_H

class StArray {

protected:
	
	Student* stu_array[MAX_STUDENT_NUM];
	int stu_num;

public:

	StArray();
	virtual ~StArray();
	int addStudent(int student_ID, string student_name);
	int addEE_Course(int student_ID, int course_num, string course_name, int hw_num, float hw_weight);
	int addCS_Course(int student_ID, int course_num, string course_name, int hw_num, float hw_weight, int hw_flag, string bookname);
	int setHwGrade(int student_ID, int course_num, int hw_assignment, int hw_grade);
	int setExamGrade(int student_ID, int course_num, int exam_grade);
	int setFactor(int course_num, int factor);
	int printStudent(int student_ID);
	void printAll();
	void resetStArray();

};

#endif