/*
 * rational_prog.cpp
 *
 *  Created on: 07.03.2014
 *      Author: trifon
 */

#include "rational.h"
#include <iostream>
using namespace std;

int main() {
	//Rational r = Rational();
	Rational r;
	//cout << r.numer << ' ' << r.denom << endl;
	//Rational q = Rational(3, 5);
	Rational q(3, 5);
	//cout << q.numer << ' ' << q.denom << endl;
	cout << q.getNumerator() << ' ' << q.getDenominator() << endl;
	// cout << getNumerator();
	// не може да се вика без променлива от Rational!
	q.print();cout << endl;
	r.print();cout << endl;
	r.read();
	r.print();cout << endl;
	add(q, r).print();cout << endl;
	Rational s;
	//s.numer = 2;
	//s.denom = 4;
	s.print();
}


