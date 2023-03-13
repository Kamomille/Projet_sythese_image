#include "Scene.h"
#include "Object3d.h"
#include "Sphere.h"
#include "Light.h"
#include "Color.h"
#include "BMPHelper.h"
#include "Vector3d.h"


#include <iostream>


void Scene::addObject(Object3d* object) {
    objects_.push_back(object);
}

void Scene::addLight(Light* light) {
    light_.push_back(light);
}

Color Scene::traceRay(const Vector3d& rayOrigin, const Vector3d& rayDirection, Object3d* sphere) {

    Vector3d oc = rayOrigin - sphere->getCenter(); 
    float a = rayDirection.Dot(rayDirection);
    float b = 2.0f * oc.Dot(rayDirection);
    float c = oc.Dot(oc) - sphere->getRadius() * sphere->getRadius();
    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0) { // rayon ne touche pas la sphère
        return INFINITY; 
    }

    float t1 = (-b - std::sqrt(discriminant)) / (2 * a);
    float t2 = (-b + std::sqrt(discriminant)) / (2 * a);

    float t = std::min(t1, t2);
    if (t < 0) {
        return INFINITY; // Color(0, 0, 0);
    }

    Color surfaceColor = sphere->getColor();

    return surfaceColor; 
}

float Scene::traceRay_2(const Vector3d& rayOrigin, const Vector3d& rayDirection, Object3d* sphere) {

    Vector3d oc = rayOrigin - sphere->getCenter();
    float a = rayDirection.Dot(rayDirection);
    float b = 2.0f * oc.Dot(rayDirection);
    float c = oc.Dot(oc) - sphere->getRadius() * sphere->getRadius();
    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0) { // rayon ne touche pas la sphère
        return 0;
    }

    float t1 = (-b - std::sqrt(discriminant)) / (2 * a);
    float t2 = (-b + std::sqrt(discriminant)) / (2 * a);

    float t = std::min(t1, t2);
    if (t < 0) {
        return 0; // Color(0, 0, 0);
    }

    //int intensite
    t = (t - 7) * 100;

    //std::cout << t;
    //std::cout << "\n";

    return t;
}


Color Scene::addSomeLight(Light* light, Object3d* sphere, int x, int y, float t) {

    Vector3d lightDir = Vector3d(-1, -1, 0);
    Vector3d rayOrigin(0.0f, 0.0f, 10.0f);
    int width = 1000;
    int height = 1000;


    // Calcul de la direction du rayon
    Vector3d rayDir(x - width / 2, height / 2 - y, -width / 2);
    rayDir.Normalize();

    // Calcul de l'intersection entre le rayon et la sphère
    //float t = 1.0;

    // Calcul de la normale à la surface de la sphère au point d'intersection
    Vector3d hitPoint = rayOrigin + t * rayDir;
    Vector3d normal = hitPoint - sphere->getCenter();
    normal.Normalize();


    // Calcul de la couleur de l'objet en fonction de la lumière
    /*
    Color color = sphere->getColor();
    float intensity = normal.Dot(lightDir);
    intensity = max(0.0f, intensity);*/

    Color color = Color(0, 0, t);
    return color;

}



void Scene::render(const std::string& filename, int width, int height, Object3d* sphere, Light* light) {


    Vector3d lightDirection(-1.0f, -1.0f, -1.0f);
    lightDirection.Normalize();


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


            int t = traceRay_2(rayOrigin, rayDirection, sphere);
            if (t != 0){
                color = addSomeLight(light, sphere, x, y, t);
            }


            /*
            Vector3d point = rayOrigin + 10 * rayDirection; // t=10
            Vector3d normal = sphere->getNormal(point, sphere->getCenter());
            //color = color * normal.dotProduct(normal, lightDirection);
            if (height/1.9 < i) {
                color.r = 100;
                //color = color * normal.dotProduct(normal, lightDirection);
            }*/


            colors[(j * width + i) * 3 + 0] = color.r; // abs(255 - color.r);
            colors[(j * width + i) * 3 + 1] = color.g; // abs(255 - color.g);
            colors[(j * width + i) * 3 + 2] = abs(255 - color.b);
        }
    }

    BMPHelper::SaveBmp(filename, colors, width, height);

    delete[] colors; 
}

