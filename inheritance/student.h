/*
 * student.h
 *
 *  Created on: 09.05.2014
 *      Author: trifon
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include "person.h"

class Student /*: public Person */{
	int fn;
	double grade;
public:

	// собствен конструктор
	Student(char const* ="", char const* = "0",
			int _fn = 0, double grade = 0);

	// собствени селектори
	int getFN() const { return fn; }
	double getGrade() const { return grade; }

	// собствени мутатори
	void setFN(int _fn) { fn = _fn; }
	void setGrade(double _grade) { grade = _grade; }

	// собствено извеждане
	void print(ostream& os = cout) const;

	bool operator>(Student const& s) const
	{ return grade > s.grade; }

	~Student();
};

#endif /* STUDENT_H_ */
