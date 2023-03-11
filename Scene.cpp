#include "Scene.h"
#include "Object3d.h"
#include "Sphere.h"
#include "Light.h"
#include "Color.h"
#include "BMPHelper.h"
#include "Vector3d.h"


#include <iostream>

void Scene::addObject(Object3d* object) {
    m_objects.push_back(object);
}

Color Scene::traceRay(const Vector3d& rayOrigin, const Vector3d& rayDirection, Object3d* sphere) {

    Vector3d oc = rayOrigin - Vector3d(0.1f, 0.0f, 00.0f); // sphere.getCenter();
    float a = rayDirection.Dot(rayDirection);
    float b = 2.0f * oc.Dot(rayDirection);
    float c = oc.Dot(oc) - 0.1 * 0.1; // sphere.getRadius()* sphere.getRadius();
    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0) { // rayon ne touche pas la sphère
        return Color(0, 0, 0); //INFINITY;  
    }

    float t1 = (-b - std::sqrt(discriminant)) / (2 * a);
    float t2 = (-b + std::sqrt(discriminant)) / (2 * a);

    float t = std::min(t1, t2);
    if (t < 0) {
        return Color(0, 0, 0);
    }

    Color surfaceColor = Color(100, 100, 0);//sphere.getColor();

    return surfaceColor; 
}




void Scene::render(const std::string& filename, int width, int height, Object3d* sphere) {

    unsigned char* colors = new unsigned char[width * height * 3]; 
    float aspectRatio = static_cast<float>(width) / static_cast<float>(height); // rapport hauteur / largeur

    for (int j = 0; j < height; ++j) {
        for (int i = 0; i < width; ++i) {
            float x = (2.0f * static_cast<float>(i) / static_cast<float>(width) - 1.0f) * aspectRatio; // coordonnée x dans la plage [-aspectRatio, aspectRatio]
            float y = 1.0f - 2.0f * static_cast<float>(j) / static_cast<float>(height); // coordonnée y dans la plage [-1, 1]

            Vector3d rayOrigin(0.0f, 0.0f, 10.0f); 
            Vector3d rayDirection(x, y, -1.0f); 
            rayDirection.Normalize(); 

            Color color = traceRay(rayOrigin, rayDirection, sphere);
            //Color color(255, 0, 0);

            colors[(j * width + i) * 3 + 0] = color.r;
            colors[(j * width + i) * 3 + 1] = color.g;
            colors[(j * width + i) * 3 + 2] = color.b;
        }
    }

    BMPHelper::SaveBmp(filename, colors, width, height);

    delete[] colors; 
}




/*
#include "Scene.h"
#include "Object3d.h"
#include "Sphere.h"
#include "Light.h"
#include "Color.h"
#include "BMPHelper.h"


#include<sstream>
#include<fstream>

using namespace std;

void Scene::addObject(Object3d* obj) {
    this->object3d.push_back(obj);
}

void Scene::addLight(Light* light) { 
    this->lights.push_back(light); 
}


void Scene::addObject(Object3d* object) {
    objects.push_back(object);
}

// Function Raycing dans son pp
void Scene::render(string filename, unsigned int width, unsigned int height) {
    unsigned char* colors = new unsigned char[width*height * 3];

    for (unsigned int i = 0; i < height; i++) {
        for (unsigned int j = 0; j < width; j++) {

            // follow a R ray (eye -> P) in scene
            int idx = ((i * width) + j) * 3;
            Color color(255, 0, 0);
            colors[idx] = color.r;
            colors[idx + 1] = color.g;
            colors[idx + 2] = color.b;
        }
    }
    // drawSphere

    Color color_2(0, 0, 255);
    int centerY = width/2;
    int centerX = width/2;
    int radius = 100;

    for (int y = centerY - radius; y <= centerY + radius; y++) {
        for (int x = centerX - radius; x <= centerX + radius; x++) {
            int distance = sqrt((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY));
            if (distance <= radius) {
                int idx = ((y * width) + x) * 3;
                colors[idx] = color_2.r;
                colors[idx + 1] = color_2.g;
                colors[idx + 2] = color_2.b;
            }
        }
    }

    BMPHelper::SaveBmp(filename, colors, width, height);

    delete[]colors;
}

double rayIntersectsSphere(const Vector3d& rayOrigin, const Vector3d& rayDirection, const Object3d& sphere) {
    double dist = 1;

    Vector3d oc = rayOrigin - 10;// sphere.center;
    float a = rayDirection.Dot(rayDirection);
    float b = 2.0 * oc.Dot(rayDirection);
    float c = oc.Dot(oc) - 100;// sphere.center* sphere.center;
    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0) { // rayon ne touche pas la sphère
        return INFINITY; //infini 
    }
    else { // rayon touche la sphère
        return dist;
    }
}
*/



/*

bool rayIntersectsSphere(const Vector3& rayOrigin, const Vector3& rayDirection, const Sphere& sphere) {
    Vector3 oc = rayOrigin - sphere.center;
    float a = rayDirection.dot(rayDirection);
    float b = 2.0 * oc.dot(rayDirection);
    float c = oc.dot(oc) - sphere.radius * sphere.radius;
    float discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        // Le rayon ne touche pas la sphère
        return false;
    }
    else {
        // Le rayon touche la sphère
        return true;
    }
}

*/