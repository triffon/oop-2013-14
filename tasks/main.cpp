/*
 * main.cpp
 *
 *  Created on: 06.06.2014
 *      Author: trifon
 */

#include "quick_task.h"
#include "simple_task.h"
#include "repeat_task.h"

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
		cout << "t? ";
		cin >> t;
		tasks[i]->work(t);
		if (tasks[i]->isFinished())
			i++;
		printAll(tasks, n);
	} while (i < n && t > 0);
}

int main() {
	int const N = 5;
	Task* tasks[N] = { new SimpleTask("събуждане", 2),
					new SimpleTask("обличане", 4),
					new QuickTask("излизане"),
					new RepeatTask("пътуване с ГТ", 2, new SimpleTask("пътуване с автобус", 3)),
					new QuickTask("усмивка")};


	work(tasks, N);

	return 0;
}

