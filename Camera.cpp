/*
 * Camera.cpp
 *
 *  Created on: Apr 24, 2015
 *      Author: manh
 */

#include "Camera.h"

#include <GL/glut.h>
#include <cmath>
#include <cstdio>

#define		PI			3.1415926
#define		DEG2RAD(x)	(x*PI)/180.0f

Camera::Camera() {
	camera_angle = 0.0;
	camera_height = 2.0;
	camera_dis = 11;
	b4View = true;
	this->screenHeight = 600;
	this->screenWidth = 800;
}
Camera::Camera(float screenWidth, float screenHeight) {
	camera_angle = 0.0;
	camera_height = 2.0;
	camera_dis = 11;
	b4View = true;
	this->screenHeight = screenHeight;
	this->screenWidth = screenWidth;
}

Camera::~Camera() {
	// TODO Auto-generated destructor stub
}

void Camera::onKeyPressed(unsigned char key, int x, int y) {
	switch (key) {
	case 'v':
	case 'V':
		b4View = !b4View;
		break;
	case '+':
		camera_dis += 0.1;
		break;
	case '-':
		camera_dis -= 0.1;
		break;
	}
	glutPostRedisplay();
}
void Camera::onFuncKeyPressed(int key, int x, int y) {

	switch (key) {
	case GLUT_KEY_UP:
		camera_height = camera_height + 0.1;
		break;
	case GLUT_KEY_DOWN:
		camera_height = camera_height - 0.1;
		break;
	case GLUT_KEY_LEFT:
		camera_angle += 2;
		break;
	case GLUT_KEY_RIGHT:
		camera_angle -= 2;
		break;
	}
	glutPostRedisplay();
}

void Camera::DisplayOneView(int nType, int left, int right, int top,
		int bottom) {
	SetupCameraVolume(nType);
	glViewport(left, top, right - left, bottom - top);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	switch (nType) {
	case 1:
		gluLookAt(0, camera_dis, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
		break;
	case 2:
		gluLookAt(0, 0.0, camera_dis, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		break;
	case 3:
		gluLookAt(camera_dis, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		break;
	case 4:
		gluLookAt(camera_dis * cosf(DEG2RAD(camera_angle)), camera_height,
				camera_dis * sinf(DEG2RAD(camera_angle)), 0.0, 0.0, 0.0, 0.0,
				1.0, 0.0);
		break;
	}
}
void Camera::SetupCameraVolume(int nType) {
	if (nType == 4) {
		glMatrixMode(GL_PROJECTION);	// set projection matrix current matrix
		glLoadIdentity();						// reset projection matrix

		// calculate aspect ratio of window
		gluPerspective(60.0f, (GLfloat) screenWidth / (GLfloat) screenHeight,
				1.0f, 1000.0f);
	} else {
		glMatrixMode(GL_PROJECTION);	// set projection matrix current matrix
		glLoadIdentity();						// reset projection matrix
		glOrtho(-5, 5, -5, 5, -1000, 1000);
	}
}

void Camera::configDisplay(GraphicObjectManager gom) {
	if (b4View == false) {
		this->DisplayOneView(4, 0, screenWidth, 0, screenHeight);
		gom.draw(false);
	} else {
		this->DisplayOneView(1, 0, screenWidth / 2, 0, screenHeight / 2);
		gom.draw(false);
		this->DisplayOneView(2, 0, screenWidth / 2, screenHeight / 2,
				screenHeight);
		gom.draw(false);
		this->DisplayOneView(3, screenWidth / 2, screenWidth, screenHeight / 2,
				screenHeight);
		gom.draw(false);
		this->DisplayOneView(4, screenWidth / 2, screenWidth, 0,
				screenHeight / 2);
		gom.draw(false);
	}
}
