/*
 * intern.h
 *
 *  Created on: 23.05.2014
 *      Author: trifon
 */

#ifndef INTERN_H_
#define INTERN_H_

#include "student.h"
#include "employee.h"

class Intern : public Student, public Employee {
	int period;
public:

	// конструктори
	Intern(char const* = "", char const* = "",
		int = 0, double = 0, char const* = "", double = 0, int = 0);

	// селектори
	int getPeriod() const { return period; }

	// мутатори
	void setPeriod(int _period) { period = _period; }

	// извеждане
	void print(ostream& = cout) const;

};



#endif /* INTERN_H_ */
