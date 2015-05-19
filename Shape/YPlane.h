/*
 * Floor.h
 *
 *  Created on: Apr 25, 2015
 *      Author: manh
 */

#ifndef YPLANE_H_
#define YPLANE_H_

#include "Shape.h"

class YPlane: public Shape {
public:
	YPlane();
	YPlane(int, int, float, float);
	virtual ~YPlane();
private:
	void init(int, int, float, float);
};

#endif /* YPLANE_H_ */
