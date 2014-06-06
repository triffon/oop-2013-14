/*
 * printable.h
 *
 *  Created on: 06.06.2014
 *      Author: trifon
 */

#ifndef PRINTABLE_H_
#define PRINTABLE_H_

#include <iostream>
using namespace std;

class Printable {
public:
	virtual void print(ostream& = cout) const = 0;
	virtual ~Printable() {}
};



#endif /* PRINTABLE_H_ */
