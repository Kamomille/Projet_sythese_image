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

