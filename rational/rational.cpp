/*
 * rational.cpp
 *
 *  Created on: 07.03.2014
 *      Author: trifon
 */

#include "rational.h"
#include <iostream>
using namespace std;

void reduce() {
	cout << "Аз съм функцията reduce()!" << endl;
}

Rational::Rational() {
	numer = 0;
	denom = 1;
}

Rational::Rational(int n) {
	numer = n;
	denom = 1;
}

Rational::Rational(int n, int d) {
	numer = n;
	denom = d;
	reduce();
	// ::reduce();
}

inline int Rational::getNumerator() const {
	// Rational const * const this;
	// !!! Rational q; this = &q;
	// !!! this->numer = 5;
	return this->numer;
}

inline int Rational::getDenominator() const {
	return denom;
}

void Rational::print() const {
	cout << numer << '/' << denom;
}

void Rational::read() {
	// можем да въвеждаме във формата 1/5
	cin >> numer;
	cin.ignore();
	cin >> denom;
	reduce();
}

Rational add(Rational p, Rational q) {
	int rN = p.getNumerator() * q.getDenominator() +
			 q.getNumerator() * p.getDenominator();
	int rD = p.getDenominator() * q.getDenominator();
	Rational r(rN, rD);
	return r;
}

void Rational::reduce() {
	int g = gcd(numer, denom);
	numer /= g;
	denom /= g;
}

int Rational::gcd(int x, int y) {
	if (x == 0 || y == 0)
		return 1;
	while (x != y) {
		if (x > y)
			x -= y;
		else
			y -= x;
	}
	return x; // == y;
}

bool Rational::equals(Rational other) const {
	// Не е грешка!
	// return numer == other.numer && denom == other.denom;
	return getNumerator() == other.getNumerator() &&
		   getDenominator() == other.getDenominator();
}