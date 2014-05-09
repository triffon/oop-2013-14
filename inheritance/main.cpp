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
	cout << s.getFN() << endl;
	s.print();

}


