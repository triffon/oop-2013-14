/*
 * main.cpp
 *
 *  Created on: 11.04.2014
 *      Author: trifon
 */

#include <iostream>
using namespace std;

#include "point2d.cpp"
#include "rational.h"

template <typename T>
void swap2(T& a, T& b) {
  cout << "Шаблон\n";
  T tmp = a; a = b; b = tmp;
}

void swap2(int& a, int& b) {
	cout << "Специализация\n";
	a += b;
	b = a - b;
	a = a - b;
}

template <typename T>
void reverse(T* a, int n) {
  for(int i = 0; i < n/2; i++)
    swap2(a[i], a[n-i-1]);
}

template <typename T>
void f(T x) {
	cout << x % 5;
}

void testTemplates() {
	int x = 3, y = 5;
	//swap2<int>(x, y);
	swap2(x, y);
	int* px = &x, *py = &y;
	// swap2<int*>(px, py);
	swap2(px, py);
	// !!! swap2<double>(px, py);
	cout << x << ' ' << y << endl;
	cout << *px << ' ' << *py << endl;
//	f(3.5);
}

template <>
double Point2D<Rational>::distance() const {
	return sqrt((double)(getX()*getX() + getY()*getY()));
}

void testPoint() {
	Point2D<int> p(1,5);
	Point2D<double> q(2.3,3.4);
	Point2D<char> r('a','b');
	p.print();
	q.print();
	r.print();
	Point2D<Point2D<double> > s(q, q);
	s.print();
	Point2D<Rational> a(Rational(3,5), Rational(4,5));
	a.print();cout << endl;
	cout << a.distance() << endl;
}

int main() {

	// testTemplates();
	testPoint();

	return 0;
}

