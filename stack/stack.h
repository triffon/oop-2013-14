
/*

 * stack.h
 *
 *  Created on: 17.03.2014
 *      Author: trifon
 */

#ifndef STACK_H_
#define STACK_H_

const int MAX_STACK = 100;

class Stack {
private:
	int a[MAX_STACK]; // самият стек
	int top; // индекс на последния включен в стека елемент
			 // индекс на върха на стека
public:

	Stack(); // create

	// проверка дали стек е празен
	bool empty() const;

	// включване на нов елемент
	bool push(int);

	// изключване на елемент
	int pop();

	// връщане на върха на стека
	int last() const;

private:
	bool full() const;
};


#endif /* STACK_H_ */
