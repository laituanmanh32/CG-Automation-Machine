/*
 * Icosahedron.cpp
 *
 *  Created on: Apr 26, 2015
 *      Author: manh
 */

#include "Icosahedron.h"

Icosahedron::Icosahedron() {
	this->init(1);

}

Icosahedron::Icosahedron(float size) {
	this->init(size);

}

Icosahedron::~Icosahedron() {
	// TODO Auto-generated destructor stub
}

void Icosahedron::setSize(float size) {
	this->init(size);
}

void Icosahedron::init(float size) {
	numFaces = 20;
	numVerts = 12;

	float A = 1 * size;
	float B = 1.618033989 * size;
	pt = new Point3[numVerts];

	pt[0].set(-A, 0, B);
	pt[1].set(A, 0, B);
	pt[2].set(-A, 0, -B);
	pt[3].set(A, 0, -B);
	pt[4].set(0, B, A);
	pt[5].set(0, B, -A);
	pt[6].set(0, -B, A);
	pt[7].set(0, -B, -A);
	pt[8].set(B, A, 0);
	pt[9].set(-B, A, 0);
	pt[10].set(B, -A, 0);
	pt[11].set(-B, -A, 0);

	face = new Face[numFaces];
	face[0].nVerts = 3;
	face[0].vert = new VertexID[3];
	face[0].vert[0].vertIndex = 1;
	face[0].vert[1].vertIndex = 4;
	face[0].vert[2].vertIndex = 0;

	face[1].nVerts = 3;
	face[1].vert = new VertexID[3];
	face[1].vert[0].vertIndex = 4;
	face[1].vert[1].vertIndex = 9;
	face[1].vert[2].vertIndex = 0;

	face[2].nVerts = 3;
	face[2].vert = new VertexID[3];
	face[2].vert[0].vertIndex = 4;
	face[2].vert[1].vertIndex = 5;
	face[2].vert[2].vertIndex = 9;

	face[3].nVerts = 3;
	face[3].vert = new VertexID[3];
	face[3].vert[0].vertIndex = 8;
	face[3].vert[1].vertIndex = 5;
	face[3].vert[2].vertIndex = 4;

	face[4].nVerts = 3;
	face[4].vert = new VertexID[3];
	face[4].vert[0].vertIndex = 1;
	face[4].vert[1].vertIndex = 8;
	face[4].vert[2].vertIndex = 4;

	face[5].nVerts = 3;
	face[5].vert = new VertexID[3];
	face[5].vert[0].vertIndex = 1;
	face[5].vert[1].vertIndex = 10;
	face[5].vert[2].vertIndex = 8;

	face[6].nVerts = 3;
	face[6].vert = new VertexID[3];
	face[6].vert[0].vertIndex = 10;
	face[6].vert[1].vertIndex = 3;
	face[6].vert[2].vertIndex = 8;

	face[7].nVerts = 3;
	face[7].vert = new VertexID[3];
	face[7].vert[0].vertIndex = 8;
	face[7].vert[1].vertIndex = 3;
	face[7].vert[2].vertIndex = 5;

	face[8].nVerts = 3;
	face[8].vert = new VertexID[3];
	face[8].vert[0].vertIndex = 3;
	face[8].vert[1].vertIndex = 2;
	face[8].vert[2].vertIndex = 5;

	face[9].nVerts = 3;
	face[9].vert = new VertexID[3];
	face[9].vert[0].vertIndex = 3;
	face[9].vert[1].vertIndex = 7;
	face[9].vert[2].vertIndex = 2;

	face[10].nVerts = 3;
	face[10].vert = new VertexID[3];
	face[10].vert[0].vertIndex = 3;
	face[10].vert[1].vertIndex = 10;
	face[10].vert[2].vertIndex = 7;

	face[11].nVerts = 3;
	face[11].vert = new VertexID[3];
	face[11].vert[0].vertIndex = 10;
	face[11].vert[1].vertIndex = 6;
	face[11].vert[2].vertIndex = 7;

	face[12].nVerts = 3;
	face[12].vert = new VertexID[3];
	face[12].vert[0].vertIndex = 6;
	face[12].vert[1].vertIndex = 11;
	face[12].vert[2].vertIndex = 7;

	face[13].nVerts = 3;
	face[13].vert = new VertexID[3];
	face[13].vert[0].vertIndex = 6;
	face[13].vert[1].vertIndex = 0;
	face[13].vert[2].vertIndex = 11;

	face[14].nVerts = 3;
	face[14].vert = new VertexID[3];
	face[14].vert[0].vertIndex = 6;
	face[14].vert[1].vertIndex = 1;
	face[14].vert[2].vertIndex = 0;

	face[15].nVerts = 3;
	face[15].vert = new VertexID[3];
	face[15].vert[0].vertIndex = 10;
	face[15].vert[1].vertIndex = 1;
	face[15].vert[2].vertIndex = 6;

	face[16].nVerts = 3;
	face[16].vert = new VertexID[3];
	face[16].vert[0].vertIndex = 11;
	face[16].vert[1].vertIndex = 0;
	face[16].vert[2].vertIndex = 9;

	face[17].nVerts = 3;
	face[17].vert = new VertexID[3];
	face[17].vert[0].vertIndex = 2;
	face[17].vert[1].vertIndex = 11;
	face[17].vert[2].vertIndex = 9;

	face[18].nVerts = 3;
	face[18].vert = new VertexID[3];
	face[18].vert[0].vertIndex = 5;
	face[18].vert[1].vertIndex = 2;
	face[18].vert[2].vertIndex = 9;

	face[19].nVerts = 3;
	face[19].vert = new VertexID[3];
	face[19].vert[0].vertIndex = 11;
	face[19].vert[1].vertIndex = 2;
	face[19].vert[2].vertIndex = 7;
}