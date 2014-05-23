/*
 * employee.h
 *
 *  Created on: 23.05.2014
 *      Author: trifon
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
using namespace std;

class Employee {
	char* position;
	double salary;
public:

	// конструктори и голяма 4
	Employee(char const* = "", double = 0);
	Employee(Employee const&);
	Employee& operator=(Employee const&);
	~Employee();

	// селектори
	char const* getPosition() const { return position; }
	double getSalary() const { return salary; }

	// мутатори
	void setPosition(char const*);
	void setSalary(double _salary) { salary = _salary; }

	// извеждане
	void print(ostream& = cout) const;

	bool operator>(Employee const& e) const
	{ return salary > e.salary; }

private:
	void clean();
	void copy(Employee const&);

};


#endif /* EMPLOYEE_H_ */
