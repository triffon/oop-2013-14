/*
 * cloneable.h
 *
 *  Created on: 06.06.2014
 *      Author: trifon
 */

#ifndef CLONEABLE_H_
#define CLONEABLE_H_

class Cloneable {
public:
	virtual Cloneable* clone() const = 0;
	virtual ~Cloneable() {};
};



#endif /* CLONEABLE_H_ */
