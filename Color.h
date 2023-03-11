#ifndef __COLOR_H
#define __COLOR_H

#include <math.h>

class Color
{
public:

	Color()
		: r(0),
		g(0),
		b(0)
	{
	}

	Color(double _r, double _g, double _b)
		: r(_r),
		g(_g),
		b(_b)
	{
	}

	Color(double value)
		: r(value),
		g(value),
		b(value)
	{
	}

	bool IsBlack() const { return ((r == 0.0f) && (g == 0.0f) && (b == 0.0f)); }

	bool IsWhite() const { return ((r == 1.0f) && (g == 1.0f) && (b == 1.0f)); }

	Color operator + (const Color& c) const
	{
		return Color(r + c.r, g + c.g, b + c.b);
	}

	Color operator - (const Color& c) const
	{
		return Color(r - c.r, g - c.g, b - c.b);
	}

	Color operator * (double factor) const
	{
		return Color(r * factor, g * factor, b * factor);
	}

	Color operator * (const Color& color) const
	{
		return Color(r * color.r, g * color.g, b * color.b);
	}

	Color operator / (double factor) const
	{
		return Color(r / factor, g / factor, b / factor);
	}

	Color operator ^ (double k)           const
	{
		return Color((double)pow(r, k), (double)pow(g, k), (double)pow(b, k));
	}

	Color& operator += (const Color& color)
	{
		r += color.r;
		g += color.g;
		b += color.b;
		return *this;
	}

	Color& operator -= (const Color& color)
	{
		r -= color.r;
		g -= color.g;
		b -= color.b;
		return *this;
	}

	Color& operator *= (double factor)
	{
		r *= factor;
		g *= factor;
		b *= factor;
		return *this;
	}

	Color& operator *= (const Color& color)
	{
		r *= color.r;
		g *= color.g;
		b *= color.b;
		return *this;
	}

	Color& operator /= (double factor)
	{
		r /= factor;
		g /= factor;
		b /= factor;
		return *this;
	}

	bool operator == (const Color& color) const
	{
		return ((r == color.r) && (g == color.g) && (b == color.b));
	}

	bool operator != (const Color& color) const
	{
		return ((r != color.r) || (g != color.g) || (b != color.b));
	}

	double r, g, b;
};

#endif
