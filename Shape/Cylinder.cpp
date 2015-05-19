/*
 * Cylinder.cpp
 *
 *  Created on: Apr 24, 2015
 *      Author: manh
 */

#include "Cylinder.h"

Cylinder::Cylinder() {
	this->setSize(1, 1);
}

Cylinder::~Cylinder() {
	// TODO Auto-generated destructor stub
}

void Cylinder::setSize(float fHeight, float fRadius) {
	this->init(360 * (fRadius < 0.3 ? fRadius / 3 : fRadius / 10), fHeight,
	           fRadius);
}

Cylinder::Cylinder(float fHeight, float fRadius) {
	this->init(360 * (fRadius < 0.3 ? fRadius / 3 : fRadius / 10), fHeight,
	           fRadius);
}

void Cylinder::init(int nSegment, float fHeight, float fRadius) {
	numVerts = nSegment * 2 + 2;
	pt = new Point3[numVerts];

	float y = fHeight / 2;
	pt[numVerts - 2].set(0, y, 0);
	pt[numVerts - 1].set(0, -y, 0);

	// x = rcos
	// y = y
	// z = rsin
	for (int i = 0; i < (nSegment); i++) {
		float x = fRadius * cosf(2 * PI / nSegment * i);
		float z = -fRadius * sinf(2 * PI / nSegment * i);
		pt[i].set(x, y, z);
		pt[nSegment + i].set(x, -y, z);
	}

	numFaces = 3 * nSegment;
	face = new Face[numFaces];
	for (int i = 0; i < nSegment; i++) {

		int top1 = i;
		int top2 = (i + 1) % nSegment;
		int bot1 = top1 + nSegment;
		int bot2 = top2 + nSegment;

		// top
		face[i].nVerts = 3;
		face[i].vert = new VertexID[3];
		face[i].vert[0].vertIndex = numVerts - 2;
		face[i].vert[1].vertIndex = top1;
		face[i].vert[2].vertIndex = top2;

		// around
		face[i + nSegment].nVerts = 4;
		face[i + nSegment].vert = new VertexID[4];
		face[i + nSegment].vert[0].vertIndex = top1;
		face[i + nSegment].vert[1].vertIndex = top2;
		face[i + nSegment].vert[2].vertIndex = bot2;
		face[i + nSegment].vert[3].vertIndex = bot1;

		// bottom
		face[i + nSegment * 2].nVerts = 3;
		face[i + nSegment * 2].vert = new VertexID[3];
		face[i + nSegment * 2].vert[0].vertIndex = numVerts - 1;
		face[i + nSegment * 2].vert[1].vertIndex = bot1;
		face[i + nSegment * 2].vert[2].vertIndex = bot2;
	}
}
