/*
 * main.cpp
 *
 *  Created on: 17.03.2014
 *      Author: trifon
 */

#include <iostream>
using namespace std;

void test() {
	int* p = new int;
	*p = 3;
	int* q = p;
	*q = 4;
	cout << *q << endl;
	int const* r = p;
	// !!! *r = 5;
	cout << *r << endl;
	// !!! p = q = r = NULL;

	double *x;
	{{{{x = new double[10];}}}}
	{ double a[10]; cin >> a[3]; }
	x[1] = 4;
	for(int i = 0; i < 10; i++)
		cin >> x[i];
}

double* resize(double* a, int& capacity) {
	int newcapacity = capacity * 2;
	cerr << "Увеличаваме капацитета от " << capacity << " на " << newcapacity << endl;
	double * newa = new double[newcapacity];
	for(int i = 0; i < capacity; i++)
		newa[i] = a[i];
	delete[] a;
	capacity = newcapacity;
	return newa;
}

void findDuplicates() {
	int capacity = 10;
	double* a = new double[capacity];
	int count = 0;
	double x;
	do {
		cin >> x;
		a[count++] = x;
		if (count == capacity)
			a = resize(a, capacity);
	} while(x != 0);

	int i = 0, j = count;
	while (i < count - 1 && j == count) {
		j = i + 1;
		while (j < count && a[i] != a[j])
			j++;
		// j == count -> не се повтаря
		// j < count -> намерили сме повторение
		i++;
	}
	// j < count намерили сме повторение
	if (j < count)
		cout << "Има повторение!";
	else
		cout << "Няма повторение!";
	delete[] a;
}

void transposeMatrix() {
	int n, m;
	cin >> m >> n;
	// m реда
	// n стълба
	int** a = new int*[m]; // указатели към редовете
	for(int i = 0; i < m; i++)
		a[i] = new int[n]; // създаваме всеки ред поотделно!

	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			cin >> a[i][j];

	// n реда
	// m стълба
	int** b = new int*[n];
	for(int i = 0; i < n; i++)
		b[i] = new int[m];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			b[i][j] = a[j][i];

	for(int i = 0; i < m; i++)
		delete[] a[i];
	delete[] a;

	// позволено!!!
	a = b; // но как да изтрия старата матрица???

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
//
}

void memoryLeak() {
	const int MAX = 1000000;
	for(int i = 0; i < MAX; i++) {
		double *a = new double[MAX];
		for(int j = 0; j < MAX; j++)
			a[j] = 0;
		cout << "Step #" << i << endl;
		cin.get();

		delete[] a;
	}
	cout << "Done!" << endl;
	cin.get();

}

int main() {
	// findDuplicates();
	// transposeMatrix();
	memoryLeak();
	return 0;
}


