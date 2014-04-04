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
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
}

Student::Student(Student const& s) : fn(s.fn), grade(s.grade) {
	name = new char[strlen(s.name) + 1];
	strcpy(name, s.name);
}

void Student::print() const {
	cout << fn << ' ' << name << ' ' << grade << endl;
}

void Student::setName(char const* _name) {
	delete[] name;
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
}

Student::~Student() {
	// cout << "Деструктор на Student\n";
	delete[] name;
}
