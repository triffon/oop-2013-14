/*
 * point3d.cpp
 *
 *  Created on: 14.03.2014
 *      Author: trifon
 */

#include <iostream>
using namespace std;

#include "point3d.h"

Point3D::Point3D(Point2D p, double z) {
	// setX(p.getX());
	// Point3D::p.setX(p.getX());
	// this->p.setX(p.getX());
	// this->p.setY(p.getY());
	this->p = p;
	this->z = z;
}

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

void Point3D::setP(Point2D _p) {
	p = _p;
}

void Point3D::setZ(double _z) {
	z = _z;
}

void Point3D::reflectZ() {
	z = -z;
}

void Point3D::reflect() {
	p.reflect();
	reflectZ();
}

void Point3D::translate(Point3D q) {
	p.translate(q.p);
	z += q.z;
}

double Point3D::distance() const {
	// return distance(Point3D(0,0,0));
	/*
	 *
	 return sqrt(p.getX()*p.getX() +
			    p.getY()*p.getY() +
			    getZ()*getZ());
			    */
	/*
	double d = p.distance();
	return sqrt(d*d + getZ()*getZ());
	*/
	Point2D q(p.distance(), z);
	return q.distance();
}

double Point3D::distance(Point3D point) const {
	point.reflect();
	point.translate(*this);
	return point.distance();
}

Point3D::Point3D(double _x, double _y, double _z) {
	p = Point2D(_x, _y);
	z = _z;
}
