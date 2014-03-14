/*
 * rational.h
 *
 *  Created on: 07.03.2014
 *      Author: trifon
 */

#ifndef RATIONAL_H_
#define RATIONAL_H_

// Декларация
class Rational;

// Дефиниция
class Rational {
private:
	int numer, denom;

public:
	// конструктори
	Rational();
	Rational(int);
	Rational(int, int);

	// селектори
	int getNumerator() const;
	int getDenominator() const;
	void print() const;
	bool equals(Rational other) const;

	// мутатори
	void read();
	// вградена функция
	void invert() {
		int tmp = numer;
		numer = denom;
		denom = tmp;
	}

private:
	// вътрешни операции
	void reduce();
	int gcd(int, int);
};

// аритметични операции
Rational add(Rational, Rational);


#endif /* RATIONAL_H_ */
