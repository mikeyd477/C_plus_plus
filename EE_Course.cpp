#include "EE_Course.h"



EE_Course::EE_Course(int course_num_, string course_name_, int hw_tot_,float hw_weigh_) :
	Course(course_num_,course_name_,hw_tot_,hw_weigh_), factor(0) {}



/*EE_Course::EE_Course(int course_num_, string course_name_, int hw_tot_num_, float hw_weigh_, int factor_) {

	Course::Course(course_num_, course_name_, hw_tot_num_, hw_weigh_ );
	factor = factor_;

};
*/
int EE_Course::getFactor() {
	return factor;

};

int EE_Course::setFactor(int factor_) {
	if (factor_ == NULL) {
		return 0;
	}
	else
	{
		factor = factor_;
		return 1;
	}
};

int EE_Course::getCourseGrade() {

		float hw_average = Course::getHwAverage();

		int course_grade = (int)(round((1 - hw_weigh) * exam_grade + (hw_weigh * hw_average))+factor);

		return course_grade;

};


