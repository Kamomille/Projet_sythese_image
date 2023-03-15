#pragma once

#include "Ray.h"
#include "Color.h"

class Object3d
{
public:

    Object3d();
    virtual ~Object3d();

    virtual double getNearestIntersectionsDistance(const Ray& rRay) = 0;
    virtual Vector3d GetNormalAtPoint(const Vector3d hit_point) = 0;
    virtual double intersect_sphere(const Ray& ray, Vector3d light) = 0;

    void setColor(const Color& _color);
    const Color& getColor();

protected:

    Color color;
};

