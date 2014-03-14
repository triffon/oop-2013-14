/*
 * point3d.cpp
 *
 *  Created on: 14.03.2014
 *      Author: trifon
 */

#include <iostream>
using namespace std;

#include "point3d.h"

Point3D::Point3D() {
	p.setX(0);
	p.setY(0);
	z = 0;
}

Point2D Point3D::getP() const {
	return p;
}

double Point3D::getZ() const {
	return z;
}

void Point3D::print() const {
	cout << '[';
	p.print();
	cout << ';' << z << ']';
}
