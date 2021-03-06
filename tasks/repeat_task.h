/*
 * repeat_task.h
 *
 *  Created on: 06.06.2014
 *      Author: trifon
 */

#ifndef REPEAT_TASK_H_
#define REPEAT_TASK_H_

#include "simple_task.h"

class RepeatTask : public SimpleTask {
private:
	// прототип на повтаряната задача, само за четене, забранен за промяна
	Task const* prototype;

	// текущото копие на повтаряната задача
	Task *current;

	// интерпретираме progress като брой повторения до момента
	// интерпретираме length като брой повторения общо

	void reset();
public:

	RepeatTask(char const*, int, Task const*);

	// голяма тройка
	RepeatTask(RepeatTask const&);
	RepeatTask& operator=(RepeatTask const&);
	~RepeatTask();

	int getLength() const { return prototype->getLength() * length; }

	int getProgress() const;

	int work(int = 1);

	void print(ostream& = cout) const;

	Cloneable* clone() const { return new RepeatTask(*this); }

	bool isFinished() const { return SimpleTask::getLength() == SimpleTask::getProgress(); }

private:
	void copy(RepeatTask const&);
	void clean();
};



#endif /* REPEAT_TASK_H_ */
