/*
 * point2d.cpp
 *
 *  Created on: 14.03.2014
 *      Author: trifon
 */

#include <cmath>
#include <iostream>
using namespace std;

#include "point2d.h"

Point2D::Point2D() {
	x = y = 0;
}

Point2D::Point2D(double _x, double _y) {
	x = _x;
	y = _y;
}

double Point2D::getX() const {
	return x;
}

double Point2D::getY() const {
	return y;
}

double Point2D::distance() const {
	return sqrt(getX()*getX() + getY()*getY());

}

double Point2D::distance(Point2D point) const {
	point.reflect();
	point.translate(*this);
	return point.distance();
}

void Point2D::reflectX() {
	setX(-getX());
}

void Point2D::reflectY() {
	setY(-getY());
}

void Point2D::reflect() {
	reflectX();
	reflectY();
}

void Point2D::setX(double _x) {
	x = _x;
}

void Point2D::setY(double _y) {
	y = _y;
}

void Point2D::print() const {
	cout << '(' << x << ',' << y << ')';
}

void Point2D::translate(Point2D point) {
	//x += point.getX();
	//y += point.getY();
	setX(getX() + point.getX());
	setY(getY() + point.getY());
}
