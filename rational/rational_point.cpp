/*
 * rational_point.cpp
 *
 *  Created on: 28.03.2014
 *      Author: trifon
 */

#include <iostream>
using namespace std;

#include "rational_point.h"

RationalPoint::RationalPoint() {
	cout << "Конструктор RationalPoint()\n";
}

RationalPoint::RationalPoint(Rational const& _x, Rational const& _y)
	: x(_x), y(_y) {
	cout << "Конструктор RationalPoint с параметри: ";
	_x.print(); cout << " , "; _y.print(); cout << endl;
	// !!!x = _x;
	// !!! y = _y;
}
