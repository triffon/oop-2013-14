/*
 * bitarray.h
 *
 *  Created on: 04.04.2014
 *      Author: trifon
 */

#ifndef BITARRAY_H_
#define BITARRAY_H_

typedef unsigned long bit_type;

const int BITS_IN_BYTE = 8;

const int BIT_SIZE = sizeof(bit_type) * BITS_IN_BYTE;

class BitArray {
	bit_type a;
public:
	// конструктор
	BitArray(bit_type = 0);

	// селектори
	bool getBit(int) const;
	void print() const;
	int getSize() const { return BIT_SIZE; }

	// мутатори
	void setBit(int);   // = 1
	void resetBit(int); // = 0
private:
	// скрит селектор
	bit_type buildMask(int) const;
	bit_type buildNegativeMask(int) const;
};

#endif /* BITARRAY_H_ */
