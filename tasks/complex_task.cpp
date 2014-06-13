/*
 * complex_task.cpp
 *
 *  Created on: 13.06.2014
 *      Author: trifon
 */

#include "complex_task.h"

ComplexTask::ComplexTask(char const* _name) : AbstractTask(_name),
	progress(0), length(0)
{}

void ComplexTask::print(ostream& os) const {
	os << "Сложна ";
	AbstractTask::print(os);
	os << ", която съдържа следните подзадачи: <";
	StackElement<Task*> *p = top;
	while(p != NULL) {
		p->data->print(os);
		os << ", ";
		p = p->next;
	}
	os << '>';
}

bool ComplexTask::addTask(Task const* task) {
	if (progress > 0)
		return false;
	length += task->getLength();
	return push((Task*)task->clone());
}

Task* ComplexTask::pop() {
	Task* lastTask = last();
	delete lastTask;
	return LinkedStack<Task*>::pop();
}

int ComplexTask::work(int t) {
	int tstart = t;
	if (t > 0 && !empty()) {
		t = last()->work(t);
	}
	// t == 0 || empty()
	while (t > 0 && !empty()) {
		pop();
		if (!empty())
			t = last()->work(t);
	}
	// t == 0 || empty()
	if (t == 0 && !empty() && last()->isFinished())
		pop();
	progress += tstart - t;
	return t;
}

ComplexTask::ComplexTask(ComplexTask const& ct) :
		AbstractTask(ct),
		LinkedStack<Task*>(ct) {
	copy(ct);
}

ComplexTask& ComplexTask::operator=(ComplexTask const& ct) {
	if (this != &ct) {
		AbstractTask::operator=(ct);
		LinkedStack<Task*>::operator=(ct);
		clean();
		copy(ct);
	}
	return *this;
}

ComplexTask::~ComplexTask() {
	clean();
}

void ComplexTask::copy(ComplexTask const& ct) {
	progress = ct.progress;
	length = ct.length;
	StackElement<Task*> *p = top;
	while (p != NULL) {
		p->data = (Task*)p->data->clone();
		p = p->next;
	}
}

void ComplexTask::clean() {
	StackElement<Task*> *p = top;
	while (p != NULL) {
		delete p->data;
		p = p->next;
	}
}
