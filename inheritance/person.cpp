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
	cerr << "Person(...)" << endl;
	setName(_name);
	setID(_id);
}

void Person::copy(Person const& p) {
	name = NULL;
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

Person::Person(Person const& p) : name(NULL) {
	cerr << "Person(Person const&)" << endl;
	copy(p);
}

Person& Person::operator=(Person const& p) {
	cerr << "operator=(Person const&)" << endl;
	if (this != &p) {
		clean();
		copy(p);
	}
	return *this;
}

Person::~Person() {
	cerr << "~Person()" << endl;
	clean();
}

void Person::print(ostream& os) const {
	os << *this;
}

ostream& operator<<(ostream& os, Person const& p) {
	os << "Име: " << p.getName() << endl;
	os << "ЕГН: " << p.getID() << endl;
	return os;
}

void Person::prettyPrint() const {
  cout << "---------- [ Personal file ] -----------" << endl;
  // this->print();
  print();
  cout << "----------------------------------------" << endl;
}
