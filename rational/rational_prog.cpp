/*
 * rational_prog.cpp
 *
 *  Created on: 07.03.2014
 *      Author: trifon
 */

#include "rational.h"
#include "rational_point.h"
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

Rational round(Rational r) {
	int wholePart = r.getNumerator() / r.getDenominator();
	return wholePart; // ↔ return Rational(wholePart);
}

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
	r6.print();cout << endl;
	cout << "По стойност:\n";
	add(r5, r6).print();cout << endl;
	// !!! Rational* result = add_pointers(&r5, &r6);
	// !!! cout << "Новият резултат е: ";
	cout << "По указател:\n";
	add_pointers(&r5, &r6).print(); cout << endl;
	cout << "По псевдоним:\n";
	add_ref(r5, r6).print();cout << endl;
	// !!! Rational& result = add_ref(r5, r6);
	// !!! add(r5, r5);
	// !!! result.print();cout << endl;
	// !!! cout << "Предният резултат е: ";
	// !!!result->print();cout << endl;
	r5.print();cout << endl;
	r6.print();cout << endl;

	add(3, Rational(2, 3)).print();cout << endl;
	// ↔ add(Rational(3), Rational(2, 3)).print();
	round(add(r4,r5)).print();cout << endl;

	Rational r7 = 1.25;
	r7.print();cout << endl;
}

void testRationalPoint() {
	RationalPoint p;
	Rational r1(1, 3);
	Rational r2(2, 5);
	RationalPoint q(r1, r2);
	RationalPoint q2 = q;
}

void testRationalArrays() {
	Rational p(1,3), q(3, 5);
	// 12 или 8 конструктора, в зависимост дали има
	// -fno-elide-constructors
	Rational d[6] = { Rational(),
			          Rational(5, 7),
			          p, Rational(q), 1 };
	// 7 конструктора
	Rational *a = new Rational, *b = new Rational(3, 4),
			*c = new Rational[5];
}

bool operator==(Rational const& r1, Rational const& r2) {
	return r1.getNumerator() == r2.getNumerator() &&
		   r1.getDenominator() == r2.getDenominator();
}

int plus1(int x) {
	return x + Rational(7,5);
}

void testOperators() {
	cout << (Rational(1,2) == Rational(2,4)) << endl;
	Rational r(2, 3),p;
	cout << 2 + r << endl;
	cin >> p >> r;
	cout << p << ' ' << r << endl;
	p = r;
	cout << p << ' ' << r << endl;
	p = 3;
	cout << p << endl;
	p = p + Rational(1,2);
	int x = p;
	cout << x << endl;
	cout << plus1(p) << endl;
}

int main() {
	// testRational();
	// testConstructors();
	// testRationalPoint();
	// testRationalArrays();
	testOperators();
	return 0;
}
