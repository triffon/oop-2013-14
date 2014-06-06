/*
 * quick_task.h
 *
 *  Created on: 06.06.2014
 *      Author: trifon
 */

#ifndef QUICK_TASK_H_
#define QUICK_TASK_H_

#include "abstract_task.h"

class QuickTask : public AbstractTask {
private:
	bool finished;
public:
	QuickTask(char const* = "QuickTask");

	int length() const { return 1; }

	int getProgress() const;

	int work(int = 1);

	void print(ostream& = cout) const;
};


#endif /* QUICK_TASK_H_ */
