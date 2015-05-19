/*
 * Dodecahedron.cpp
 *
 *  Created on: Apr 26, 2015
 *      Author: manh
 */

#include "Dodecahedron.h"

Dodecahedron::Dodecahedron() {
	this->init(1);
}

Dodecahedron::Dodecahedron(float size) {
	this->init(size);
}

Dodecahedron::~Dodecahedron() {
	// TODO Auto-generated destructor stub
}

void Dodecahedron::setSize(float size){
	init(size);
}

void Dodecahedron::init(float size){
	numVerts = 20;
	numFaces = 12;
	pt = new Point3[numVerts];

	float A = 1.618033989*size;
	float B = 1/1.618033989 *size;
	float C = size;

	pt[0].set(C, C, C);
	pt[1].set(C, C, -C);
	pt[2].set(C, -C, C);
	pt[3].set(C, -C, -C);
	pt[4].set(-C, C, C);
	pt[5].set(-C, C, -C);
	pt[6].set(-C, -C, C);
	pt[7].set(-C, -C, -C);

	pt[8].set(0, B, A);
	pt[9].set(0, B, -A);
	pt[10].set(0, -B, A);
	pt[11].set(0, -B, -A);

	pt[12].set(B, A, 0);
	pt[13].set(B, -A, 0);
	pt[14].set(-B, A, 0);
	pt[15].set(-B, -A, 0);

	pt[16].set(A, 0, B);
	pt[17].set(A, 0, -B);
	pt[18].set(-A, 0, B);
	pt[19].set(-A, 0, -B);

	face = new Face[numFaces];

	face[0].nVerts = 5;
	face[0].vert = new VertexID[5];
	face[0].vert[0].vertIndex = 0;
	face[0].vert[1].vertIndex = 16;
	face[0].vert[2].vertIndex = 2;
	face[0].vert[3].vertIndex = 10;
	face[0].vert[4].vertIndex = 8;

	face[1].nVerts = 5;
	face[1].vert = new VertexID[5];
	face[1].vert[0].vertIndex = 0;
	face[1].vert[1].vertIndex = 8;
	face[1].vert[2].vertIndex = 4;
	face[1].vert[3].vertIndex = 14;
	face[1].vert[4].vertIndex = 12;

	face[2].nVerts = 5;
	face[2].vert = new VertexID[5];
	face[2].vert[0].vertIndex = 16;
	face[2].vert[1].vertIndex = 17;
	face[2].vert[2].vertIndex = 1;
	face[2].vert[3].vertIndex = 12;
	face[2].vert[4].vertIndex = 0;

	face[3].nVerts = 5;
	face[3].vert = new VertexID[5];
	face[3].vert[0].vertIndex = 1;
	face[3].vert[1].vertIndex = 9;
	face[3].vert[2].vertIndex = 11;
	face[3].vert[3].vertIndex = 3;
	face[3].vert[4].vertIndex = 17;

	face[4].nVerts = 5;
	face[4].vert = new VertexID[5];
	face[4].vert[0].vertIndex = 1;
	face[4].vert[1].vertIndex = 12;
	face[4].vert[2].vertIndex = 14;
	face[4].vert[3].vertIndex = 5;
	face[4].vert[4].vertIndex = 9;

	face[5].nVerts = 5;
	face[5].vert = new VertexID[5];
	face[5].vert[0].vertIndex = 2;
	face[5].vert[1].vertIndex = 13;
	face[5].vert[2].vertIndex = 15;
	face[5].vert[3].vertIndex = 6;
	face[5].vert[4].vertIndex = 10;

	face[6].nVerts = 5;
	face[6].vert = new VertexID[5];
	face[6].vert[0].vertIndex = 13;
	face[6].vert[1].vertIndex = 3;
	face[6].vert[2].vertIndex = 17;
	face[6].vert[3].vertIndex = 16;
	face[6].vert[4].vertIndex = 2;

	face[7].nVerts = 5;
	face[7].vert = new VertexID[5];
	face[7].vert[0].vertIndex = 3;
	face[7].vert[1].vertIndex = 11;
	face[7].vert[2].vertIndex = 7;
	face[7].vert[3].vertIndex = 15;
	face[7].vert[4].vertIndex = 13;

	face[8].nVerts = 5;
	face[8].vert = new VertexID[5];
	face[8].vert[0].vertIndex = 4;
	face[8].vert[1].vertIndex = 8;
	face[8].vert[2].vertIndex = 10;
	face[8].vert[3].vertIndex = 6;
	face[8].vert[4].vertIndex = 18;

	face[9].nVerts = 5;
	face[9].vert = new VertexID[5];
	face[9].vert[0].vertIndex = 14;
	face[9].vert[1].vertIndex = 5;
	face[9].vert[2].vertIndex = 19;
	face[9].vert[3].vertIndex = 18;
	face[9].vert[4].vertIndex = 4;

	face[10].nVerts = 5;
	face[10].vert = new VertexID[5];
	face[10].vert[0].vertIndex = 5;
	face[10].vert[1].vertIndex = 19;
	face[10].vert[2].vertIndex = 7;
	face[10].vert[3].vertIndex = 11;
	face[10].vert[4].vertIndex = 9;

	face[11].nVerts = 5;
	face[11].vert = new VertexID[5];
	face[11].vert[0].vertIndex = 15;
	face[11].vert[1].vertIndex = 7;
	face[11].vert[2].vertIndex = 19;
	face[11].vert[3].vertIndex = 18;
	face[11].vert[4].vertIndex = 6;
}

