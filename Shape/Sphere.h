/*
 * Sphere.h
 *
 *  Created on: Apr 24, 2015
 *      Author: manh
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include "Shape.h"

class Sphere: public Shape {
public:
	Sphere();
	Sphere(float size);
	virtual ~Sphere();
	void setSize(float size);
private:
	void init(int nSlice, int nStack, float radius);
};

#endif /* SPHERE_H_ */
