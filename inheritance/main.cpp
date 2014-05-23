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
#include "intern.h"

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
	Employee e1, e2("Иван Иванов", "XXXX", "Асистент", 300), e3 = e2;
	e1 = e3;
	e2.setPosition("Главен асистент");
	e2.setSalary(400);
	e1.print();
	e2.print();
	e3.print();
}

void internTest() {
	Intern i1, i2("Владимир Начев", "XXXXXXXXXX",
				  81000, 5.80, "Демонстратор", 150, 4), i3 = i2;
	i1 = i3;
	i1.setPeriod(8);
	i1.setGrade(6);
	i2.setPosition("Асистент");
	i2.setSalary(300);
	cout << "i1:\n";
	i1.print();
	cout << "i2:\n";
	i2.print();
	cout << "i3:\n";
	i3.print();

	/// !!! cout << (i1 > i2) << endl;

	Student s1 = i1;
	Student s2 = i2;

	cout << "s1 > s2? " << (s1 > s2) << endl;

	Employee e1 = i1;
	Employee e2 = i2;

	cout << "e1 > e2? " << (e1 > e2) << endl;

	cout << "(Student&)i1 > i2? " << ((Student&)i1 > i2) << endl;
	cout << "(Employee&)i1 > i2? " << ((Employee&)i1 > i2) << endl;

	// !!! cout << i1.getName();
	cout << ((Employee&)i1).getName() << endl;
	cout << ((Student&)i1).getName() << endl;

	Person p11 = (Person&)(Employee&)i1;
	Person p12 = (Person&)(Student&)i1;

	cout << i1.getName() << endl;
	Person p13 = i1;

}

int main() {

	// personStudentTest();

	cerr << "======================" << endl;

	paidStudentTest();

	cerr << "======================" << endl;

	employeeTest();

	cerr << "======================" << endl;

	internTest();

	cerr << "======================" << endl;

}


