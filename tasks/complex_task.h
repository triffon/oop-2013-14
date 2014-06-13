/*
 * complex_task.h
 *
 *  Created on: 13.06.2014
 *      Author: trifon
 */

#ifndef COMPLEX_TASK_H_
#define COMPLEX_TASK_H_

#include "abstract_task.h"
#include "lstack.cpp"

class ComplexTask : public AbstractTask, protected LinkedStack<Task*> {
private:
	int progress, length;
public:

	ComplexTask(char const* = "ComplexTask");
	ComplexTask(ComplexTask const&);
	ComplexTask& operator=(ComplexTask const&);
	~ComplexTask();

	int getLength() const { return length; }

	int getProgress() const { return progress; }

	int work(int = 1);

	void print(ostream& = cout) const;

	bool addTask(Task const*);

	Cloneable* clone() const { return new ComplexTask(*this); }

	Task* pop();
private:
	void copy(ComplexTask const&);
	void clean();
};

#endif /* COMPLEX_TASK_H_ */
