/*
 * person.h
 *
 *  Created on: 09.05.2014
 *      Author: trifon
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
using namespace std;
#include "printable.h"

const int EGN_SIZE = 11;

class Person : public Printable {
	char* name;
	char id[EGN_SIZE];
public:

	// голяма четворка
	Person(char const* ="", char const* ="0");
	Person(Person const&);
	Person& operator=(Person const&);
	virtual ~Person();

	// селектори
	char const* getName() const { return name; }
	char const* getID() const { return id; }

	// мутатори
	void setName(char const*);

	// извеждане
	virtual void print(ostream& = cout) const;
	void prettyPrint() const;
private:
	void copy(Person const&);
	void clean();
protected:
	void setID(char const*);
};

ostream& operator<<(ostream&, Person const&);

#endif /* PERSON_H_ */
