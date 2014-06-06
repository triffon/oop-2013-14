/*
 * simple_task.h
 *
 *  Created on: 06.06.2014
 *      Author: trifon
 */

#ifndef SIMPLE_TASK_H_
#define SIMPLE_TASK_H_

#include "abstract_task.h"

class SimpleTask : public AbstractTask {
protected:
	int length, progress;
public:

	SimpleTask(char const* = "SimpleTask", int = 1);

	int getLength() const { return length; }

	int getProgress() const { return progress; }

	int work(int = 1);

	void print(ostream& = cout) const;

	Cloneable* clone() const { return new SimpleTask(*this); }
};



#endif /* SIMPLE_TASK_H_ */
