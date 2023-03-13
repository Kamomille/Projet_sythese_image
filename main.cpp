// Projet_sythese_image.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "Scene.h"

#include "Object3d.h"
#include "Color.h"
#include "DirectionalLight.h"
#include "Sphere.h"
#include "Vector3d.h"
#include "Light.h"


int main()
{
    Scene scene;
    
    Object3d* sphere = new Sphere(Vector3d(0.0f, 0.0f, 0.0f), 1.0f);
    sphere->SetColor(Color(0, 0, 255));
    scene.addObject(sphere);

    Light* light = new DirectionalLight(Vector3d(-1, -1, 0));
    scene.addLight(light);
    
    scene.render("test.bmp", 1000, 1000, sphere, light);

    /*
    Vector3d rayOrigin(0, 0, 10);
    Vector3d rayDirection(0, 0, 1);
    scene.rayIntersectsSphere(rayOrigin, rayDirection, sphere);*/

}





/*
//std::cout << "Hello World!\n";
*/
