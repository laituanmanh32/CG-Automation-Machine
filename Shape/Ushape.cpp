/*
 * UShape.cpp
 *
 *  Created on: Apr 24, 2015
 *      Author: manh
 */

#include "UShape.h"

UShape::UShape() {
	this->init(1,1,1,1);
}

UShape::UShape(float fSizeX, float fSizeY, float fSizeZ, float fThick){
	this->init(fSizeX,fSizeY,fSizeZ,fThick);
}

UShape::~UShape() {
	// TODO Auto-generated destructor stub
}

void UShape::setSize(float fSizeX, float fSizeY, float fSizeZ, float fThick){
	this->init(fSizeX,fSizeY,fSizeZ,fThick);
}

void UShape::init(float fSizeX, float fSizeY, float fSizeZ, float fThick){
	this->numFaces = 6 * 3;
	this->numVerts = 8 * 3;

	float X = fSizeX / 2 - fThick / 2;
	float Z = fSizeZ / 2 - fThick / 2;

	this->face = new Face[numFaces];
	this->pt = new Point3[numVerts];

	// right
	Cuboid* left = new Cuboid(fThick, fSizeY, fSizeZ - fThick);
	for (int i = 0; i < left->numVerts; i++) {
		left->pt[i].set(left->pt[i].x - X, left->pt[i].y,
				left->pt[i].z + fThick / 2);
		this->pt[i] = left->pt[i];
	}
	for (int i = 0; i < left->numFaces; i++) {
		this->face[i] = left->face[i];
	}

	Cuboid* behind = new Cuboid(fSizeX, fSizeY, fThick);
	for (int i = 0; i < behind->numVerts; i++) {
		behind->pt[i].set(behind->pt[i].x, behind->pt[i].y,
				behind->pt[i].z - Z);
		this->pt[i + 8] = behind->pt[i];
	}
	for (int i = 0; i < behind->numFaces; i++) {
		this->face[i + 6].nVerts = behind->face[i].nVerts;
		this->face[i + 6].vert = new VertexID[behind->face[i].nVerts];
		for (int j = 0; j < behind->face[i].nVerts; j++) {
			this->face[i + 6].vert[j].vertIndex =
					behind->face[i].vert[j].vertIndex + 8;
		}
	}

	//left face
	Cuboid* right = new Cuboid(fThick, fSizeY, fSizeZ - fThick);
	for (int i = 0; i < right->numVerts; i++) {
		right->pt[i].set(right->pt[i].x + X, right->pt[i].y, left->pt[i].z);
		this->pt[i + 16] = right->pt[i];
	}
	for (int i = 0; i < right->numFaces; i++) {
		this->face[i + 12].nVerts = right->face[i].nVerts;
		this->face[i + 12].vert = new VertexID[right->face[i].nVerts];
		for (int j = 0; j < right->face[i].nVerts; j++) {
			this->face[i + 12].vert[j].vertIndex =
					right->face[i].vert[j].vertIndex + 16;
		}
	}
}