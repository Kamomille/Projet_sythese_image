#pragma once

#include "Object3d.h"

class Sphere : public Object3d {
public:
    Sphere(Vector3d position, float size);
    Vector3d getCenter(); 
    //virtual ~Sphere();
    //virtual float distance(const Vector3d& point) const;

private:
    Vector3d m_center;
};



/*
class Sphere {
private:
    Vector3d origin;
    float radius;


public:
    void SetColor(Color);
};



class Sphere : public Object3d {
public:
    float center;
    explicit Sphere(const Vector3d& origin, float center) : Object3d(origin) {
        this->center = center;
    }
    double GetCenter();
};

*/




