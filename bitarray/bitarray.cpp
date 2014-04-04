/*
 * bitarray.cpp
 *
 *  Created on: 04.04.2014
 *      Author: trifon
 */

#include <iostream>
using namespace std;

#include "bitarray.h"

BitArray::BitArray(bit_type _a) : a(_a) {}

void BitArray::print() const {
	for(int i = getSize() - 1; i >= 0; i--) {
		cout << getBit(i);
	}
	cout << endl;
}

inline bit_type BitArray::buildMask(int n) const {
	bit_type mask = 1;
	// mask = mask << n;
	mask <<= n;
	return mask;
}

inline bit_type BitArray::buildNegativeMask(int n) const {
	return ~buildMask(n);
}

bool BitArray::getBit(int i) const {
	return (buildMask(i) & a) != 0;
}

void BitArray::setBit(int i) {
	a |= buildMask(i);
}

void BitArray::resetBit(int i) {
	a &= buildNegativeMask(i);
}
