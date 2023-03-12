#include "Object3d.h"
#include "Color.h"
#include "Vector3d.h"


Object3d::Object3d(Vector3d position, float size) 
{
    position_ = position;
    size_ = size;
}

void Object3d::SetColor(Color color)
{
    color_ = color;
}
Color Object3d::getColor() {
    return color_;
}


float Object3d::distance() {
    return 10;
}


float Object3d::getRadius() {
    return size_; // / 2.0f;
}


Vector3d Object3d::getCenter() {
    float radius = getRadius();
    return Vector3d(position_.getX() + radius, position_.getY() + radius, position_.getZ() + radius);
    //return Vector3d(0.1f, 0.0f, 00.0f);
}


