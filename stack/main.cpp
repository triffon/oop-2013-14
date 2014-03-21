/*
 * main.cpp
 *
 *  Created on: 17.03.2014
 *      Author: trifon
 */

#include <iostream>
using namespace std;

#include "stack.h"
#include "rstack.h"
#include "lstack.h"

typedef LinkedStack MyStack;

void testStack() {
	MyStack s;
	for(int i = 1; i <= 100; i++)
		s.push(i);
	MyStack s2 = s;
	while (!s.empty())
		cout << s.pop() << endl;
	while (!s2.empty())
		cout << s2.pop() << endl;
	cout << "Живи сме!\n";
}

bool checkParentheses() {
	char c;
	MyStack s;
	do {
		cin >> c;
		switch(c) {
		case '(':
		case '[':
		case '{':
			s.push(c);
			break;
		case ')':
			if (s.empty() || s.pop() != '(')
				return false;
			break;
		case ']':
			if (s.empty() || s.pop() != '[')
				return false;
			break;
		case '}':
			if (s.empty() || s.pop() != '{')
				return false;
		}
	} while (c != '.');
	return s.empty();
}

int main() {
	testStack();
	if (checkParentheses())
		cout << "OK!" << endl;
	else
		cout << "FAIL!" << endl;
	return 0;
}
