#pragma once

#include "Light.h"

class DirectionalLight : public Light
{
public:
    DirectionalLight(const Vector3d& _direction = Point3d(0.0, 0.0, 0.0));
    Vector3d getVectorToLightAtPoint(const Vector3d& point);
    Vector3d& getDirection();

protected:
    Point3d direction;
};

