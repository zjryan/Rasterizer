#include "Color.h"

Color::Color()
	:	r(1.0f),
		g(1.0f),
		b(1.0f)
{
}

Color::Color(float c)
	:	r(c),
		g(c),
		b(c)
{
}

Color::Color(float _r, float _g, float _b)
	:	r(_r),
		g(_g),
		b(_b)
{
}

Color::Color(const Color &c)
	:	r(c.r),
		g(c.g),
		b(c.b)
{
}

Color::~Color()
{
}

Color Color::operator*(const Color &c) const
{
	return Color(r * c.r, g * c.g, b * c.b);
}

Color Color::operator*(float f) const
{
	return Color(r * f, g * f, b * f);
}

Color Color::operator/(float f) const
{
	return Color(r / f, g / f, b / f);
}

Color Color::operator+(const Color &c) const
{
	float r_ = r + c.r;
	float g_ = g + c.g;
	float b_ = b + c.b;
	return Color(r_, g_, b_);
}

Color Color::operator-(const Color &c) const
{
	float r_ = r - c.r;
	float g_ = g - c.g;
	float b_ = b - c.b;
	return Color(r_, g_, b_);
}

Color& Color::operator=(const Color &rhs)
{
	if (this == &rhs)
	{
		return *this;
	}

	r = rhs.r;
	g = rhs.g;
	b = rhs.b;

	return *this;
}

Color& Color::operator*=(const Color &c)
{
	r *= c.r;
	g *= c.g;
	b *= c.b;
	return *this;
}

Color& Color::operator*=(float f)
{
	r *= f;
	g *= f;
	b *= f;
	return *this;
}

Color& Color::operator/=(float f)
{
	r /= f;
	g /= f;
	b /= f;
	return *this;
}

Color& Color::operator+=(const Color &c)
{
	r += c.r;
	g += c.g;
	b += c.b;
	return *this;
}

Color& Color::operator-=(const Color &c)
{
	r -= c.r;
	g -= c.g;
	b -= c.b;
	return *this;
}

Color::_RGB_ Color::format() const
{
	auto R = static_cast<unsigned char>(r * 255.0f);
	auto G = static_cast<unsigned char>(g * 255.0f);
	auto B = static_cast<unsigned char>(b * 255.0f);

	_RGB_ color(R, G, B);
	return color;
}