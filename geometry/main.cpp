/*
 * main.cpp
 *
 *  Created on: 14.03.2014
 *      Author: trifon
 */

#include <iostream>
using namespace std;

#include "point2d.h"

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
			(distanceTest() ? "OK" : "FAILED!");

	return 0;
}


