/*
 * main.cpp
 *
 *  Created on: 09.05.2014
 *      Author: trifon
 */

#include <iostream>
using namespace std;

#include "paid_student.h"
#include "employee.h"

void paidStudentTest() {
	PaidStudent ps1, ps2("Тодор Тодоров", "9876543210", 50000, 4.25, 10000, "ФМИ"),
			    ps3 = ps2;
	ps1 = ps3;

}

/*
void personStudentTest() {
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
*/

void employeeTest() {
	Employee e1, e2("Асистент", 300), e3 = e2;
	e1 = e3;
	e2.setPosition("Главен асистент");
	e2.setSalary(400);
	e1.print();
	e2.print();
	e3.print();
}

int main() {

	// personStudentTest();

	cerr << "======================" << endl;

	paidStudentTest();

	cerr << "======================" << endl;

	employeeTest();

	cerr << "======================" << endl;

}


