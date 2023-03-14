#pragma once

#include <vector>
#include <string>

#include "Vector3d.h"
#include "Ray.h"
#include "Object3d.h"
#include "Light.h"
#include "Color.h"

class Scene
{
public:

	Scene();
	~Scene();

	void addObject(Object3d* object3d);
	void addLight(Light* light);

	void render(std::string fileName, unsigned int width, unsigned int height);

protected:

	Color raytrace(const Ray& ray);
	double raytrace_2(const Ray& ray);
	Color rayLightTrace(const Ray& ray);

	std::vector<Object3d*> objects3d;
	std::vector<Light*> lights;
};
