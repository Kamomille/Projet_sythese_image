#include "Scene.h"
#include "Sphere.h"
#include "DirectionalLight.h"

using namespace std;

int first_scene() {
	Scene scene;

	Sphere* sphere = new Sphere(Vector3d(0, 0, 0), 0.25);
	sphere->setColor(Color(1, 0, 0));
	scene.addObject(sphere);

	Light* light = new DirectionalLight(Vector3d(-1, -1, 0));
	scene.addLight(light);

	scene.render("step3.bmp", 1024, 1024);

	return 0;
}

int second_scene(string picture_name, float a) {

	Scene scene;

	Sphere* sphere_1 = new Sphere(Vector3d(-0.25 + 2*a, 0.25, 0), 0.15); // rouge
	sphere_1->setColor(Color(1, 0, 0));
	scene.addObject(sphere_1);

	Sphere* sphere_2 = new Sphere(Vector3d(0.25 - a, 0.25 - 2*a, 0), 0.15); // vert
	sphere_2->setColor(Color(0, 1, 0));
	scene.addObject(sphere_2);

	Sphere* sphere_3 = new Sphere(Vector3d(0 - a, -0.25 + 2*a, 0), 0.15); // bleu
	sphere_3->setColor(Color(0, 0, 1));
	scene.addObject(sphere_3);

	Sphere* sphere_4 = new Sphere(Vector3d(0, 0, -10), 0.16); // gris
	sphere_4->setColor(Color(0.8, 0.8, 0.8));
	scene.addObject(sphere_4);

	Light* light_1 = new DirectionalLight(Vector3d(0, 0, -1));
	scene.addLight(light_1);

	Light* light_2 = new DirectionalLight(Vector3d(1, 1, 0));
	scene.addLight(light_2);

	scene.render(picture_name, 1024, 1024);

	return 0;
}

int animation() {
	float a = 0;
	// -0.25 + 2*a = 0.25
	// 0.1 * 5

	for (int y = 1; y <= 20; y++){
		a += 0.005;
		second_scene("6_animation_images/step6-0" + to_string(y) + ".bmp", a);
	}
	return 0;
}

int main() {
	first_scene();
	second_scene("step4.bmp", 0);
	//animation();

	return 0;
}

// Anti-aliasing

/*
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <FreeImage.h>

// Fonction pour générer un nombre aléatoire entre 0 et 1
float randFloat()
{
	return (float)rand() / RAND_MAX;
}

// Fonction pour générer un vecteur aléatoire dans la sphère unité
vec3 random_in_unit_sphere() {
	vec3 p;
	do {
		p = 2.0 * vec3(randFloat(), randFloat(), randFloat()) - vec3(1, 1, 1);
	} while (p.squared_length() >= 1.0);
	return p;
}

// Fonction pour lancer des rayons
vec3 ray_color(const ray& r, const hittable& world, int depth) {
	hit_record rec;

	// Si la profondeur maximale est atteinte, on renvoie du noir
	if (depth <= 0)
		return vec3(0, 0, 0);

	// Si le rayon intersecte l'objet, on calcule la couleur
	if (world.hit(r, 0.001, infinity, rec)) {
		ray scattered;
		vec3 attenuation;
		if (rec.mat_ptr->scatter(r, rec, attenuation, scattered)) {
			return attenuation * ray_color(scattered, world, depth - 1);
		}
		return vec3(0, 0, 0);
	}

	// On calcule la couleur de fond
	vec3 unit_direction = unit_vector(r.direction());
	float t = 0.5 * (unit_direction.y() + 1.0);
	return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
}

// Fonction pour générer une couleur moyenne pour un pixel
vec3 sample_pixel_color(const camera& cam, const hittable& world, int x, int y, int num_samples)
{
	vec3 color(0, 0, 0);
	for (int s = 0; s < num_samples; ++s) {
		float u = float(x + randFloat()) / float(cam.width());
		float v = float(y + randFloat()) / float(cam.height());
		ray r = cam.get_ray(u, v);
		color += ray_color(r, world, 50);
	}
	return color / float(num_samples);
}

*/

