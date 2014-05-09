/*
 * person.cpp
 *
 *  Created on: 09.05.2014
 *      Author: trifon
 */

#include <cstring>
#include "person.h"

Person::Person(char const* _name, char const* _id)
	: name(NULL) {
	setName(_name);
	setID(_id);
}

void Person::copy(Person const& p) {
	setName(p.name);
	setID(p.id);
}

void Person::setID(char const* _id) {
	strncpy(id, _id, EGN_SIZE);
	id[EGN_SIZE-1] = '\0';
}

void Person::setName(char const* _name) {
	if (name != NULL)
		delete[] name;
	name = new char[strlen(_name)+1];
	strcpy(name, _name);
}

void Person::clean() {
	if (name != NULL)
		delete[] name;
}

Person::Person(Person const& p) {
	copy(p);
}

Person& Person::operator=(Person const& p) {
	if (this != &p) {
		clean();
		copy(p);
	}
	return *this;
}

Person::~Person() {
	clean();
}

void Person::print(ostream& os) const {
	os << "Име: " << name << endl;
	os << "ЕГН: " << id << endl;
}
