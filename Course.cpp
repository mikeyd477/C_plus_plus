#include "Course.h"

//Course default constructor
		//Course::Course()
			//{
				//}
// "Course" class REGULAR constractor implementation: NOT SURE ABOUT exam_grade INITIALIZATION - shouldn't be part of the constructor
Course::Course(int course_num_, string course_name_, int hw_tot_num_, float hw_weigh_) {

	course_num = course_num_;
	course_name = course_name_;
	hw_tot_num = hw_tot_num_;
	hw_weigh = hw_weigh_;
	hw_grades_arr = new int[hw_tot_num - 1];
	for (int i = 0; i < hw_tot_num; i++) {
		hw_grades_arr[i] = 0;
	}
	exam_grade = 0;

};

// assignment operator helper function:
int* createNewCopy(const int* hw_grades_arr_, const int hw_tot_num_) {

	int* dst_hw_grades_arr;

	if (hw_grades_arr_ == NULL) return NULL;

	dst_hw_grades_arr = new int[hw_tot_num_];

	for (int i = 0; i <= (hw_tot_num_ - 1); i++) {

		dst_hw_grades_arr[i] = hw_grades_arr_[i];

	}

	return dst_hw_grades_arr;

}


// "Course" class COPY constractor implementation: NOT SURE ABOUT exam_grade INITIALIZATION - not part of the constructor
Course::Course(const Course& rhs) {

	course_num = rhs.course_num;
	course_name = rhs.course_name;
	hw_tot_num = rhs.hw_tot_num;
	hw_weigh = rhs.hw_weigh;
	hw_grades_arr = createNewCopy(rhs.hw_grades_arr, rhs.hw_tot_num);
	exam_grade = rhs.exam_grade;

};

// "Course" class destructor implementation:
Course::~Course() { 
	
	delete[] hw_grades_arr; 

};


// "Course" class assignment operator implementation:
//AR: why "&" and *this ? 
Course& Course::operator=(const Course& rhs) {

	if (this != &rhs) {

		course_num = rhs.course_num;
		course_name = rhs.course_name;
		hw_tot_num = rhs.hw_tot_num;
		hw_weigh = rhs.hw_weigh;
		exam_grade = rhs.exam_grade;

		if (hw_grades_arr) delete[] hw_grades_arr;
		hw_grades_arr = createNewCopy(rhs.hw_grades_arr, rhs.hw_tot_num);
	}

	return *this;

}

// "getNum" function returns the course number:
int Course::getNum() {

	return course_num;

};

// "getName" function returns a pointer to a copy of the course name string
string* Course::getName() {

	string* course_name_copy = new string;
	(*course_name_copy) = course_name;
	
	return course_name_copy;

};

// "getExamGrade" function returns the course final exam grade:
int Course::getExamGrade() {

	return exam_grade;

};

// "getHwGrade" gets HW number and returns its grade:
int Course::getHwGrade(int hw_num_) {

	if ((hw_num_ > (hw_tot_num - 1)) || (hw_num_ < 0)) {

		return 0;

	}
	else
	{

		return hw_grades_arr[hw_num_];
	
	}
};

// "getHwNum" returns the total HW's number
int Course::getHwNum() {

	return hw_tot_num;

};

// "getHwWeight" returns the HW weight relative to the final grade:
float Course::getHwWeigh() {

	return hw_weigh;

};

//"getHwAverage" returns all HW grades average:
float Course::getHwAverage() {

	float hw_grades_sum = 0;
	
	if (hw_tot_num == 0){
	
		return 0;
	
	}

	else {

		for (int i = 0; i <hw_tot_num; i++) {

			hw_grades_sum += hw_grades_arr[i];
		}

		return (hw_grades_sum / hw_tot_num);

	}

};

// "getCourseGrade" returns final course grade:
 int Course::getCourseGrade() {
	
	float hw_average = Course::getHwAverage();
	
	int course_grade = (int)(round((1-hw_weigh)*exam_grade + (hw_weigh*hw_average)));

	return course_grade;

};

// "setExamGrade" adds the exame grade to the course (1=success, 0=failure): NOT CLEAR FROM THE FORUM about failure
int Course::setExamGrade(int exam_grade_) {

//	if (exam_grade_ == NULL) {
		
//		return 0;
	
//	}
	
//	else
	
//	{
		Course::exam_grade = exam_grade_;
		
		return 1;
//	}

};

// "setHwGrade" adds the hw_grade to hw_num (1=success, 0=failure):
int Course::setHwGrade(int hw_num_, int hw_grade_) {

	if ( (hw_num_ > (hw_tot_num-1) ) || (hw_num_ < 0) ) {

		return 0;

	}
	else
	{
		hw_grades_arr[hw_num_] = hw_grade_;

		return 1;
	}

};