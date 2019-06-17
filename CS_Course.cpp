#include "CS_Course.h"


CS_Course::CS_Course(int course_num_, string course_name_, int hw_tot_, float hw_weigh_,int hw_flag_,string bookname_) :
	Course(course_num_, course_name_, hw_tot_, hw_weigh_), hw_flag(hw_flag_),bookname(bookname_) {}



/*
CS_Course::CS_Course(int course_num_, string course_name_, int hw_tot_num_, float hw_weigh_, int hw_flag_, string bookname_) {
	Course::Course(course_num_, course_name_, hw_tot_num_, hw_weigh_);
	hw_flag = hw_flag_;
	bookname = bookname_;
};
*/

int max(int a, int b) {
	if (a >= b) {
		return a;
	}
	else {
		return b;
	}
}

int CS_Course::isTakef() {

	if (hw_flag == 1) {
		return 1;
	}
	else {
		return 0;
	}
};

string* CS_Course::getBook() {
	string* book_copy = new string;
	(*book_copy) = bookname;
	return book_copy;
};

int CS_Course::setTakef(int hw_flag_) {
	if ((hw_flag_ != 0) && (hw_flag_ != 1))
	{
		return 0;
	}
	else {
		hw_flag = hw_flag_;
		return 1;
	}
};

void CS_Course::setBook(string *bookname_) {
	bookname = *(bookname_);
};

int CS_Course::getCourseGrade() {
	int course_grade = 0;
	if (hw_flag == 1) {
		float hw_average = Course::getHwAverage();
		course_grade = (int)(round((1 - hw_weigh) * exam_grade + (hw_weigh * hw_average)));		
	}
	else if (hw_flag == 0) {
		float hw_average = Course::getHwAverage();
		int course_grade_temp = (int)(round((1 - hw_weigh) * exam_grade + (hw_weigh * hw_average)));
		 course_grade = max(course_grade_temp, exam_grade);
	}
	return course_grade;
};


