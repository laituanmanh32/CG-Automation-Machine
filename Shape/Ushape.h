/*
 * UShape.h
 *
 *  Created on: Apr 24, 2015
 *      Author: manh
 */

#ifndef USHAPE_H_
#define USHAPE_H_

#include "Shape.h"
#include "Cuboid.h"

class UShape: public Shape {
public:
	UShape();
	UShape(float fSizeX, float fSizeY, float fSizeZ, float fThick);
	virtual ~UShape();
	void setSize(float fSizeX, float fSizeY, float fSizeZ, float fThick);
private:
	void init(float fSizeX, float fSizeY, float fSizeZ, float fThick);
};

#endif /* USHAPE_H_ */
