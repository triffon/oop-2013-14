/*
 * rational_point.h
 *
 *  Created on: 28.03.2014
 *      Author: trifon
 */

#ifndef RATIONAL_POINT_H_
#define RATIONAL_POINT_H_

#include "rational.h"

class RationalPoint {
	Rational x, y;
public:
	RationalPoint();
	RationalPoint(Rational const&, Rational const&);
	RationalPoint(RationalPoint const&);
};


#endif /* RATIONAL_POINT_H_ */
