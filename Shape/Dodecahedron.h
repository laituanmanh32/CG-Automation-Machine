/*
 * Dodecahedron.h
 *
 *  Created on: Apr 26, 2015
 *      Author: manh
 */

#ifndef DODECAHEDRON_H_
#define DODECAHEDRON_H_

#include "Shape.h"

class Dodecahedron: public Shape {
public:
	Dodecahedron();
	Dodecahedron(float);
	void setSize(float);
	virtual ~Dodecahedron();
private:
	void init(float);
};

#endif /* DODECAHEDRON_H_ */
