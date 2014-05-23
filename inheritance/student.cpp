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
{ cerr << "Student(...)" << endl; }

void Student::print(ostream& os) const {
	Person::print(os);
	os << *this;
}

Student::~Student() {
	cerr << "~Student()" << endl;
}

ostream& operator<<(ostream& os, Student const& s) {
	os << "Ф№: " << s.getFN() << endl;
	os << "Успех: " << s.getGrade() << endl;
	return os;
}
