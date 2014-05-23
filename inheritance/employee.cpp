/*
 * employee.cpp
 *
 *  Created on: 23.05.2014
 *      Author: trifon
 */

#include <cstring>
#include "employee.h"

Employee::Employee(char const* _name,
		           char const* _id,
		           char const* _position,
					double _salary)
		: Person(_name, _id),
		  salary(_salary),
		  position(NULL) {
	cerr << "Employee(...)" << endl;
	setPosition(_position);
}

Employee::Employee(Employee const& e) : Person(e) {
	cerr << "Employee(Employee const&)" << endl;
	copy(e);
}

Employee& Employee::operator=(Employee const& e) {
	cerr << "operator=(Employee const&)" << endl;
	if (this != &e) {
		Person::operator=(e);
		clean();
		copy(e);
	}
	return *this;
}

Employee::~Employee() {
	cerr << "~Employee()" << endl;
	clean();
}

void Employee::setPosition(char const* _position) {
	if (position != NULL)
		delete[] position;
	position = new char[strlen(_position) + 1];
	strcpy(position, _position);
}

void Employee::print(ostream& os) const {
	Person::print();
	os << "Позиция: " << position << endl;
	os << "Заплата: " << salary << " лв." << endl;
}

void Employee::clean() {
	if (position != NULL)
		delete[] position;
}

void Employee::copy(Employee const& e) {
	position = NULL;
	setPosition(e.position);
	setSalary(e.salary);
}

