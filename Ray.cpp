#include "Ray.h"

Ray::Ray()
	: origin(),
	direction()
{
}

Ray::Ray(const Point3d& vOrigin, const Vector3d& vDirection)
	: origin(vOrigin),
	direction(vDirection)
{
}

void Ray::setOrigin(const Point3d& vOrigin)
{
	origin = vOrigin;
}

void Ray::setDirection(const Vector3d& vDirection)
{
	direction = vDirection;
}

const Point3d& Ray::getOrigin() const
{
	return origin;
}

const Vector3d& Ray::getDirection() const
{
	return direction;
}
