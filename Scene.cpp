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

			float add = raytrace_2(ray)*500;
			color.r -= add;
			color.g -= add;
			color.b -= add;

			/*
			if (raytrace_2(ray) != 0) {
				cout << "\n" << raytrace_2(ray)* 1000 << endl;
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

		for (Light* light : lights) {
			Vector3d light_vector = light->getDirection();

			double distance = obj->intersect_sphere(ray, light_vector);
			if (distance < nearestDistance) {
				nearestDistance = distance;
				nearestObject = obj;
			}
		}
	}
	if (!nearestObject) {
		return 0;
	}
	return nearestDistance;
}

/*

Color ComputeLocalIllumination(Vector3d intersectionPoint, Vector3d normal) {

	Object3d* nearestObject = NULL;

	Color color = Color(1, 0, 0); // = kd

	for (Light* l : light) {
	//for (const auto& light : scene.lights) {
		Vector3d L = light->GetVectorToLightAtPoint(intersectionPoint); // vecteur L_i
		double dotNL = normal.dot(L); // produit scalaire N·L_i

		if (dotNL > 0) { // Si la source éclaire le pt intersection
			color += color * dotNL;
		}
	}

	return color;
}
*/