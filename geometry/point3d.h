/*
 * point3d.h
 *
 *  Created on: 14.03.2014
 *      Author: trifon
 */

#ifndef POINT3D_H_
#define POINT3D_H_

#include "point2d.h"

class Point3D {
	Point2D p;
	double z;
public:
	// конструктори
	Point3D(); //
	Point3D(Point2D, double); //
	Point3D(double, double, double);

	// селектори
	Point2D getP() const; //
	double getZ() const; //
	double distance() const; //
	double distance(Point3D) const;
	void print() const; //

	// мутатори
	void setP(Point2D); //
	void setZ(double); //
	void translate(Point3D); //
	void reflectZ(); //
	void reflect(); //
};



#endif /* POINT3D_H_ */
