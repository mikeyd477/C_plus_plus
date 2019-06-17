#include "Person.h"


Person::Person(int person_ID_, string person_name_) {
	person_ID = person_ID_;
	person_name = person_name_;
};

int Person::getID() {
	return person_ID;
};

string* Person::getName() {
	string* copy_name = new string;
	*copy_name = person_name;
	return copy_name;
};

