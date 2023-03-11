#include <math.h>
#include "Vector3d.h"

Vector3d::Vector3d(double _x, double _y, double _z)
	: x(_x),
	y(_y),
	z(_z)
{
}

Vector3d::Vector3d(const Vector3d& v)
	: x(v.x),
	y(v.y),
	z(v.z)
{
}

Vector3d::~Vector3d() {
}

// Operators

Vector3d Vector3d::operator = (const Vector3d& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

Vector3d Vector3d::operator + (const Vector3d& v) const
{
	return Vector3d(x + v.x, y + v.y, z + v.z);
}

Vector3d Vector3d::operator - (const Vector3d& v) const
{
	return Vector3d(x - v.x, y - v.y, z - v.z);
}

Vector3d Vector3d::operator - ()                  const
{
	return Vector3d(-x, -y, -z);
}

Vector3d Vector3d::operator * (double k)           const
{
	return Vector3d(k * x, k * y, k * z);
}

Vector3d Vector3d::operator / (double k)           const
{
	return Vector3d(x / k, y / k, z / k);
}

Vector3d& Vector3d::operator += (const Vector3d& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

Vector3d& Vector3d::operator *= (double value)
{
	x *= value;
	y *= value;
	z *= value;
	return *this;
}

Vector3d& Vector3d::operator /= (double value)
{
	x /= value;
	y /= value;
	z /= value;
	return *this;
}

// operations

double Vector3d::Dot(const Vector3d& v) const
{
	return ((x * v.x) + (y * v.y) + (z * v.z));
}

double Vector3d::GetLength()
{
	return ((double)sqrt(x * x + y * y + z * z));
}

void Vector3d::Normalize()
{
	double length = GetLength();

	if (length > 0)
	{
		x /= length;
		y /= length;
		z /= length;
	}
}

Vector3d Vector3d::Unit() const
{
	Vector3d v(*this);
	v.Normalize();
	return v;
}

Vector3d operator * (double k, const Vector3d& v)
{
	return v * k;
}
