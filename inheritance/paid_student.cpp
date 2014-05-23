/*
 * paid_student.cpp
 *
 *  Created on: 16.05.2014
 *      Author: trifon
 */

#include "paid_student.h"
#include <cstring>

PaidStudent::PaidStudent(char const* _name,
		                 char const* _id,
		                 int _fn,
		                 double _grade,
		                 double _fee,
		                 char const* _sponsor)
 : Student(_name, _id, _fn, _grade),
   fee(_fee), sponsor(NULL) {
	cerr << "PaidStudent(...)" << endl;
	setSponsor(_sponsor);
}

PaidStudent::PaidStudent(PaidStudent const& ps)
  : Student(ps), sponsor(NULL) {
	cerr << "PaidStudent(PaidStudent const&)" << endl;
	copy(ps);
}

PaidStudent& PaidStudent::operator=(PaidStudent const& ps) {
	cerr << "operator=(PaidStudent const&)" << endl;
	if (this != &ps) {
		// Student::operator=(ps);
		//(Student &)*this = ps;
		*(Student*)this = ps;
		clean();
		copy(ps);
	}
	return *this;
}

PaidStudent::~PaidStudent() {
	cerr << "~PaidStudent()" << endl;
	clean();
}

void PaidStudent::print(ostream& os) const {
	Student::print(os);
	os << "Такса: " << fee << endl;
	os << "Спонсор: " << sponsor << endl;
}

void PaidStudent::setFee(double _fee) {
	fee = _fee;
}

void PaidStudent::setSponsor(char const* _sponsor) {
	if (sponsor != NULL)
		delete[] sponsor;
	sponsor = new char[strlen(_sponsor) + 1];
	strcpy(sponsor, _sponsor);
}

void PaidStudent::copy(PaidStudent const& ps) {
	// !!! Person::copy(ps);
	sponsor = NULL;
	setFee(ps.fee);
	setSponsor(ps.sponsor);
}

void PaidStudent::clean() {
	if (sponsor != NULL)
		delete[] sponsor;
}



