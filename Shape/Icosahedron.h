/*
 * Icosahedron.h
 *
 *  Created on: Apr 26, 2015
 *      Author: manh
 */

#ifndef ICOSAHEDRON_H_
#define ICOSAHEDRON_H_

#include "Shape.h"

class Icosahedron: public Shape {
public:
	Icosahedron();
	Icosahedron(float);
	void setSize(float);
	virtual ~Icosahedron();
private:
	void init(float);
};

#endif /* ICOSAHEDRON_H_ */
