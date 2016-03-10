#ifndef ZJR_VECTOR2_
#define ZJR_VECTOR2_

class Vector2
{
public:
	float				x;
	float				y;

	Vector2();
	Vector2(float x_, float y_);

	Vector2				operator+(const Vector2 &v) const;
	Vector2				operator-(const Vector2 &v) const;
	Vector2				operator*(float f) const;

	Vector2&			operator+=(const Vector2 &v);
	Vector2&			operator-=(const Vector2 &v);
	Vector2&			operator=(const Vector2 &rhs);
};

inline Vector2::Vector2()
{
}

inline Vector2::Vector2(float x_, float y_)
	:	x(x_),
		y(y_)
{
}

inline Vector2 Vector2::operator+(const Vector2 &v) const
{
	return Vector2(x + v.x, y + v.y);
}

inline Vector2 Vector2::operator-(const Vector2 &v) const
{
	return Vector2(x - v.x, y - v.y);
}

inline Vector2& Vector2::operator-=(const Vector2 &v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}

inline Vector2 Vector2::operator*(float f) const
{
	return Vector2(x * f, y * f);
}

inline Vector2& Vector2::operator+=(const Vector2 &v)
{
	x += v.x;
	y += v.y;
	return *this;
}

inline Vector2& Vector2::operator=(const Vector2 &rhs)
{
	if (this == &rhs)
	{
		return *this;
	}

	x = rhs.x;
	y = rhs.y;
	return *this;
}

#endif
