#include "Vector3.h"
#include "./Point.h"
#include "./Normal.h"

Vector3::Vector3()
	:	x(0.0f),
		y(0.0f),
		z(0.0f)
{
}

Vector3::Vector3(float x_, float y_, float z_)
	:	x(x_),
		y(y_),
		z(z_)
{
}

Vector3::Vector3(const Vector3 &v)
	:	x(v.x),
		y(v.y),
		z(v.z)
{
}

Vector3::Vector3(const Point& p)
	:	x(p.x),
		y(p.y),
		z(p.z)
{
}


Vector3::Vector3(const Normal& n)
	:	x(n.x),
		y(n.y),
		z(n.z)
{
}

Vector3::~Vector3()
{
}



