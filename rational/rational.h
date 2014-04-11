/*
 * rational.h
 *
 *  Created on: 07.03.2014
 *      Author: trifon
 */

#ifndef RATIONAL_H_
#define RATIONAL_H_

#include <iostream>
using namespace std;

// Декларация
class Rational;

// Дефиниция
class Rational {
private:
	// GCD(numer, denom) == 1
	// denom > 0
	int numer, denom;

public:
	// конструктори
	//Rational();
	//Rational(int);
	Rational(int = 0, int = 1);
	Rational(Rational const&);
	Rational(double);

	// селектори
	int getNumerator() const;
	int getDenominator() const;
	void print(ostream& = cout) const;
	bool equals(Rational other) const;

	// мутатори
	void read(istream& = cin);

	// вградена функция
	Rational& invert() {
		int tmp = numer;
		numer = denom;
		denom = tmp;
		return *this;
	}

	// аритметични операции
	Rational operator+(Rational const&) const;
	Rational operator-() const; // -r
	Rational operator-(Rational const&) const;
	Rational operator*(Rational const&) const;
	Rational operator/(Rational const&) const;

	friend Rational operator+(int, Rational const&);

	// операции за преобразуване
	operator int() const;
	operator double() const;

private:
	// вътрешни операции
	void reduce();
	int gcd(int, int);
};

// аритметични операции
Rational add(Rational, Rational);
// !!! Rational* add_pointers(Rational const*, Rational const*);
Rational add_pointers(Rational const*, Rational const*);
Rational add_ref(Rational const&, Rational const&);

// операции за вход и изход
ostream& operator<<(ostream&, Rational const&);
istream& operator>>(istream&, Rational &);

#endif /* RATIONAL_H_ */
