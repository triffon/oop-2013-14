/*
 * main.cpp
 *
 *  Created on: 09.05.2014
 *      Author: trifon
 */

#include <iostream>
using namespace std;

#include "student.h"

int main() {
	Person p("Иван Иванов", "8311100123");
	p.setName("Петър Петров");
	cout << p.getID() << endl;
	p.print();

	Student s("Мария Георгиева", "1234567890", 44444, 5.5);
	s.setName("Пенка Георгиева");
	cout << s.getName() << endl;
	cout << s.getFN() << endl;
	s.print();

	Person p2 = s;
	p2.print();

	Person* pp = &s;
	cout << &s << ' ' << pp << endl;

	// !!!
	Student s2 = (Student const&)p;
	// !!! Student s2 = (Student)p;
	s2.print();

	// !!! Person p3 = s;
	Person& p3 = s;

	Student s3 = (Student const&)p3;
	s3.print();
}


