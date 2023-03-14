#pragma once

#include "Light.h"

class DirectionalLight : public Light
{
public:
    DirectionalLight(const Vector3d& _center = Point3d(0.0, 0.0, 0.0));
    Vector3d getVectorToLightAtPoint(const Vector3d& point);
protected:
    Point3d center;
};

