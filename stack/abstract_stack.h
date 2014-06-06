/*
 * abstract_stack.h
 *
 *  Created on: 06.06.2014
 *      Author: trifon
 */

#ifndef ABSTRACT_STACK_H_
#define ABSTRACT_STACK_H_

#include "printable.h"

class AbstractStack : public Printable {
public:
	// проверка дали стек е празен
	virtual bool empty() const = 0;

	// включване на нов елемент
	virtual bool push(int) = 0;

	// изключване на елемент
	virtual int pop() = 0;

	// връщане на върха на стека
	virtual int last() const = 0;

	// виртуален деструктор
	virtual ~AbstractStack() {}

	// извеждане
	void print(ostream& = cout);
};



#endif /* ABSTRACT_STACK_H_ */
