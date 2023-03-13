#include "Light.h"
#include "Vector3d.h"
#include "Color.h"
#include "Object3d.h"


Light::Light(Vector3d direction)
{
    direction.Normalize();
    direction_ = direction;
}
/*
void Light:: applyToSphere(Object3d* sphere) {
    Vector3d normal = sphere->getNormal(sphere->getPosition());
    float intensity = (-direction_).Dot(normal);
    sphere->SetColor(sphere->getColor() + std::max(intensity, 0.0f));
}*/

