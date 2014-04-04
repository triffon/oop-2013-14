/*
 * bitarray_main.cpp
 *
 *  Created on: 04.04.2014
 *      Author: trifon
 */

#include <iostream>
using namespace std;

#include "bitarray.h"

int main() {
	BitArray a(42);
	a.print();
	a.setBit(2);
	a.print();
	a.resetBit(3);
	a.print();
	return 0;
}

