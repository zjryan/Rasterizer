#include "Point.h"

Point::Point()
	:	x(0.0f),
		y(0.0f),
		z(0.0f)
{
}

Point::Point(float x_, float y_, float z_)
	:	x(x_),
		y(y_),
		z(z_)
{
}

Point::Point(const Point &p)
	:	x(p.x),
		y(p.y),
		z(p.z)
{
}

Point::Point(const Vector3& v)
	:	x(v.x),
		y(v.y),
		z(v.z)
{
}

Point::~Point()
{
}

