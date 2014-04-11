/*
 * rResizingStack.cpp
 *
 *  Created on: 17.03.2014
 *      Author: trifon
 */

#include "rstack.h"
#include <iostream>
using namespace std;

ResizingStack::ResizingStack() {
	top = -1;
	a = new int[INIT_CAPACITY];
	capacity = INIT_CAPACITY;
}

ResizingStack::ResizingStack(ResizingStack const& rs) {
	copy(rs);
}

void ResizingStack::copy(ResizingStack const& rs) {
	top = rs.top;
	capacity = rs.capacity;
	a = new int[capacity];
	// прехвърляме елементите
	for(int i = 0; i <= top; i++)
		a[i] = rs.a[i];
}

bool ResizingStack::empty() const {
	return top == -1;
}

bool ResizingStack::full() const {
	return top == capacity - 1;
}

int ResizingStack::pop() {
	if (empty())
		return 0;
	return a[top--];
}

int ResizingStack::last() const {
	if (empty())
		return 0;
	return a[top];
}

bool ResizingStack::push(int x) {
	if (full())
		resize();
	a[++top] = x;
	return true;
}

void ResizingStack::resize() {
	capacity *= 2;
	cerr << "Разширяваме стека до " << capacity << " елемента!\n";

	int* newa = new int[capacity];

	// копираме данните от стария стек
	for(int i = 0; i < capacity / 2; i++)
		newa[i] = a[i];

	delete[] a;

	a = newa;
}

ResizingStack::~ResizingStack() {
	clean();
}

void ResizingStack::clean() {
	delete[] a;
}

ResizingStack& ResizingStack::operator=(ResizingStack const& rs) {
	if (this != &rs) {
		clean();
		copy(rs);
	}
	return *this;
}
