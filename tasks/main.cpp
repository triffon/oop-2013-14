/*
 * main.cpp
 *
 *  Created on: 06.06.2014
 *      Author: trifon
 */

#include "quick_task.h"
#include "simple_task.h"
#include "repeat_task.h"
#include "complex_task.h"

void printAll(Task** p, int n) {
	for(int i = 0; i < n; i++) {
		p[i]->print();
		cout << endl;
	}
}

void work(Task** tasks, int n) {
	int i = 0;
	int t;
	do {
		cout << '[' << tasks[i]->getProgress() << '/' <<
				tasks[i]->getLength() << "] ";
		cout << "t? ";
		cin >> t;
		tasks[i]->work(t);
		if (tasks[i]->isFinished())
			i++;
		printAll(tasks, n);
	} while (i < n && t > 0);
}

int main() {
	int const N = 6;
	ComplexTask* ct = new ComplexTask("лекции");
	ComplexTask* oop = new ComplexTask("лекции по ООП");
	oop->addTask(new SimpleTask("лекция с малко контролно", 3));
	oop->addTask(new RepeatTask("обикновени лекции по ООП", 2,
						new SimpleTask("лекция по ООП", 2)));
	ct->addTask(oop);
	ct->addTask(new RepeatTask("лекции по ЕАИ", 3,
					new SimpleTask("лекция по ЕАИ", 2)));
	ct->addTask(new QuickTask("влизане във ФМИ"));
	Task* tasks[N] = { new SimpleTask("събуждане", 2),
					new SimpleTask("обличане", 4),
					new QuickTask("излизане"),
					new RepeatTask("пътуване с ГТ", 2,
							new RepeatTask("пътуване с ГТ", 2,
									new RepeatTask("пътуване с ГТ", 2,
											new SimpleTask("пътуване с автобус", 3)))),
					ct,
					new QuickTask("усмивка")};


	work(tasks, N);

	ComplexTask* ct2 = new ComplexTask(*ct);
	delete oop;
	delete ct;
	delete ct2;

	return 0;
}

