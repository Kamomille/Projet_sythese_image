#include "Object3d.h"

Object3d::Object3d()
{
}

Object3d::~Object3d()
{
}

void Object3d::setColor(const Color& _color)
{
    color = _color;
}

const Color& Object3d::getColor()
{
    return color;
}


/*
float Object3d::getRadius() {
    return size_; // / 2.0f;
}
Vector3d Object3d::getNormal(Vector3d point, Vector3d center) {
    Vector3d normal = point - center;
    normal.Normalize();
    return normal;
}

Vector3d Object3d::getCenter() {
    float radius = getRadius();
    return Vector3d(position_.getX() + radius, position_.getY() + radius, position_.getZ() + radius);
    //return Vector3d(0.1f, 0.0f, 00.0f);
}

*/
