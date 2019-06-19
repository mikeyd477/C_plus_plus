#include "Course.h"
#ifndef CS_COURSE_H
#define CS_COURSE_H

class CS_Course : public Course {

protected:
	int hw_flag; // 0 is Magen and 1 is Takef
	//AR: Do we need a CopyConstructor for the bookname ??
	string bookname; 

public:
	CS_Course(int course_num_, string course_name_, int hw_tot_num_, float hw_weigh_, int hw_flag_, string bookname_);
	int isTakef();
	string* getBook();
	int setTakef(int hw_flag_);
	void setBook(string* bookname_);
	int getCourseGrade();
};



#endif
