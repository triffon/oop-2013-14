/*
 * main.cpp
 *
 *  Created on: 04.04.2014
 *      Author: trifon
 */

#include <iostream>
using namespace std;
#include "array.h"

int main() {
	double d[] = { 1.2, 2.3, 3.4, 4.5 };
	Array a(4, d);
	d[3] = 7; // ще променим и масива, ако споделяме памет!
	return 0;
}


