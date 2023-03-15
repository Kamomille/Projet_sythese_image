#pragma once

#include "Vector3d.h"

class Light
{
public:
    Light();
    virtual ~Light();

	virtual Vector3d getVectorToLightAtPoint(const Vector3d& point) = 0;

    virtual Vector3d& getDirection() = 0;
};

