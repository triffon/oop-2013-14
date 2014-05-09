/*
 * point2d.cpp
 *
 *  Created on: 14.03.2014
 *      Author: trifon
 */

#include <cmath>
#include <iostream>
using namespace std;



#ifndef POINT2D_CPP_
#define POINT2D_CPP_

template <typename T>
class Point2D {
	T x, y;
public:
	// конструктори
	Point2D();
	Point2D(T const&, T const&);

	// селектори
	T getX() const;
	T getY() const;
	double distance() const;
	double distance(Point2D) const;
	void print(ostream& = cout) const;

	// мутатори
	void setX(T const&);
	void setY(T const&);
	// транслация с вектор
	void reflectX();
	void reflectY();
	void reflect();
	void translate(Point2D);
};

template <typename T>
Point2D<T>::Point2D() {
	x = y = 0;
}

template <typename T>
Point2D<T>::Point2D(T const& _x, T const& _y) {
	x = _x;
	y = _y;
}

template <typename T>
T Point2D<T>::getX() const {
	return x;
}

template <typename T>
T Point2D<T>::getY() const {
	return y;
}

template <typename T>
double Point2D<T>::distance() const {
	return sqrt(getX()*getX() + getY()*getY());

}

template <typename T>
double Point2D<T>::distance(Point2D<T> point) const {
	point.reflect();
	point.translate(*this);
	return point.distance();
}

template <typename T>
void Point2D<T>::reflectX() {
	setX(-getX());
}

template <typename T>
void Point2D<T>::reflectY() {
	setY(-getY());
}

template <typename T>
void Point2D<T>::reflect() {
	reflectX();
	reflectY();
}

template <typename T>
void Point2D<T>::setX(T const& _x) {
	x = _x;
}

template <typename T>
void Point2D<T>::setY(T const& _y) {
	y = _y;
}

template <typename T>
void Point2D<T>::print(ostream& os) const {
	os << '(' << x << ',' << y << ')';
}

template <typename T>
ostream& operator<<(ostream& os, Point2D<T> const& p) {
	p.print(os);
}

template <typename T>
void Point2D<T>::translate(Point2D<T> point) {
	//x += point.getX();
	//y += point.getY();
	setX(getX() + point.getX());
	setY(getY() + point.getY());
}


#endif /* POINT2D_CPP_ */
