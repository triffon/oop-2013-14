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
#include "lstack.cpp"

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

typedef LinkedStack<int> MyStack;

void testStack() {
	MyStack s;
	for(int i = 1; i <= 10; i++)
		s.push(i);
	MyStack s2 = s;
	cout << "s:\n";
	while (!s.empty())
		cout << s.pop() << endl;
	MyStack s3;
	s3 = s;
	for(int i = 11; i <= 20; i++)
			s.push(i);
	cout << "s2:\n";
	while (!s2.empty())
		cout << s2.pop() << endl;
	cout << "Живи сме!\n";
}

void testPointStack() {
	LinkedStack<Point2D<int> > s;
	s.push(Point2D<int>(1, 2));
	s.push(Point2D<int>(2, 3));
	s.push(Point2D<int>(3, 4));
	while (!s.empty())
		cout << s.pop();
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

template <typename T>
ostream& operator<<(ostream& os, LinkedStack<T> s) {
	while (!s.empty()) {
		os << '[' << s.pop() << ']';
	}
	os << endl;
	return os;
}

void testStackStack() {
	LinkedStack<LinkedStack<Rational> > ss;
	for(int i = 1; i <= 10; i++) {
		LinkedStack<Rational> s;
		for(int j = 1; j <= 10; j++) {
			Rational r(i * j, (i+1)*(j+1));
			s.push(r);
		}
		ss.push(s);
	}
	cerr << ss;
}

int main() {

	// testTemplates();
	// testPoint();
	// testStack();
	// testPointStack();
	testStackStack();

	return 0;
}

