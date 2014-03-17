/*
 * stack.cpp
 *
 *  Created on: 17.03.2014
 *      Author: trifon
 */

#include "stack.h"

Stack::Stack() {
	top = -1;
}

bool Stack::empty() const {
	return top == -1;
}

bool Stack::full() const {
	return top == MAX_STACK - 1;
}

bool Stack::push(int x) {
	if (full())
		return false;
	a[++top] = x;
	return true;
}

int Stack::pop() {
	if (empty())
		return 0;
	return a[top--];
}

int Stack::last() const {
	if (empty())
		return 0;
	return a[top];
}
