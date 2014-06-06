/*
 * rstack.h
 *
 *  Created on: 17.03.2014
 *      Author: trifon
 */

#ifndef RSTACK_H_
#define RSTACK_H_

#include "abstract_stack.h"

const int INIT_CAPACITY = 10;

class ResizingStack : public AbstractStack{
private:
	int* a; // самият стек
	int top; // индекс на последния включен в стека елемент
			 // индекс на върха на стека
	int capacity; // капацитет на стека
public:

	ResizingStack(); // create
	ResizingStack(ResizingStack const&);

	// проверка дали стек е празен
	bool empty() const;

	// включване на нов елемент
	bool push(int);

	// изключване на елемент
	int pop();

	// връщане на върха на стека
	int last() const;

	// деструктор
	~ResizingStack();

	// операция за присвояване
	ResizingStack& operator=(ResizingStack const&);

private:
	// проверка дали стек е пълен
	bool full() const;

	// разширяване на капацитета
	void resize();

	// копиране
	void copy(ResizingStack const&);

	// изчистване
	void clean();
};


#endif /* RSTACK_H_ */
