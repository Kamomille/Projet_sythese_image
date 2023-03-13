#pragma once

#include "Light.h"

class DirectionalLight : public Light {
public:
    DirectionalLight(Vector3d position);

private:
    Vector3d position_;
};







