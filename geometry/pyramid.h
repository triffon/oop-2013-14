/*
 * pyramid.h
 *
 *  Created on: 17.03.2014
 *      Author: trifon
 */

#ifndef PYRAMID_H_
#define PYRAMID_H_

#include "point3d.h"

class Pyramid {
private:
	Point3D p;
public:
	// конструктори
	Pyramid();
	Pyramid(double, double, double);

	// селектори
	double getA() const {
		return p.getP().getX();
	}
	double getB() const {
		return p.getP().getY();
	}
	double getC() const {
		return p.getZ();
	}

	// мутатори
	double setA(double _a) {
		// !!! p.getP().setX(_a);
		Point2D q = p.getP();
		q.setX(_a);
		p.setP(q);
	}

	double setB(double _b) {
		// !!! p.getP().setY(_b);
		Point2D q = p.getP();
		q.setY(_b);
		p.setP(q);
	}

	double setC(double _c) {
		p.setZ(_c);
	}

	// операции
	// намиране на обем
	double volume() const;
	// проверка дали точка е вътре
	bool isInside(Point3D) const;

};


#endif /* PYRAMID_H_ */
