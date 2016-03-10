#ifndef ZJR_VECTOR_
#define ZJR_VECTOR_

#include <assert.h>
#include <math.h>

class Normal;
class Point;

class Vector3
{
public:
	float				x;
	float				y;
	float				z;

	Vector3();
	Vector3(float x_, float y_, float z_);
	Vector3(const Vector3 &v);
	Vector3(const Point &p);
	Vector3(const Normal &n);
	~Vector3();

	Vector3				operator+(const Vector3 &v) const;
	Vector3				operator-(const Vector3 &v) const;
	Vector3				operator-() const;
	Vector3				operator*(float f) const;
	Vector3				operator/(float f) const;
	float				operator[](int i) const;

	Vector3&				operator+=(const Vector3 &v);
	Vector3&				operator-=(const Vector3 &v);
	Vector3&				operator*=(float f);
	Vector3&				operator/=(float f);

	void				normalize();
	Vector3				cross(const Vector3 &v) const;
	float				dot(const Vector3 &v) const;
	float				absDot(const Vector3 &v) const;
	float				length() const;
	float				lengthSquared() const;				
};

inline Vector3 Vector3::operator+(const Vector3 &v) const
{
	return Vector3(x + v.x, y + v.y, z + v.z);
}

inline Vector3 Vector3::operator-(const Vector3 &v) const
{
	return Vector3(x - v.x, y - v.y, z - v.z);
}

inline Vector3 Vector3::operator-() const
{
	return Vector3(-x, -y, -z);
}

inline Vector3 Vector3::operator/(float f) const
{
	assert(f != 0);
	float inv = 1.0f / f;
	return Vector3(x * inv, y * inv, z * inv);
}

inline void Vector3::normalize()
{
	auto len = this->length();
	x /= len;
	y /= len;
	z /= len;
}

inline Vector3 Vector3::cross(const Vector3 &v) const
{
	return Vector3(y * v.z - z * v.y,
					z * v.x - x * v.z,
					x * v.y - y * v.x);
}

inline float Vector3::dot(const Vector3 &v) const
{
	return x * v.x + y * v.y + z * v.z;
}

inline float Vector3::absDot(const Vector3 &v) const
{
	return fabsf(dot(v));
}

inline float Vector3::length() const
{
	return sqrtf(lengthSquared());
}

inline float Vector3::lengthSquared() const
{
	return x * x + y * y + z * z;
}

inline Vector3 Vector3::operator*(float f) const
{
	return Vector3(x * f, y * f, z * f);
}

inline float Vector3::operator[](int i) const
{
	assert(i >= 0 && i <= 2);
	return (&x)[i];
}

inline Vector3& Vector3::operator+=(const Vector3 &v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

inline Vector3& Vector3::operator-=(const Vector3 &v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

inline Vector3& Vector3::operator*=(float f)
{
	x *= f;
	y *= f;
	z *= f;
	return *this;
}

inline Vector3& Vector3::operator/=(float f)
{
	assert(f != 0);
	float inv = 1.0f / f;
	x *= inv;
	y *= inv;
	z *= inv;
	return *this;
}

#endif