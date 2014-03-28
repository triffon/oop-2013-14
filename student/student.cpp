/*
 * student.cpp
 *
 *  Created on: 28.03.2014
 *      Author: trifon
 */

#include <cstring>
#include <iostream>
using namespace std;

#include "student.h"

Student::Student(int _fn, char const* _name, double _grade)
				  : fn(_fn), grade(_grade) {
	setName(_name);
}

void Student::print() const {
	cout << fn << ' ' << name << ' ' << grade << endl;
}

void Student::setName(char const* _name) {
	strncpy(name, _name, MAX_NAME);
	name[MAX_NAME - 1] = '\0'; // В случай на препълване
}

