/*
 * quick_task.cpp
 *
 *  Created on: 06.06.2014
 *      Author: trifon
 */

#include "quick_task.h"

QuickTask::QuickTask(char const* _name)
  : AbstractTask(_name), finished(false)
{}

int QuickTask::getProgress() const {
	return finished ? 1 : 0;
	// може и:
	// return finished;
}

void QuickTask::print(ostream& os) const {
	os << "бърза ";
	AbstractTask::print(os);
	os << ", която ";
	if (!finished)
		os << "НЕ ";
	os << "е завършена";
}

int QuickTask::work(int t) {
	if (!finished) {
		finished = true;
		t--;
	}
	return t;
}
