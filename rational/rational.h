/*
 * rational.h
 *
 *  Created on: 07.03.2014
 *      Author: trifon
 */

#ifndef RATIONAL_H_
#define RATIONAL_H_

class Rational {
private:
	int numer, denom;

public:
	// конструктори
	Rational();
	Rational(int, int);

	// селектори
	int getNumerator() const;
	int getDenominator() const;
	void print() const;

	// мутатори
	void read();

private:
	// вътрешни операции
	void reduce();
	int gcd(int, int);
};

// аритметични операции
Rational add(Rational, Rational);


#endif /* RATIONAL_H_ */
