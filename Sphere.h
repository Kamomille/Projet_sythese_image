#pragma once

#include "Object3d.h"

class Sphere : public Object3d
{
public:

    Sphere(const Vector3d& _center = Point3d(0.0, 0.0, 0.0), double _radius = 1.0);
    double getNearestIntersectionsDistance(const Ray& rRay);
    double getNearestIntersectionsDistance_2(const Ray& rRay);


    float intersect_sphere(const Ray& ray);

protected:

    Point3d center;
    double radius;
};





