/*
 * Floor.cpp
 *
 *  Created on: Apr 25, 2015
 *      Author: manh
 */
#include "YPlane.h"
YPlane::YPlane() {
	init(10, 10, 1, 1);
//	this->CreateRandomColor();
}

YPlane::~YPlane() {
	// TODO Auto-generated destructor stub
}

YPlane::YPlane(int row, int col, float sizeX, float sizeY) {
	init(row, col, sizeX, sizeY);
}

void YPlane::init(int row, int col, float sizeX, float sizeY) {
	numVerts = (row + 1) * (col + 1);
	pt = new Point3[numVerts];

	numFaces = row * col;
	face = new Face[numFaces];

	int startX = -(col + 1) / 2 * sizeX;
	int startY = -(row + 1) / 2 * sizeY;
	int faceIndex = 0;

	for (int i = 0; i <= col; i++) {
		for (int j = 0; j <= row; j++) {
			pt[i * (col + 1) + j].set(startX + i * sizeX, 0,
			                          startY + j * sizeY);

			if (i < col && j < row) {
				face[faceIndex].nVerts = 4;
				face[faceIndex].vert = new VertexID[4];
				face[faceIndex].vert[0].vertIndex = i * (col + 1) + j;
				face[faceIndex].vert[1].vertIndex = i * (col + 1) + j + 1;
				face[faceIndex].vert[2].vertIndex = (i + 1) * (col + 1) + j + 1;
				face[faceIndex].vert[3].vertIndex = (i + 1) * (col + 1) + j;
				faceIndex++;
			}
		}
	}

//	// fix add vertex
//	if (row % 2 == 0) {
//		for (int i = 0; i < numVerts; i++) {
//			pt[i].set(pt[i].x, 0, pt[i].y + sizeY / 2);
//
//		}
//	}
//	if (col % 2 == 0) {
//		for (int i = 0; i < numVerts; i++) {
//			pt[i].set(pt[i].x + sizeX / 2, 0, pt[i].y);
//		}
//	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					face[i * row + j].vert[0].colorIndex = 13;
					face[i * row + j].vert[1].colorIndex = 13;
					face[i * row + j].vert[2].colorIndex = 13;
					face[i * row + j].vert[3].colorIndex = 13;

				} else {
					face[i * row + j].vert[0].colorIndex = 12;
					face[i * row + j].vert[1].colorIndex = 12;
					face[i * row + j].vert[2].colorIndex = 12;
					face[i * row + j].vert[3].colorIndex = 12;
				}
			} else {
				if (j % 2 == 0) {
					face[i * row + j].vert[0].colorIndex = 12;
					face[i * row + j].vert[1].colorIndex = 12;
					face[i * row + j].vert[2].colorIndex = 12;
					face[i * row + j].vert[3].colorIndex = 12;
				} else {
					face[i * row + j].vert[0].colorIndex = 13;
					face[i * row + j].vert[1].colorIndex = 13;
					face[i * row + j].vert[2].colorIndex = 13;
					face[i * row + j].vert[3].colorIndex = 13;
				}
			}
		}
	}
}
