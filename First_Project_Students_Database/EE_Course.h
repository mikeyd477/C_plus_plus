#include "Course.h"

#ifndef EE_COURSE_H
#define EE_COURSE_H

class EE_Course : public Course {

protected : 
	int factor;

public : 
	//Constructor
	EE_Course(int course_num_, string course_name_, int hw_tot_num_, float hw_weigh_);
	//Destructor
	int getFactor();
	int setFactor(int factor_);
	int getCourseGrade();

};



#endif
