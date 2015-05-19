/*
 * Cylinder.h
 *
 *  Created on: Apr 24, 2015
 *      Author: manh
 */

#ifndef CYLINDER_H_
#define CYLINDER_H_

#include "Shape.h"

class Cylinder: public Shape {
public:
	Cylinder();
	Cylinder(float fHeight, float fRadius);
	virtual ~Cylinder();

	void setSize(float fHeight, float fRadius);
private:
	void init(int nSegment,float fHeight, float fRadius);
};

#endif /* CYLINDER_H_ */
