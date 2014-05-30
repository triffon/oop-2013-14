/*
 * paid_student.h
 *
 *  Created on: 16.05.2014
 *      Author: trifon
 */

#ifndef PAID_STUDENT_H_
#define PAID_STUDENT_H_

#include <iostream>
using namespace std;
#include "student.h"

class PaidStudent : public Student {
	double fee;
	char* sponsor;
public:

	// голяма четворка
	PaidStudent(char const* ="", char const* ="0",
				int=0, double=0, double=0, char const* ="аз");
	PaidStudent(PaidStudent const&);
	PaidStudent& operator=(PaidStudent const&);
	~PaidStudent();

	// селектори
	double getFee() const { return fee; }
	char const* getSponsor() const { return sponsor; }

	// мутатори
	void setFee(double);
	void setSponsor(char const*);

private:
	void print(ostream& = cout) const;

	// копиране и почистване
	void copy(PaidStudent const&);
	void clean();
};



#endif /* PAID_STUDENT_H_ */
