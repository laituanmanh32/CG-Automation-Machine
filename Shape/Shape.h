#if !defined (_SHAPE_CLASS)
#define _SHAPE_CLASS

#include "supportClass.h"

#define PI			3.1415926
#define	COLORNUM		14

class VertexID {
public:
	int vertIndex;
	int colorIndex;
};

class Face {
public:
	int nVerts;
	VertexID* vert;

	Face() {
		nVerts = 0;
		vert = NULL;
	}
	~Face() {
		if (vert != NULL) {
			delete[] vert;
			vert = NULL;
		}
		nVerts = 0;
	}
};

class Shape {
public:

	int numVerts;
	Point3* pt;

	int numFaces;
	Face* face;

	float slideX, slideY, slideZ;
	float rotateX, rotateY, rotateZ;

	float angle;

public:
	Shape() {

		numVerts = 0;
		pt = NULL;
		numFaces = 0;
		face = NULL;

		slideX = 0;
		slideY = 0;
		slideZ = 0;
		rotateX = 0;
		rotateY = 0;
		rotateZ = 0;

		angle = 0;
		slideX = slideY = slideZ = 0;
		rotateX = rotateY = rotateZ = 0;
	}
	virtual ~Shape() {
		if (pt != NULL) {
			delete[] pt;
		}
		if (face != NULL) {
			delete[] face;
		}
		numVerts = 0;
		numFaces = 0;
	}

	void setPosition(float fX, float fY, float fZ);
	void setRotation(float fAngle, float fRotateX , float fRotateY,
	                 float fRotateZ );
	virtual void drawSefl(bool isWireframe);
	virtual void draw(bool isWireframe);
	virtual void DrawWireframe();
	void DrawColor();
	void DrawRandomColor();
	void SetColor(int ColorIdx);
	void CreateRandomColor();
};

#endif /* SHAPE_H_ */
