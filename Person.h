#include <iostream>

using namespace std;

#ifndef PERSON_H
#define PERSON_H

class Person {

//Public variables and functions which the user can access directly
public:
	
	Person(int person_ID_, string person_name_);
	virtual ~Person();
	int getID();
	string* getName();

//Private variables and functions which can be accessed only via internal class code ! the user won't be able to access them directly!
protected:

	int person_ID;
	string person_name;

};

#endif