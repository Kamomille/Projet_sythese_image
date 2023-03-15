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

	Sphere* sphere_4 = new Sphere(Vector3d(0, 0, -10), 0.6); // gris
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
	for (int y = 1; y <= 20; y++){
		a += 0.01;
		second_scene("6_animation_images/step6-0" + to_string(y) + ".bmp", a);
	}
	return 0;
}

int main() {
    //first_scene();
    //second_scene("step4.bmp", 0);
    animation();
    return 0;
}