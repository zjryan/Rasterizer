#ifndef ZJR_NORMAL_
#define ZJR_NORMAL_

class Vector3;

class Normal
{
public:
	float				x;
	float				y;
	float				z;

	Normal();
	Normal(float x_, float y_, float z_);
	Normal(const Normal &n);
	Normal(const Vector3 &v);
	~Normal();

	Normal				operator+(const Normal &n) const;
	Normal				operator-(const Normal &n) const;
	Normal				operator-() const;
	Normal				operator*(float f) const;

	Normal&				operator+=(const Normal &n);
	Normal&				operator*=(float f);

	float				dot(const Vector3 &v) const;
	float				absDot(const Vector3 &v) const;
};

inline Normal Normal::operator+(const Normal &n) const
{
	return Normal(x + n.x, y + n.y, z + n.z);
}

inline Normal Normal::operator-() const
{
	return Normal(-x, -y, -z);
}

inline Normal Normal::operator*(float f) const
{
	return Normal(x * f, y * f, z * f);
}

inline Normal& Normal::operator*=(float f)
{
	x *= f;
	y *= f;
	z *= f;
	return *this;
}

inline Normal& Normal::operator+=(const Normal &n)
{
	x += n.x;
	y += n.y;
	z += n.z;
	return *this;
}

#endif
