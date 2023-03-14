#pragma once

class Color
{
public:

	Color();
	Color(double _r, double _g, double _b);
	Color(double value);

	Color operator + (const Color& c) const;
	Color operator * (double value) const;
	Color operator / (double value) const;
	Color& operator += (const Color& color);

	double r, g, b;
};
