/*
 * lstack.cpp
 *
 *  Created on: 21.03.2014
 *      Author: trifon
 */

#include <cstddef>

#include "lstack.h"

LinkedStack::LinkedStack() {
	top = NULL;
}

bool LinkedStack::empty() const {
	return top == NULL;
}

bool LinkedStack::push(int x) {
	StackElement* el = new StackElement;
	el->data = x;
	el->next = top;
	top = el;
	return true;
}

int LinkedStack::last() const {
	if (empty())
		return -1;
	return top->data;
}

int LinkedStack::pop() {
	if (empty())
		return -1;
	// top != NULL
	StackElement* el = top;
	top = top->next;
	int x = el->data;
	delete el;
	return x;
}
