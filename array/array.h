/*
 * array.h
 *
 *  Created on: 04.04.2014
 *      Author: trifon
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include <cmath>

class Array {
	int n;		// капацитет
	double* d;  // указател към първи елемент
// Задача: да се напишат подходящи конструктори
// Бонус: селектори и мутатори
public:
	Array(int _n = 10, double const* _d = NULL) : n(_n) {
		d = new double[n];// това е задължително
		// !!! d = NULL; // лошо
		if (_d != NULL)
			copy(_d);
	}

	/*
	 * Не е добре
	 * Array() : n(0) { d = new double[n]; }
	 */
	// !!!!
	Array(Array const& a) : n(a.n) {
		d = new double[n];
		copy(a.d);
	}

	int getN() const { return n; }

	// !!! не е добре: нарушава се абстракцията
	double const* getD() const { return d; }

	double getAt(int i) const {
		if (i >= 0 && i < n)
			return d[i];
		return 0;
	}

	// по-сложен, отколкото изглежда
	void setN(int _n) {
		double* newd = new double[_n];
		for(int i = 0; i < min(_n, n); i++)
			newd[i] = d[i];
		delete[] d;
		d = newd;
		n = _n;
	}

	// лошо!!!
	// !!! void setD(double* d) { ... }
	void setD(double const* _d, int _n) {
		delete d;
		n = _n;
		d = new double[n];
		copy(_d);
	}

	void setAt(int i, double x) {
		if (i >= 0 && i < n)
			d[i] = x;
	}

private:
	void copy(double const* _d) {
		for(int i = 0; i < n; i++)
			d[i] = _d[i];
	}
};


#endif /* ARRAY_H_ */
