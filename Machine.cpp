/*
 * Machine.cpp
 *
 *  Created on: Apr 24, 2015
 *      Author: manh
 */

#include "Machine.h"

#include <GL/gl.h>
#include <cstdio>

#include "Shape/Shape.h"

Machine::Machine() {
	size = 1;
	isAnimation = false;

	bodyAngle = 1;
	axis1Angle = 2 * bodyAngle;
	axis2Angle = 3 * bodyAngle;

	bWireFrame = false;

	machineBaseRadius = 1.2;
	machineBaseHeight = 0.2;
	machineBaseRotateAngle = 0.0;

	machineBodyXZ = 0.3;
	machineBodyY = 3;

	machineAxis1Radius = 0.1;
	machineAxis1Height = 0.3;
	machineAxis1Offset = 0.2;
	machineAxis1RotateAngle = 0;

	machineBracketX = 1.6;
	machineBracketY = 0.3;
	machineBracketZ = 1.4;
	machineBracketThick = 0.1;

	cylAxis2X = machineBracketX - 2 * machineBracketThick;
	cylAxis2Y = 0.1;
	cylAxis2Z = 0.1;

	wheelRadius = 0.7;
	wheelHeight = 0.1;
	wheelRotateAngle = 0.0;

	pX = pY = pZ = 0;

	this->init();
}

Machine::~Machine() {
	// TODO Auto-generated destructor stub
}

void Machine::setSize(int size) {
	this->size = size;
	this->reCal();
	this->init();
}

void Machine::init() {
	machineBase.setSize(machineBaseHeight, machineBaseRadius);
	machineBase.setPosition(pX, pY + machineBaseHeight / 2, pZ);
	machineBase.SetColor(1);

	machineBody.setSize(machineBodyXZ, machineBodyY, machineBodyXZ);
	machineBody.setPosition(0, machineBaseHeight/2 + machineBodyY / 2.0, 0);
	machineBody.SetColor(0);

	machineAxis1.setSize(machineAxis1Height, machineAxis1Radius);
	machineAxis1.setPosition(0, machineBodyY / 2 - machineAxis1Offset,
			machineAxis1Height / 2 + machineBodyXZ / 2);
	machineAxis1.SetColor(2);

	machineBracket.setSize(machineBracketX, machineBracketY, machineBracketZ,
			machineBracketThick);
	machineBracket.setPosition(0, 0,
			machineBracketZ / 2 + machineAxis1Height / 2);
	machineBracket.SetColor(3);

	machineAxis2.setSize(cylAxis2X, cylAxis2Y, cylAxis2Z);
	machineAxis2.setPosition(0, 0, machineBracketZ / 4);
	machineAxis2.SetColor(4);

	machineWheel.setSize(wheelHeight, wheelRadius);
	machineWheel.SetColor(5);

	machineBall.setSize(0.2);

}

void Machine::draw(bool isWireframe) {
	glPushMatrix();
	glRotatef(machineBaseRotateAngle, 0, 1, 0);
	glTranslatef(machineBase.slideX, machineBase.slideY, machineBase.slideZ);
	machineBase.draw(isWireframe);

	glTranslatef(machineBody.slideX, machineBody.slideY, machineBody.slideZ);
	machineBody.draw(isWireframe);

	glTranslatef(machineAxis1.slideX, machineAxis1.slideY, machineAxis1.slideZ);
	glRotatef(90, 1, 0, 0);
	glRotatef(machineAxis1RotateAngle, 0, 1, 0);
	machineAxis1.draw(isWireframe);

	glRotatef(-90, 1, 0, 0);
	glTranslatef(machineBracket.slideX, machineBracket.slideY,
			machineBracket.slideZ);
	machineBracket.draw((isWireframe));

	glTranslatef(machineAxis2.slideX, machineAxis2.slideY, machineAxis2.slideZ);
	glRotatef(wheelRotateAngle, 1, 0, 0);
	machineAxis2.draw(isWireframe);

	glRotated(90, 0, 0, 1);
	machineWheel.draw(isWireframe);

	glTranslatef(0, 0, wheelRadius / 2);
	machineBall.SetColor(9);
	machineBall.draw(isWireframe);
	glTranslatef(0, 0, -wheelRadius / 2);

	glRotatef(120, 0, 1, 0);
	glTranslatef(0, 0, wheelRadius / 2);
	machineBall.SetColor(9);
	machineBall.draw(isWireframe);
	glTranslatef(0, 0, -wheelRadius / 2);

	glRotatef(120, 0, 1, 0);
	glTranslatef(0, 0, wheelRadius / 2);
	machineBall.SetColor(9);
	machineBall.draw(isWireframe);
	glTranslatef(0, 0, -wheelRadius / 2);

	glPopMatrix();
}

void Machine::drawSefl(bool isWireframe){
	this->draw(isWireframe);
}

void Machine::reCal() {
	machineBaseRadius *= size;
	machineBaseHeight *= size;

	machineBodyXZ *= size;
	machineBodyY *= size;

	machineAxis1Radius *= size;
	machineAxis1Height *= size;
	machineAxis1Offset *= size;

	machineBracketX *= size;
	machineBracketY *= size;
	machineBracketZ *= size;

	cylAxis2X *= size;
	cylAxis2Y *= size;
	cylAxis2Z *= size;

	wheelRadius *= size;
	wheelHeight *= size;
}

void Machine::setPosition(float fX, float fY, float fZ) {
	this->pX = fX;
	this->pY = fY;
	this->pZ = fZ;
	init();
}

void Machine::onKeyPressed(unsigned char key, int x, int y) {

	if (key == 'a' || key == 'A') {
		isAnimation = !isAnimation;
	}

	if (isAnimation)
		return;
	switch (key) {
	case '1':
		machineBaseRotateAngle += 2;
		if (machineBaseRotateAngle > 360)
			machineBaseRotateAngle -= 360;
		break;
	case '2':
		machineBaseRotateAngle -= 2;
		if (machineBaseRotateAngle < 0)
			machineBaseRotateAngle += 360;
		break;
	case '3':
		machineAxis1RotateAngle += 2;
		if (machineAxis1RotateAngle > 360)
			machineAxis1RotateAngle -= 360;
		break;
	case '4':
		machineAxis1RotateAngle -= 2;
		if (machineAxis1RotateAngle < 0)
			machineAxis1RotateAngle += 360;
		break;
	case '5':
		wheelRotateAngle += 2;
		if (wheelRotateAngle > 360)
			wheelRotateAngle -= 360;
		break;
	case '6':
		wheelRotateAngle -= 2;
		if (wheelRotateAngle < 0)
			wheelRotateAngle += 360;
		break;
	}
	glutPostRedisplay();
}
void Machine::onFuncKeyPressed(int key, int x, int y) {

}

void Machine::animation() {
	if (!isAnimation)
		return;

	machineBaseRotateAngle += bodyAngle;
	if (machineBaseRotateAngle >= 360 || machineBaseRotateAngle <= 0)
		bodyAngle = -bodyAngle;

	machineAxis1RotateAngle += axis1Angle;
	if (machineAxis1RotateAngle >= 360 || machineAxis1RotateAngle <= 0)
		axis1Angle = -axis1Angle;

	wheelRotateAngle += axis2Angle;
	if (wheelRotateAngle >= 360 || wheelRotateAngle <= 0)
		axis2Angle = -axis2Angle;
	glutPostRedisplay();
}

void Machine::onTime(int value){
	this->animation();
}
