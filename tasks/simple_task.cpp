/*
 * simple_task.cpp
 *
 *  Created on: 06.06.2014
 *      Author: trifon
 */

#include "simple_task.h"

SimpleTask::SimpleTask(char const* _name, int _length)
  : AbstractTask(_name), length(_length), progress(0)
{}

void SimpleTask::print(ostream& os) const {
	os << "проста ";
	AbstractTask::print(os);
	os << ", която е с напредък " << progress;
	os << " от " << length;
}

int SimpleTask::work(int t) {
	if (progress + t >= length) {
		// времето e достатъчно за завършване
		// на задачата
		t -= length - progress;
		progress = length;
	} else {
		// времето не е достатъчно!
		progress += t;
		t = 0;
	}
	return t;
}


