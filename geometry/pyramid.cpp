/*
 * pyramid.cpp
 *
 *  Created on: 17.03.2014
 *      Author: trifon
 */

#include "pyramid.h"

Pyramid::Pyramid() {
	p = Point3D(1, 1, 1);
}

Pyramid::Pyramid(double _a, double _b, double _c) {
	p = Point3D(_a, _b, _c);
}

double Pyramid::volume() const {
	return getA() * getB() * getC() / 6;
}

bool Pyramid::isInside(Point3D point) const {
	return point.getP().getX() >= 0 &&
		   point.getP().getY() >= 0 &&
		   point.getZ() >= 0 &&
		   point.getP().getX() / getA() +
		   point.getP().getY() / getB() +
		   point.getZ() / getC() <= 1;
}
