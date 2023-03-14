#pragma once

#include "Vector3d.h"

class Ray
{
public:

	Ray();
	Ray(const Point3d& vOrigin, const Vector3d& vDirection);

	void setOrigin(const Point3d& vOrigin);
	void setDirection(const Vector3d& vDirection);

	const Point3d& getOrigin() const;
	const Vector3d& getDirection() const;

protected:

	Point3d  	origin;
	Vector3d	direction;
};
