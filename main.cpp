#include "Scene.h"
#include "Sphere.h"
#include "DirectionalLight.h"

int main() {
	Scene scene;

	Sphere* sphere = new Sphere(Vector3d(0, 0, 0), 0.25);
	sphere->setColor(Color(1, 0, 0));
	scene.addObject(sphere);

	Light *light = new DirectionalLight(Vector3d(-1, -1, 0));
	scene.addLight(light);

	scene.render("tp.bmp", 1024, 1024);

	return 0;
}
