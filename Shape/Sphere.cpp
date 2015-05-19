/*
 * Sphere.cpp
 *
 *  Created on: Apr 24, 2015
 *      Author: manh
 */

#include "Sphere.h"

Sphere::Sphere() {
	this->init(3 / 0.1, 3 / 0.1, 3);

}

Sphere::Sphere(float size) {
	this->setSize(size);
}

Sphere::~Sphere() {
	// TODO Auto-generated destructor stub
}

void Sphere::setSize(float size) {
	this->init(size / (size < 0.5 ? 0.02 : 0.05),
	           size / (size < 0.5 ? 0.02 : 0.05), size);
	this->setPosition(0, size, 0);
}

void Sphere::init(int nSlice, int nStack, float radius) {
	int i, k;
	float fRadius;

	numVerts = 2 + nSlice * (nStack - 1);
	pt = new Point3[numVerts];
	pt[numVerts - 2].set(0, 0, radius); // The Nearest Point
	pt[numVerts - 1].set(0, 0, -radius); // The Farthest Point
	for (i = 0; i < nStack - 1; ++i) {
		fRadius = radius * sin((i + 1) * PI / nStack);
		for (k = 0; k < nSlice; ++k) {
			pt[i * nSlice + k].set(fRadius * cos(k * 2 * PI / nSlice),
			                       fRadius * sin(k * 2 * PI / nSlice),
			                       radius * cos((i + 1) * PI / nStack));
		}
	}

	numFaces = nSlice * nStack;
	face = new Face[numFaces];

	//The Nearest Slice
	for (i = 0; i < nSlice; ++i) {
		face[i].nVerts = 3;
		face[i].vert = new VertexID[3];
		face[i].vert[0].vertIndex = numVerts - 2;
		face[i].vert[1].vertIndex = i;
		face[i].vert[2].vertIndex = (i + 1) % nSlice;
	}
	//Internal Slices
	int c, d;
	for (k = 1; k < nStack - 1; ++k) {
		for (i = 0; i < nSlice; ++i) {
			c = k * nSlice + i;
			d = k * nSlice + ((i + 1) % nSlice);
			face[k * nSlice + i].nVerts = 4;
			face[k * nSlice + i].vert = new VertexID[4];
			face[k * nSlice + i].vert[0].vertIndex = d - nSlice;
			face[k * nSlice + i].vert[1].vertIndex = c - nSlice;
			face[k * nSlice + i].vert[2].vertIndex = c;
			face[k * nSlice + i].vert[3].vertIndex = d;
		}
	}
	//The Farthest Slice
	for (i = numFaces - nSlice; i < numFaces; ++i) {
		face[i].nVerts = 3;
		face[i].vert = new VertexID[3];
		face[i].vert[0].vertIndex = numVerts - 1;
		face[i].vert[1].vertIndex = face[i - nSlice].vert[3].vertIndex;
		face[i].vert[2].vertIndex = face[i - nSlice].vert[2].vertIndex;
	}
}