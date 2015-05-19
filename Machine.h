/*
 * Machine.h
 *
 *  Created on: Apr 24, 2015
 *      Author: manh
 */

#ifndef MACHINE_H_
#define MACHINE_H_

#include "KeyboardListener.h"
#include "Shape/Cuboid.h"
#include "Shape/Cylinder.h"
#include "Shape/Sphere.h"
#include "Shape/UShape.h"
#include "TimeListener.h"

class Machine: public KeyboardListener, public Shape, public TimeListener {
private:
	int size;
	bool isAnimation;
	int bodyAngle;
	int axis1Angle;
	int axis2Angle;

	bool bWireFrame;

	float machineBaseRadius;
	float machineBaseHeight;
	float machineBaseRotateAngle;

	float machineBodyXZ;
	float machineBodyY;

	float machineAxis1Radius;
	float machineAxis1Height;
	float machineAxis1Offset;
	float machineAxis1RotateAngle;

	float machineBracketX;
	float machineBracketY;
	float machineBracketZ;
	float machineBracketThick;

	float cylAxis2X;
	float cylAxis2Y;
	float cylAxis2Z;

	float wheelRadius;
	float wheelHeight;
	float wheelRotateAngle;

	float pX, pY, pZ;

	Cylinder machineBase;
	Cuboid machineBody;
	Cylinder machineAxis1;
	Cuboid machineAxis2;
	UShape machineBracket;
	Cylinder machineWheel;
	Sphere machineBall;

	void reCal();
	void init();

public:
	Machine();
	virtual ~Machine();
	void setSize(int size);
	void setPosition(float fX, float fY, float fZ);
	void draw(bool isWireframe = false);
	void drawSefl(bool isWireframe = false);

	void onKeyPressed(unsigned char key, int x, int y);
	void onFuncKeyPressed(int key, int x, int y);
	void onKey();
	void onTime(int);
	void animation();
};

#endif /* MACHINE_H_ */
