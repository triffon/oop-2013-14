/*
 * abstract_stack.cpp
 *
 *  Created on: 06.06.2014
 *      Author: trifon
 */

#include "abstract_stack.h"

void AbstractStack::print(ostream& os) {
	// не можем да копираме!
	// !!! AbstractStack copy = *this;
	while(!empty())
		os << pop() << ' ';
	os << endl;
}


