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

LinkedStack::LinkedStack(LinkedStack const& ls) {
	/* !!! неправилно !!!
	top = NULL;
	while(!ls.empty())
		push(ls.pop());
		*/
	if (ls.empty())
		top = NULL;
	else {
		// първа стъпка
		top = new StackElement;
		top->data = ls.top->data;

		// подготовка за втората стъпка
		StackElement* toCopy = ls.top->next;
		StackElement* lastCopy = top;

		while (toCopy != NULL) {
			// копиране
			StackElement* newCopy = new StackElement;
			newCopy->data = toCopy->data;

			// завързване
			lastCopy->next = newCopy;

			// подготовка за следващата стъпка
			toCopy = toCopy->next;
			lastCopy = newCopy;
		}
		// затваряме веригата
		lastCopy->next = NULL;
	}
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

LinkedStack::~LinkedStack() {
	// !!! delete top; // не е достатъчно!
	while (!empty())
		pop();
	// за домашно: директна реализация
}
