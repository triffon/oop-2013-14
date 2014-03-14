/*
 * point2d.h
 *
 *  Created on: 14.03.2014
 *      Author: trifon
 */

#ifndef POINT2D_H_
#define POINT2D_H_

class Point2D {
	double x, y;
public:
	// конструктори
	Point2D();
	Point2D(double, double);

	// селектори
	double getX() const;
	double getY() const;
	double distance() const;
	double distance(Point2D) const;
	void print() const;

	// мутатори
	void setX(double);
	void setY(double);
	// транслация с вектор
	void reflectX();
	void reflectY();
	void reflect();
	void translate(Point2D);
};



#endif /* POINT2D_H_ */
