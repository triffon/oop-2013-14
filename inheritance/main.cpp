/*
 * main.cpp
 *
 *  Created on: 09.05.2014
 *      Author: trifon
 */

#include <iostream>
#include <typeinfo>
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
	Employee e1, e2("Иван Иванов", "XXXX", "Асистент", 300), e3 = e2;
	e1 = e3;
	e2.setPosition("Главен асистент");
	e2.setSalary(400);
	e1.print();
	e2.print();
	e3.print();
}

void tests() {

	// personStudentTest();

	cerr << "======================" << endl;

	paidStudentTest();

	cerr << "======================" << endl;

	employeeTest();

	cerr << "======================" << endl;

}

void bindingTest0() {
	Person* pp = NULL; char c;
	cin >> c;
	if (c == 's') pp = new Student;
	if (c == 'e') pp = new Employee;
	if (c == 'p') pp = new PaidStudent;
	if (pp != NULL) {
		pp->print();
		Person& p = *pp;
		p.print();
		pp->prettyPrint();
		cout << typeid(p).name() << endl;
		cout << typeid(pp).name() << endl;
		cout << typeid(*pp).name() << endl;
		delete pp;
	}
	// PaidStudent ps;
	// !!! ps.print();
}

void bindingTest1() {
	Person* pp = NULL; char c;
	cin >> c;
	if (c == 's') pp = new Student;
	if (c == 'e') pp = new Employee;
	// ......
	// ......
	if (pp != NULL) {
		if (c == 's') ((Student*)pp)->print(); // Student::print
		if (c == 'e') ((Employee*)pp)->print(); // Employee::print
	}
}

struct SmartPerson {
  Person* person;
  enum { PERSON, STUDENT, EMPLOYEE } type;
  void print() {
    if (type == PERSON) person->print();
    if (type == STUDENT) ((Student*)person)->print();
    if (type == EMPLOYEE) ((Employee*)person)->print();
  }
};

void bindingTest2() {
	SmartPerson pp = { NULL, SmartPerson::PERSON }; char c;
	cin >> c;
	if (c == 's') {
		pp.person = new Student;
		pp.type = SmartPerson::STUDENT;
	}
	if (c == 'e') {
		pp.person = new Employee;
		pp.type = SmartPerson::EMPLOYEE;
	}
	pp.print();
	pp.print();
}

class HelloWorld : public Printable {
public:
	void print(ostream& os) const { os << "Hello, world!\n"; }
};

void printableTest() {
	const int N = 5;
	Printable* a[N] = { new Student, new Person,
			            new PaidStudent, new Employee, new HelloWorld };
	for(int i = 0; i < N; i++) {
		cout << "-----------------------------\n";
		a[i]->print();
		cout << "-----------------------------\n";
	}

	for(int i = 0; i < N; i++) {
		delete a[i];
	}

}

int main() {
//	bindingTest0();
	printableTest();
	return 0;
}


