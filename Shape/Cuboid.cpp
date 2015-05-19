/*
 * Cuboid.cpp
 *
 *  Created on: Apr 24, 2015
 *      Author: manh
 */

#include "Cuboid.h"
Cuboid::Cuboid() {
	init(1, 1, 1);
}

Cuboid::~Cuboid() {
	// TODO Auto-generated destructor stub
}

Cuboid::Cuboid(float fSizeX, float fSizeY, float fSizeZ) {
	init( fSizeX, fSizeY, fSizeZ);
}

void Cuboid::setSize(float fSizeX, float fSizeY, float fSizeZ) {
	init( fSizeX, fSizeY, fSizeZ);
}

void Cuboid::init(float fSizeX, float fSizeY, float fSizeZ) {
	float x = fSizeX / 2;
	float y = fSizeY / 2;
	float z = fSizeZ / 2;

	numVerts = 8;
	pt = new Point3[numVerts];

	pt[0].set(x, y, z);
	pt[1].set(x, y, -z);
	pt[2].set(x, -y, z);
	pt[3].set(x, -y, -z);
	pt[4].set(-x, y, z);
	pt[5].set(-x, y, -z);
	pt[6].set(-x, -y, z);
	pt[7].set(-x, -y, -z);

	numFaces = 6;
	face = new Face[6];

	face[0].nVerts = 4;
	face[0].vert = new VertexID[4];
	face[0].vert[0].vertIndex = 0;
	face[0].vert[1].vertIndex = 4;
	face[0].vert[2].vertIndex = 6;
	face[0].vert[3].vertIndex = 2;

	face[1].nVerts = 4;
	face[1].vert = new VertexID[4];
	face[1].vert[0].vertIndex = 1;
	face[1].vert[1].vertIndex = 0;
	face[1].vert[2].vertIndex = 2;
	face[1].vert[3].vertIndex = 3;

	face[2].nVerts = 4;
	face[2].vert = new VertexID[4];
	face[2].vert[0].vertIndex = 5;
	face[2].vert[1].vertIndex = 1;
	face[2].vert[2].vertIndex = 3;
	face[2].vert[3].vertIndex = 7;

	face[3].nVerts = 4;
	face[3].vert = new VertexID[4];
	face[3].vert[0].vertIndex = 4;
	face[3].vert[1].vertIndex = 5;
	face[3].vert[2].vertIndex = 7;
	face[3].vert[3].vertIndex = 6;

	face[4].nVerts = 4;
	face[4].vert = new VertexID[4];
	face[4].vert[0].vertIndex = 5;
	face[4].vert[1].vertIndex = 4;
	face[4].vert[2].vertIndex = 0;
	face[4].vert[3].vertIndex = 1;

	face[5].nVerts = 4;
	face[5].vert = new VertexID[4];
	face[5].vert[0].vertIndex = 7;
	face[5].vert[1].vertIndex = 6;
	face[5].vert[2].vertIndex = 2;
	face[5].vert[3].vertIndex = 3;
}