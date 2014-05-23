/*
 * intern.cpp
 *
 *  Created on: 23.05.2014
 *      Author: trifon
 */

#include "intern.h"

Intern::Intern(char const* _name,
			   char const* _id,
			   int _fn, double _grade,
			   char const* _position,
			   double _salary,
			   int _period)
  : Student("", "", _fn, _grade),
    Employee("", "", _position, _salary),
    Person(_name, _id),
    period(_period) {
	cerr << "Intern(...)" << endl;
}

Intern::Intern(Intern const& i)
	: Student(i), Employee(i), period(i.period),
	  Person(i) {
	cerr << "Intern(Intern const&)" << endl;
}

void Intern::print(ostream& os) const {
	Person::print();
	os << *this;
}

ostream& operator<<(ostream& os, Intern const& i) {
	os << (Student const&)i;
	os << (Employee const&)i;
	os << "Период на стажа: " << i.getPeriod() << " месеца" << endl;
	return os;
}
