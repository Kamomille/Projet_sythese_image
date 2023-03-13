#pragma once

#include "Object3d.h"
#include "Vector3d.h"

class Light {
public:
    Light(Vector3d direction);

    void applyToSphere(Object3d* sphere);

private:
    Vector3d direction_;
};




