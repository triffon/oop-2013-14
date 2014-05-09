/*
 * main.cpp
 *
 *  Created on: 09.05.2014
 *      Author: trifon
 */

#include <iostream>
using namespace std;

#include "person.h"

int main() {
	Person p("Иван Иванов", "8311100123");
	p.setName("Петър Петров");
	cout << p.getID() << endl;
	p.print();
}


