#include "DirectionalLight.h"
#include "Ray.h"
#include "Sphere.h"
#include "Vector3d.h"

DirectionalLight::DirectionalLight(const Vector3d& _center)
	: Light(),
	center(_center)
{
}

Vector3d DirectionalLight::getVectorToLightAtPoint(const Vector3d& point)
{
	return point;
}

