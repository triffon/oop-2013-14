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
  : Student(_name, _id, _fn, _grade),
    Employee(_name, _id, _position, _salary),
    period(_period) {
	cerr << "Intern(...)" << endl;
}

void Intern::print(ostream& os) const {
	Student::print(os);
	Employee::print(os);
	os << "Период на стажа: " << period << " месеца" << endl;
}

