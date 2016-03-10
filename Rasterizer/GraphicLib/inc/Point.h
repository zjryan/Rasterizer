#ifndef ZJR_POINT_
#define ZJR_POINT_

#include "./Vector3.h"

class Point
{
public:
	float				x;
	float				y;
	float				z;

	Point();
	Point(float x_, float y_, float z_);
	Point(const Vector3& v);
	Point(const Point &p);
	~Point();

	Point				operator+(const Point &p) const;
	Point				operator+(const Vector3 &v) const;
	Point				operator+(float f) const;
	Vector3				operator-(const Point &p) const;
	Point				operator-(float f) const;
	Point				operator-() const;
	Point				operator/(float f) const;
	float				operator[](int i) const;

	Point&				operator=(const Point &rhs);
	Point&				operator+=(const Point &p);
	Point&				operator-=(const Point &p); 
	Point&				operator/=(float f);

	float				Distance(const Point &p) const;
	float				DistanceSquared(const Point &p) const;
};

inline Point Point::operator+(const Point &p) const
{
	return Point(x + p.x, y + p.y, z + p.z);
}

inline Point Point::operator+(const Vector3 &v) const
{
	return Point(x + v.x, y + v.y, z + v.z);
}

inline Point Point::operator+(float f) const
{
	return Point(x + f, y + f, z + f);
}

inline Vector3 Point::operator-(const Point &p) const
{
	return Vector3(x - p.x, y - p.y, z - p.z);
}

inline Point Point::operator-() const
{
	return Point(-x, -y, -z);
}

inline Point Point::operator-(float f) const
{
	return Point(x - f, y - f, z - f);
}

inline Point Point::operator/(float f) const
{
	return Point(x / f, y / f, z / f);
}

inline float Point::Distance(const Point &p) const
{
	return (*this - p).length();
}

inline float Point::DistanceSquared(const Point &p) const
{
	return (*this - p).lengthSquared();
}

inline float Point::operator[](int i) const
{
	assert(i >= 0 && i <= 2);
	return (&x)[i];
}

inline Point& Point::operator=(const Point &rhs)
{
	if(this == &rhs)
	{
		return *this;
	}

	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	return *this;
}

inline Point& Point::operator+=(const Point &p)
{
	x += p.x;
	y += p.y;
	z += p.z;
	return *this;
}

inline Point& Point::operator-=(const Point &p)
{
	x -= p.x;
	y -= p.y;
	z -= p.z;
	return *this;
}

inline Point& Point::operator/=(float f)
{
	x /= f;
	y /= f;
	z /= f;
	return *this;
}

#endif
