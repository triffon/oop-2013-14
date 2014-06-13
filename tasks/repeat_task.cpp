/*
 * repeat_task.cpp
 *
 *  Created on: 06.06.2014
 *      Author: trifon
 */

#include "repeat_task.h"

void RepeatTask::reset() {
	if (current != NULL)
		delete current;
	current = (Task*)prototype->clone();
}

RepeatTask::RepeatTask(char const* _name, int _iterations,
		               Task const* _prototype) :
		SimpleTask(_name, _iterations), prototype(_prototype),
		current(NULL) {
	reset();
}

void RepeatTask::print(ostream& os) const {
	os << "повтаряща се ";
	AbstractTask::print(os);
	os << ", която е повторила {";
	prototype->print(os);
	os << "} " << progress << " пъти от общо " << length;
	os << ", като текущата задача е с прогрес " << current->getProgress();
}

int RepeatTask::getProgress() const {
	return SimpleTask::getProgress() * prototype->getLength() +
			 current->getProgress();
}

int RepeatTask::work(int t) {
	if (t > 0 && !isFinished()) {
		t = current->work(t);
	}
	// current->isFinished() || t == 0
	// isFinished() <-> всички итерации са завършени
	while (t > 0 && !isFinished()) {
		reset();
		SimpleTask::work(); // отбелязваме една завършена итерация
		t = current->work(t);
	}
	// t == 0 || isFinished()
	if (t == 0 && current->isFinished()) {
		// Времето е свършило изцяло
		reset();
		SimpleTask::work();
	}
	return t;
}
