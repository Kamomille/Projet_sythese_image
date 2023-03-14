#pragma once

#include <istream>
#include <ostream>

class Vector3d
{
public:

	Vector3d(double _x = 0, double _y = 0, double _z = 0);
	Vector3d(const Vector3d& v);

	~Vector3d();

	// accessors

	double getX() const { return x; }
	double getY() const { return y; }
	double getZ() const { return z; }

	// operators

	Vector3d operator = (const Vector3d& v);
	Vector3d operator + (const Vector3d& v) const;
	Vector3d operator - (const Vector3d& v) const;
	Vector3d operator - ()                  const;
	Vector3d operator * (double k)           const;

	friend Vector3d operator * (double k, const Vector3d& v);

	Vector3d operator / (double k)           const;

	Vector3d& operator += (const Vector3d& v);
	Vector3d& operator *= (double value);
	Vector3d& operator /= (double value);

	// operations

	double dot(const Vector3d& v) const;
	double getLength();
	void normalize();
	Vector3d unit() const;

protected:

	double x, y, z;
};

typedef Vector3d Point3d;
