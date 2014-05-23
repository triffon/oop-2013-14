/*
 * intern.cpp
 *
 *  Created on: 23.05.2014
 *      Author: trifon
 */

#include "intern.h"

Intern::Intern(int _fn, double _grade,
			   char const* _position,
			   double _salary,
			   int _period)
  : Student("", "", _fn, _grade),
    Employee(_position, _salary),
    period(_period) {
	cerr << "Intern(...)" << endl;
}

void Intern::print(ostream& os) const {
	Student::print(os);
	Employee::print(os);
	os << "Период на стажа: " << period << " месеца" << endl;
}

