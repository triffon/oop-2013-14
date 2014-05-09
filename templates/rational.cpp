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

Rational::Rational(int n, int d) : numer(n), denom(d) {
	cout << "Конструктор Rational с параметри: " << n << ',' << d << endl;
	reduce();
	// ::reduce();
}

Rational::Rational(Rational const &r) : numer(r.numer),
										denom(r.denom) {
	cout << "Конструктор за копиране Rational: ";
	r.print();cout << endl;
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

void Rational::print(ostream& os) const {
	os << numer << '/' << denom;
}

void Rational::read(istream& is) {
	// можем да въвеждаме във формата 1/5
	is >> numer;
	is.ignore();
	is >> denom;
	reduce();
}

Rational add(Rational p, Rational q) {
	int rN = p.getNumerator() * q.getDenominator() +
			 q.getNumerator() * p.getDenominator();
	int rD = p.getDenominator() * q.getDenominator();
	p.invert();
	q.invert();
	Rational r(rN, rD);
	return r;
}

// !!! Rational* add_pointers(Rational const* p, Rational const* q) {
Rational add_pointers(Rational const* p, Rational const* q) {
	int rN = p->getNumerator() * q->getDenominator() +
			 q->getNumerator() * p->getDenominator();
	int rD = p->getDenominator() * q->getDenominator();
	// не можем да викаме мутатори
	// !!! p->invert();
	// !!! q->invert();
	// !!! return new Rational(rN, rD);
	Rational r(rN, rD);
	// !!! return & r;
	return r;
}

Rational add_ref(Rational const& p, Rational const& q) {
	int rN = p.getNumerator() * q.getDenominator() +
			 q.getNumerator() * p.getDenominator();
	int rD = p.getDenominator() * q.getDenominator();
	// не можем да викаме мутатори
	// !!! p.invert();
	// !!! q.invert();
	Rational r(rN, rD);
	return r;
}

void Rational::reduce() {
	int g = gcd(numer, denom);
	numer /= g;
	denom /= g;
	if (denom < 0) {
		numer = -numer;
		denom = -denom;
	}
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

Rational::Rational(double x) : numer(x * 10000), denom(10000) {
	reduce();
}

Rational operator+(int x, Rational const& r) {
	return Rational(x * r.denom + r.numer,
			        r.denom);
}

Rational Rational::operator+(Rational const& r) const {
	return Rational(r.numer * denom + numer * r.denom,
			r.denom * denom);
}

Rational Rational::operator-() const {
	return Rational(-numer, denom);
}

Rational Rational::operator-(Rational const& r) const {
	return *this + -r;
	//return this->operator+(r.operator-());
	//return operator+(-r);
}

Rational Rational::operator*(Rational const& r) const {
	return Rational(numer * r.numer, denom * r.denom);
}

Rational Rational::operator/(Rational const& r) const {
	Rational ri = r;
	ri.invert();
	return *this * ri;
	// return operator*(Rational(r).invert());
}

ostream& operator<<(ostream& os, Rational const& r) {
	r.print(os);
	return os;
}

istream& operator>>(istream& is, Rational & r) {
	r.read(is);
	return is;
}

Rational::operator int() const {
	return numer / denom;
}

Rational::operator double() const {
	return (double) numer / denom;
}
