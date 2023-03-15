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
			float add = raytrace_2(ray);
			color.r -= add;
			color.g -= add;
			color.b -= add;

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


// ------------ Anti-aliasing ------------
// J'ai tenté la partie mais ca ne marche pas encore

#include <iostream>
#include <cmath>
#include <cstdlib>

//générer un nb aléatoire entre 0 et 1
float Scene::randFloat()
{
	return (float)rand() / RAND_MAX;
}

// générer vecteur aléatoire dans la sphère unité
Vector3d Scene::random_in_unit_sphere() {
	Vector3d p;
	do {
		p = 2.0 * Vector3d(randFloat(), randFloat(), randFloat()) - Vector3d(1, 1, 1);
	} while (p.getLength() >= 1.0);
	return p;
}

// Fonction pour générer une couleur moyenne pour un pixel
Color Scene::sample_pixel_color(Ray r, int x, int y, int num_samples)
{
	Color color(0, 0, 0);
	for (int s = 0; s < num_samples; ++s) {
		float u = float(x + randFloat()) / 1024.0f;
		float v = float(y + randFloat()) / 1024.0f;

		Color color_r = raytrace(r);
		color += color_r;
	}
	return color;
}