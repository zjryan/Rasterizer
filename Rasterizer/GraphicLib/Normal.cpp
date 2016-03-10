#include "Normal.h"
#include "./Vector3.h"


Normal::Normal()
	:	x(0.0f),
		y(1.0f),
		z(0.0f)
{
}

Normal::Normal(const Normal &n)
	:	x(n.x),
		y(n.y),
		z(n.z)
{
}

Normal::Normal(float x_, float y_, float z_)
	:	x(x_),
		y(y_),
		z(z_)
{
}

Normal::Normal(const Vector3 &v)
	:	x(v.x),
		y(v.y),
		z(v.z)
{
}

Normal::~Normal()
{
}

Normal Normal::operator-(const Normal &n) const
{
	return Normal(x - n.x, y - n.y, z - n.z);
}

float Normal::dot(const Vector3 &v) const
{
	return x * v.x + y * v.y + z * v.z;
}

float Normal::absDot(const Vector3 &v) const
{
	return fabsf(dot(v));
}
