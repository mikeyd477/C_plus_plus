#include "Student.h"

Student::Student(int person_ID, string person_name) :
	Person(person_ID, person_name), ee_courses_num(0), cs_courses_num(0), ee_courses_index(0), cs_courses_index(0){
	//Reset array to NULL's
	for (int i = 0; i < MAX_COURSE_NUM; i++) {
		ee_courses[i] = NULL;
		cs_courses[i] = NULL;

	}
};

int Student::getCourseCnt() {

	return (ee_courses_num + cs_courses_num);
};

int Student::addEE_Course(EE_CoursePtr EE_Course_P) {

	if (EE_Course_P == NULL) {
		return 0;
	}
	else if (ee_courses_index < MAX_COURSE_NUM) {
				ee_courses[ee_courses_index] = EE_Course_P;
				ee_courses_index++;
				ee_courses_num++;
				return 1;
			}
	else {
		return 0;
	}
};

int Student::addCS_Course(CS_CoursePtr CS_Course_P) {

	if (CS_Course_P == NULL) {
		return 0;
	}
	else if (cs_courses_index < MAX_COURSE_NUM) {
				cs_courses[cs_courses_index] = CS_Course_P;
				cs_courses_index++;
				cs_courses_num++;
				return 1;
			}
	else {
		return 0;
	}

};

EE_Course* Student::getEE_Course(int course_num) {
	for (int i = 0; i < MAX_COURSE_NUM; i++) {
		if (ee_courses[i] != NULL) {
			if ((ee_courses[i]->getNum()) == course_num) {
				return ee_courses[i];
			}
		}
	}
	return NULL;

};

CS_Course* Student::getCS_Course(int course_num) {
	for (int i = 0; i < MAX_COURSE_NUM; i++) {
		if (cs_courses[i] != NULL) {
			if ((cs_courses[i]->getNum()) == course_num) {
				return cs_courses[i];
			}
		}
	}
	return NULL;

};

int Student::remCourse(int course_num) {
	for (int i = 0; i < MAX_COURSE_NUM; i++) {
		//CS courses check
		if (cs_courses[i] != NULL) {
			if ((cs_courses[i]->getNum()) == course_num) {
				delete cs_courses[i];
				cs_courses[i] = NULL;
				cs_courses_num--;
				return 1;
			}
		}
		//EE courses check
		if (ee_courses[i] != NULL) {
			if ((ee_courses[i]->getNum()) == course_num) {
				delete ee_courses[i];
				ee_courses[i] = NULL;
				ee_courses_num--;
				return 1;
			}
		}
	}
	return 0;
};


int Student::getAvg() {
	int total_grades_sum = 0;
	for (int i = 0; i < MAX_COURSE_NUM; i++) {
		if (cs_courses[i] != NULL) {
			total_grades_sum += (cs_courses[i]->getCourseGrade());
		}
		if (ee_courses[i] != NULL) {
			total_grades_sum += (ee_courses[i]->getCourseGrade());
		}
	}
	int total_courses = ee_courses_num + cs_courses_num;
	if (total_courses == 0) {
		return 0;
	}
	else {
		return ((int)round(total_grades_sum / total_courses));
	}
};

void Student::print() {

	cout << "Student name: " << person_name << endl;
	cout << "Student ID: " << person_ID << endl;
	cout << "Average grade: " << getAvg() << endl << endl;
	
	cout << "EE courses:" << endl;

	for (int i = 0; i < MAX_COURSE_NUM; i++) {
		if (ee_courses[i] != NULL) {
			cout << ee_courses[i]->getNum() << " " << (*(ee_courses[i]->getName())) << ": " << ee_courses[i]->getCourseGrade() << endl;
		}
	}

	cout << "" << endl;

	cout << "CS courses:" << endl;

	for (int i = 0; i < MAX_COURSE_NUM; i++) {
		if (cs_courses[i] != NULL) {
			cout << cs_courses[i]->getNum() << " " << (*(cs_courses[i]->getName())) << ": " << cs_courses[i]->getCourseGrade() << endl;
		}
	}
	cout << "" << endl;

};
