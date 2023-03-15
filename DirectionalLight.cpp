#include "DirectionalLight.h"
#include "Ray.h"
#include "Sphere.h"
#include "Vector3d.h"

DirectionalLight::DirectionalLight(const Vector3d& _direction)
	: Light(),
	direction(_direction)
{
}

Vector3d& DirectionalLight::getDirection()
{
	return direction;
}


Vector3d DirectionalLight::getVectorToLightAtPoint(const Vector3d& point) {
	//return (direction - point).normalize();
	return point;
}
