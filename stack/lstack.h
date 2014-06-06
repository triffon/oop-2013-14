
/*

 * lstack.h
 *
 *  Created on: 17.03.2014
 *      Author: trifon
 */

#ifndef LSTACK_H_
#define LSTACK_H_

#include "abstract_stack.h"


struct StackElement {
	int data;
	StackElement* next;
};

class LinkedStack : public AbstractStack {
private:
	StackElement* top;
			  //  самият стек, т.е. указател към
			  // последния включен в стека елемент
public:

	LinkedStack(); // create
	LinkedStack(LinkedStack const&);

	// проверка дали стек е празен
	bool empty() const;

	// включване на нов елемент
	bool push(int);

	// изключване на елемент
	int pop();

	// връщане на върха на стека
	int last() const;

	// деструктор
	~LinkedStack();

	// операция за присвояване
	LinkedStack& operator=(LinkedStack const&);

private:

	// копиране
	void copy(LinkedStack const&);

	// изчистване
	void clean();
};


#endif /* STACK_H_ */
