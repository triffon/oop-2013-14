/*
 * task.h
 *
 *  Created on: 06.06.2014
 *      Author: trifon
 */

#ifndef TASK_H_
#define TASK_H_

#include "printable.h"

class Task : public Printable {
public:
	// дължина на задачата в единици време
	virtual int length() const = 0;

	// прогрес на задачата в единици време от началото ѝ
	virtual int getProgress() const = 0;

	// извършване на работа по задачата
	// параметър: брой единици време, които се работи по задачата
	// резултат: оставащи брой единици свободно време
	virtual int work(int = 1) = 0;

};



#endif /* TASK_H_ */
