#include "Object3d.h"
#include "Color.h"
#include "Vector3d.h"


Object3d::Object3d(Vector3d position, float size) //: m_position(position), m_size(size), m_color(Vector3d(1.0f, 1.0f, 1.0f))
{
}

void Object3d::SetColor(Color color)
{
    m_color = color;
}


float Object3d::distance() {
    return 10;
}

Color Object3d::getColor() {
    return m_color;
}

Vector3d Object3d::getCenter() {
    float radius = size / 2.0f;
    return Vector3d(m_position.getX() + radius, m_position.getY() + radius, m_position.getZ() + radius);
}
float Object3d::getRadius() {
    return size / 2.0f;
}


/*

Object3d::Object3d(Vector3d vec, float nb) {}


void Object3d::SetColor(Color* color) {

}


Object3d::Object3d(const Vector3d& origin) { this->origin = origin; }

void Object3d::SetColor(Color color) { this->color = color; }*/