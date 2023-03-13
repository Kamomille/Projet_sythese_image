#include "DirectionalLight.h"
#include "Vector3d.h"
#include "Light.h"


DirectionalLight::DirectionalLight(Vector3d position) : Light(position)
{
    position_ = position;
}