#include <cstdlib>
#include <iostream>

#include "Scene.h"
#include "Bmpfile.h"

#define MIN(a,b)	( a < b ? a : b )


using namespace std;

Scene::Scene()
	: objects3d(),
	lights()
{
}

Scene::~Scene()
{
	for (Object3d* object3d : objects3d) {
		delete object3d;
	}
	for (Light* light : lights) {
		delete light;
	}
}

void Scene::addObject(Object3d* object3d)
{
	objects3d.push_back(object3d);
}

void Scene::addLight(Light* light)
{
	lights.push_back(light);
}

void Scene::render(std::string fileName, unsigned int width, unsigned int height)
{
	Ray ray;
	unsigned char* pColors = new unsigned char[width * height * 3];
	ray.setOrigin(Vector3d(0, 0, 10));
	unsigned int index = 0;

	for (unsigned int y = 0; y < height; y++)
	{
		for (unsigned int x = 0; x < width; x++)
		{
			Vector3d target = Vector3d(((double)x - (double)width / 2) / (double)width, -((double)y - (double)height / 2) / (double)height, 0);
			ray.setDirection((target - ray.getOrigin()).unit());

			Color color = raytrace(ray);

			float add = raytrace_2(ray)*1000;
			color.r -= add;

			//color.g += add;
			//color.b += add;

			/*
			if (raytrace_2(ray) != 0) {
				cout << "\n" << raytrace_2(ray)* 1000 << endl;
			}
			double t = raytrace_2(ray);
			if (t > 9) {
				t = abs(t - 9);
				color = Color(1, t, t);
			}*/

			 

			pColors[index++] = MIN(int(255 * color.b), 255);
			pColors[index++] = MIN(int(255 * color.g), 255);
			pColors[index++] = MIN(int(255 * color.r), 255);
		}
	}
	BMPFile::saveBmp(fileName, pColors, width, height);
	delete[]pColors;
}

Color Scene::raytrace(const Ray& ray)
{
	Object3d* nearestObject = NULL;
	double nearestDistance = 10000.0;
	for (Object3d* obj : objects3d) {
		double distance = obj->getNearestIntersectionsDistance(ray);
		if (distance < nearestDistance) {
			nearestDistance = distance;
			nearestObject = obj;
		}
	}
	if (!nearestObject) {
		return Color();
	}
	return nearestObject->getColor();
}

double Scene::raytrace_2(const Ray& ray)
{
	Object3d* nearestObject = NULL;
	double nearestDistance = 10000.0;
	for (Object3d* obj : objects3d) {
		double distance = obj->getNearestIntersectionsDistance_2(ray);
		if (distance < nearestDistance) {
			nearestDistance = distance;
			nearestObject = obj;
		}
	}
	if (!nearestObject) {
		return 0;
	}
	//t = 1.2 - abs(t - 9);
	return nearestDistance; // nearestObject->getColor();
}


//t = 1.2 - abs(t - 9);
//Color color = Color(t, 0, 0);
//cout << "\n" << t << endl;

/*
// Calculate the dot product between the normal and light direction
float dotProduct = max(0.0f, dot(normal, lightDirection));

// Calculate the diffuse color
glm::vec3 diffuseColor = lightColor * surfaceColor * dotProduct;

*/

