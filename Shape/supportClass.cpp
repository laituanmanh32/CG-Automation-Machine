//#include "stdafx.h"
#include "supportClass.h"
#include <math.h>

//Oriented Vertex c = [this,b]
Vector3 Vector3::cross(Vector3 b)
{
	Vector3 c(y*b.z-z*b.y, z*b.x-x*b.z, x*b.y-y*b.x);
	return c;
}

// |b|^2
float Vector3::dot(Vector3 b)
{
	return x*b.x + y*b.y + z*b.z;
}

// normalize transfer vertex "this" to unit vertex
void Vector3::normalize()
{
	float temp = sqrt(x*x + y*y + z*z);
	x = x/temp;
	y = y/temp;
	z = z/temp;
}