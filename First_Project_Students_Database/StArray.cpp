#include "StArray.h"
//Constructor
StArray::StArray() :stu_num(0) {

	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		stu_array[i] = NULL;
	}
};
//Destructor will have to free all the pointers in the array!
StArray::~StArray() {
	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		delete stu_array[i];
	}
};

int StArray::addStudent(int student_ID, string student_name) {

	Student* new_student_ptr = new Student(student_ID, student_name);
	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		if (stu_array[i] == NULL) {
			stu_array[i] = new_student_ptr;
			stu_num++;
			return 1;
		}
	}
	return 0;
};


int StArray::addEE_Course(int student_ID, int course_num, string course_name, int hw_num, float hw_weight) {

	EE_Course* New_Course_Ptr  = new EE_Course(course_num, course_name, hw_num, hw_weight);
	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		if (stu_array[i] != NULL) {
			if ((stu_array[i]->getID()) == student_ID) {
				stu_array[i]->addEE_Course(New_Course_Ptr);
				return 1;
			}
		}
	}
	return 0;
};

int StArray::addCS_Course(int student_ID, int course_num, string course_name, int hw_num, float hw_weight, int hw_flag, string bookname) {

	CS_Course*  new_CS_Course_Ptr = new CS_Course(course_num, course_name, hw_num, hw_weight, hw_flag, bookname);
	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		if (stu_array[i] != NULL) {
			if ((stu_array[i]->getID()) == student_ID) {
				stu_array[i]->addCS_Course(new_CS_Course_Ptr);
				return 1;
			}
		}
	}
	return 0;
};

int StArray::setHwGrade(int student_ID, int course_num, int hw_assignment, int hw_grade) {
	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		if (stu_array[i] != NULL) {
			if ((stu_array[i]->getID()) == student_ID) {
				if ((stu_array[i]->getEE_Course(course_num)) != NULL) {
					stu_array[i]->getEE_Course(course_num)->setHwGrade(hw_assignment, hw_grade);
					return 1;
				}

				if ((stu_array[i]->getCS_Course(course_num)) != NULL) {
					stu_array[i]->getCS_Course(course_num)->setHwGrade(hw_assignment, hw_grade);
					return 1;
				}
			}
		}
	}
	return 0;
};

int StArray::setExamGrade(int student_ID, int course_num, int exam_grade) {
	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		if (stu_array[i] != NULL) {
			if ((stu_array[i]->getID()) == student_ID) {
				if ((stu_array[i]->getEE_Course(course_num)) != NULL) {
					stu_array[i]->getEE_Course(course_num)->setExamGrade(exam_grade);
					return 1;
				}

				if ((stu_array[i]->getCS_Course(course_num)) != NULL) {
					stu_array[i]->getCS_Course(course_num)->setExamGrade(exam_grade);
					return 1;
				}
			}
		}
	}
	return 0;
};

int StArray::setFactor(int course_num, int factor) {
	int flag = 0;
	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		if (stu_array[i] != NULL) {
				if ((stu_array[i]->getEE_Course(course_num)) != NULL) {
					stu_array[i]->getEE_Course(course_num)->setFactor(factor);
					flag = 1;
				}
		}
	}
	if (flag == 1) {
		return 1;
	}
	else {
		return 0;
	}
};

int StArray::printStudent(int student_ID) {
	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		if (stu_array[i] != NULL) {
			if ((stu_array[i]->getID()) == student_ID) {
				stu_array[i]->print();
				return 1;
			}
		}
	}
	return 0;
};

void StArray::printAll() {

	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		if (stu_array[i] != NULL) {
			stu_array[i]->print();
		}
	}
};
//Have issue here with the reset function.
void StArray::resetStArray() {
	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		delete stu_array[i];
	}
};



