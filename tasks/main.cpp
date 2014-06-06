/*
 * main.cpp
 *
 *  Created on: 06.06.2014
 *      Author: trifon
 */

#include "quick_task.h"

void printAll(Task** p, int n) {
	for(int i = 0; i < n; i++) {
		p[i]->print();
		cout << endl;
	}
}

int main() {
	int const N = 3;
	Task* tasks[N] = { new QuickTask("събуждане"),
					new QuickTask("излизане"),
					new QuickTask("усмивка") };

	printAll(tasks, N);

	tasks[2]->work();
	tasks[0]->work();

	printAll(tasks, N);

	return 0;
}

