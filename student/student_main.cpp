/*
 * student_main.cpp
 *
 *  Created on: 28.03.2014
 *      Author: trifon
 */

#include <iostream>
using namespace std;
#include "student.h"

void anonymousPrint(Student s) {
  s.setName("Анонимен");
  cout << "Информация за оценка:\n";
  s.print();
}

int main() {
	Student s1(40000, "Надя Петрова", 4.5);
	Student s2 = s1;
	s2.setName("Надя Иванова");
	s1.print();
	s2.print();
	anonymousPrint(s1);
	s1.print();
	Student s3 = 5;
	// <--> Student s3(5);
	s3.print();
	return 0;
}


