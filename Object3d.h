#pragma once

#include "Ray.h"
#include "Color.h"

class Object3d
{
public:

    Object3d();
    virtual ~Object3d();

    virtual double getNearestIntersectionsDistance(const Ray& rRay) = 0;
    virtual double getNearestIntersectionsDistance_2(const Ray& rRay) = 0;

    virtual float intersect_sphere(const Ray& ray) = 0;

    void setColor(const Color& _color);
    const Color& getColor();

protected:

    Color color;
};


/*
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

    Vector3d getNormal(Vector3d point, Vector3d center);
    Vector3d getPosition();

    virtual double getVolume() const = 0;

private:
    Vector3d position_;
    float size_;
    Color color_;
};


*/