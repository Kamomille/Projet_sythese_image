#pragma once

#include "Vector3d.h"
#include "Color.h"

class Object3d {
public:
    Object3d(Vector3d position, float size);

    void SetColor(Color color);
    Color getColor();

    float distance();
    Vector3d getCenter();
    float getRadius();

    virtual double getVolume() const = 0;

private:
    Vector3d position_;
    float size_;
    Color color_;
};


