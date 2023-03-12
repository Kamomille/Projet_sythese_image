#pragma once

#include "Object3d.h"

class Sphere : public Object3d {
public:
    Sphere(Vector3d position, float size);
    Vector3d getCenter(); 

    virtual double getVolume() const override;

private:
    Vector3d position_;
    float size_;
};





