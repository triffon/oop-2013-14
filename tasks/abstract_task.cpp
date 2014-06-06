/*
 * abstract_task.cpp
 *
 *  Created on: 06.06.2014
 *      Author: trifon
 */

#include "abstract_task.h"

#include <cstring>

AbstractTask::AbstractTask(char const* _name) {
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
}

AbstractTask::AbstractTask(AbstractTask const& at) {
	copy(at);
}

AbstractTask& AbstractTask::operator=(AbstractTask const& at) {
	if (this != &at) {
		clean();
		copy(at);
	}
	return *this;
}

AbstractTask::~AbstractTask() {
	clean();
}

void AbstractTask::copy(AbstractTask const& at) {
	name = new char[strlen(at.name) + 1];
	strcpy(name, at.name);
}

void AbstractTask::clean() {
	delete[] name;
}

void AbstractTask::print(ostream& os) const {
	os << "задача '" << name << "'";
}
