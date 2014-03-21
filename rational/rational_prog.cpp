/*
 * rational_prog.cpp
 *
 *  Created on: 07.03.2014
 *      Author: trifon
 */

#include "rational.h"
#include <iostream>
using namespace std;

void testRational() {
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
	// q.reduce();
	// q.denom;
	Rational q2(9, 15);
	if (q.equals(q2))
		cout << "Равни са!\n";
	else
		cout << "Не са равни!\n";
	// !!! cout << getNumerator() << endl;

}

// декларация на функция
// Rational r2();

void testConstructors() {
	Rational r1;
	// !!! Rational r2();
	Rational r3 = Rational();
	r1.print();cout << endl;
	// !!! r2.print();
	r3.print();cout << endl;
	Rational r4(1, 2);
	Rational r5(5);
	Rational r6 = r4;
	r6.print();
}

int main() {
	// testRational();
	testConstructors();
	return 0;
}
