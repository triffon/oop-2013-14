/*
 * main.cpp
 *
 *  Created on: 14.03.2014
 *      Author: trifon
 */

#include <iostream>
using namespace std;

#include "point2d.h"
#include "point3d.h"
#include "pyramid.h"

bool distanceTest() {
	Point2D p(10, 11), q(7, 15);
	return p.distance(q) == 5;
}

int main() {
	Point2D p(1, 2);
	p.translate(Point2D(3, 5));
	p.print();cout << endl;
	cout << p.distance() << endl;
	Point2D q = p;
	q.translate(Point2D(-3, 4));
	cout << p.distance(q) << endl;

	cout << "Running unit test for distance: " <<
			(distanceTest() ? "OK" : "FAILED!") << endl;

	Point3D p3(Point2D(1, 2), 3);
	Point3D q3(Point2D(3, 4), 12);
	Point3D r3 = p3;
	r3.translate(q3);
	cout << "Разстоянието между p3 и r3 е: " <<
			p3.distance(r3) << endl;

	Pyramid py(3, 4, 12);
	cout << py.volume() << endl;
	cout << py.isInside(Point3D(1,1,1)) << endl;
	return 0;
}


