#include "Color.h"

Color::Color()
	: r(0),
	g(0),
	b(0)
{
}

Color::Color(double _r, double _g, double _b)
	: r(_r),
	g(_g),
	b(_b)
{
}

Color::Color(double value)
	: r(value),
	g(value),
	b(value)
{
}

Color Color::operator + (const Color& c) const
{
	return Color(r + c.r, g + c.g, b + c.b);
}

Color Color::operator * (double value) const
{
	return Color(r * value, g * value, b * value);
}

Color Color::operator / (double value) const
{
	return Color(r / value, g / value, b / value);
}

Color& Color::operator += (const Color& color)
{
	r += color.r;
	g += color.g;
	b += color.b;
	return *this;
}
