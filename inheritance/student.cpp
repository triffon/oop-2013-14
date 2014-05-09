/*
 * student.cpp
 *
 *  Created on: 09.05.2014
 *      Author: trifon
 */

#include "student.h"

Student::Student(char const* _name,
				 char const* _id,
				 int _fn,
				 double _grade)
	: Person(_name, _id), fn(_fn), grade(_grade)
{}

void Student::print(ostream& os) const {
	// !!! print(os);
	Person::print(os);
	cout << "Ф№: " << fn << endl;
	cout << "Успех: " << grade << endl;
}
