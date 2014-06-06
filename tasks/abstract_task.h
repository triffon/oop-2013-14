/*
 * abstact_task.h
 *
 *  Created on: 06.06.2014
 *      Author: trifon
 */

#ifndef ABSTACT_TASK_H_
#define ABSTACT_TASK_H_

#include "task.h"

class AbstractTask : public Task {
private:
	char* name;
public:

	// голяма четворка
	AbstractTask(char const* _name = "неизвестна");
	AbstractTask(AbstractTask const&);
	AbstractTask& operator=(AbstractTask const&);
	~AbstractTask();

	// селектор
	char const* getName() const { return name; }

	// извеждане
	void print(ostream& = cout) const;

	bool isFinished() const {
		return getLength() == getProgress();
	}

	// !!!! Cloneable* clone() const { return new AbstractTask(*this); }

private:
	void copy(AbstractTask const&);
	void clean();
};



#endif /* ABSTACT_TASK_H_ */
