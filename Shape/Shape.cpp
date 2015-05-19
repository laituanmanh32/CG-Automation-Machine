#include "Shape.h"

#define PI			3.1415926
#define	COLORNUM		14

float ColorArr[COLORNUM][3] = { { 1.0, 0.0, 0.0 }, { 0.0, 1.0, 0.0 }, {
		0.0,
		0.0, 1.0
	}, { 1.0, 1.0, 0.0 }, { 1.0, 0.0, 1.0 }, { 0.0, 1.0, 1.0 }, {
		0.3, 0.3, 0.3
	}, { 0.5, 0.5, 0.5 }, { 0.9, 0.9, 0.9 },
	{ 1.0, 0.5, 0.5 }, { 0.5, 1.0, 0.5 }, { 0.5, 0.5, 1.0 },
	{ 0.0, 0.0, 0.0 }, { 1.0, 1.0, 1.0 }
};

void Shape::setPosition(float fX = 0, float fY = 0, float fZ = 0) {
	this->slideX = fX;
	this->slideY = fY;
	this->slideZ = fZ;
}
void Shape::setRotation(float fAngle = 0, float fRotateX = 0, float fRotateY = 0,
                        float fRotateZ = 0) {
	this->rotateX = fRotateX;
	this->rotateY = fRotateY;
	this->rotateZ = fRotateZ;
	this->angle = fAngle;
}
void Shape::drawSefl(bool isWireframe = false) {
	glPushMatrix();
	glTranslatef(slideX, slideY, slideZ);
	glRotated(angle, rotateX, rotateY, rotateZ);

	if (isWireframe)
		this->DrawWireframe();
	else
		this->DrawColor();

	glPopMatrix();
}
void Shape::draw(bool isWireframe = false) {
	if (isWireframe)
		this->DrawWireframe();
	else
		this->DrawColor();
}
void Shape::DrawWireframe() {
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	for (int f = 0; f < numFaces; f++) {
		glBegin(GL_POLYGON);
		for (int v = 0; v < face[f].nVerts; v++) {
			int iv = face[f].vert[v].vertIndex;

			glVertex3f(pt[iv].x, pt[iv].y, pt[iv].z);
		}
		glEnd();
	}
}
void Shape::DrawColor() {
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	for (int f = 0; f < numFaces; f++) {
		glBegin(GL_POLYGON);
		for (int v = 0; v < face[f].nVerts; v++) {
			int iv = face[f].vert[v].vertIndex;
			int ic = face[f].vert[v].colorIndex;
			glColor3f(ColorArr[ic][0], ColorArr[ic][1], ColorArr[ic][2]);
			glVertex3f(pt[iv].x, pt[iv].y, pt[iv].z);
		}
		glEnd();
	}
}
void Shape::DrawRandomColor() {
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	for (int f = 0; f < numFaces; f++) {
		glBegin(GL_POLYGON);
		for (int v = 0; v < face[f].nVerts; v++) {
			int iv = face[f].vert[v].vertIndex;
			int ic = face[f].vert[v].colorIndex;

			ic = f % COLORNUM;

			glColor3f(ColorArr[ic][0], ColorArr[ic][1], ColorArr[ic][2]);
			glVertex3f(pt[iv].x, pt[iv].y, pt[iv].z);
		}
		glEnd();
	}
}
void Shape::SetColor(int ColorIdx) {
	for (int i = 0; i < numFaces; i++) {
		for (int j = 0; j < face[i].nVerts; j++) {
			face[i].vert[j].colorIndex = ColorIdx;
		}
	}
}
void Shape::CreateRandomColor() {
	for (int i = 0; i < numFaces; i++) {
		for (int j = 0; j < face[i].nVerts; j++) {
			face[i].vert[j].colorIndex = i % COLORNUM;
		}
	}
}