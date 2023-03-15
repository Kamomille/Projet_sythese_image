#pragma once

#include "Object3d.h"

class Sphere : public Object3d
{
public:

    Sphere(const Vector3d& _center = Point3d(0.0, 0.0, 0.0), double _radius = 1.0);
    double getNearestIntersectionsDistance(const Ray& rRay);

    double intersect_sphere(const Ray& rRay, Vector3d light);

    Vector3d GetNormalAtPoint(const Vector3d hit_point);

protected:

    Point3d center;
    double radius;
};





