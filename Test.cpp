// Lab3.cpp : Defines the entry point for the console application.
//

#include <GL/gl.h>

#include "Camera.h"
#include "EventDispatcher.h"
#include "GraphicObjectManager.h"
#include "Machine.h"
#include "Shape/Dodecahedron.h"
#include "Shape/YPlane.h"
#include "Shape/Icosahedron.h"
#include "Shape/Shape.h"
#include "Shape/Sphere.h"

using namespace std;

#define PI		3.1415926

int screenWidth = 600;
int screenHeight = 600;

bool bWireFrame = false;

EventDispatcher event;
GraphicObjectManager gom;
Camera* camera;

void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	camera->configDisplay(gom);
//	test->draw(false);
//	sphere->draw(false);

	glFlush();
	glutSwapBuffers();
}

void myInit() {
	float fHalfSize = 3;

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glFrontFace(GL_CCW);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-fHalfSize, fHalfSize, -fHalfSize, fHalfSize, -1000, 1000);

	glMatrixMode(GL_MODELVIEW);
}

void onKeyPressed(unsigned char key, int x, int y) {
	event.onKeyPressed(key, x, y);
}

void onFuncKeyPress(int key, int x, int y) {
	event.onFuncKeyPressed(key, x, y);
}

void onTime(int x) {
	event.onTime(x);
	glutTimerFunc(10, onTime, 0);
}

int main(int argc, char* argv[]) {

	glutInit(&argc, (char**) argv); //initialize the tool kit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //set the display mode
	glutInitWindowSize(screenWidth, screenHeight); //set window size
	glutInitWindowPosition(100, 100); // set window position on screen
	glutCreateWindow("Assignment 1 - Lai Tuan Manh (51202099)"); // open the screen window

	Machine* test = new Machine();
	camera = new Camera(screenWidth, screenHeight);
	YPlane* plane = new YPlane();
	Sphere* sphere = new Sphere();
	Icosahedron* ico = new Icosahedron(0.3);
	Dodecahedron* dod = new Dodecahedron(0.3);

	sphere->setSize(0.5);
	sphere->CreateRandomColor();
	sphere->setPosition(4,0.5,4);

	ico->CreateRandomColor();
	ico->setPosition(-4,0.5,4);

	dod->setPosition(-4,0.5,-4);
	dod->CreateRandomColor();

	test->setPosition(0,0.1,0);

	event.addKeyboardListener(test);
	event.addKeyboardListener(camera);
	event.addTimeListener(test);

	gom.add(test);
	gom.add(plane);
	gom.add(sphere);
	gom.add(ico);
	gom.add(dod);

	myInit();
	glutDisplayFunc(myDisplay);
	glutKeyboardFunc(onKeyPressed);
	glutSpecialFunc(onFuncKeyPress);
	glutTimerFunc(10, onTime, 0);

	glutMainLoop();
	return 0;
}

