#include "Course.h"
#include "EE_Course.h"
#include "CS_Course.h"
int main() {

	Course Test(44101, "Mamat", 3, 0.5);
	//cout << *Test.getName()<< endl;
	Test.setExamGrade(90);
	//cout << Test.getHwGrade(0) <<Test.getHwGrade(1) << Test.getHwGrade(2) << endl;
	//cout << Test.getHwAverage() << endl;
	//cout << Test.getCourseGrade() << endl;
	EE_Course Test2(44200, "Haim", 3, 0.5);
	cout << Test2.getFactor() << endl;
	Test2.setFactor(15);
	cout << *Test2.getName()<<endl;
	cout << Test2.getFactor() << endl;
	Test2.setHwGrade(0, 100);
	cout << Test2.getCourseGrade() << endl;
	cout << Test2.getNum() << endl;

}