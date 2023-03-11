#pragma once

#include "Object3d.h"
#include <string>

#include <vector>

using namespace std;


class Scene {
public:
    void addObject(Object3d* object);
    void render(const std::string& filename, int width, int height, Object3d* sphere);
    //Color traceRay(const Vector3d& rayOrigin, const Vector3d& rayDirection);
    Color traceRay(const Vector3d& rayOrigin, const Vector3d& rayDirection, Object3d* sphere);
private:
    std::vector<Object3d*> m_objects;
};


/*

#include <vector>
#include "Object3d.h"
#include "Light.h"
#include "Light.h"

#include<sstream>
#include<fstream>

using namespace std;


class Scene {
protected:
    std::vector<Object3d*> object3d;
    std::vector<Light*> lights;

public:
    void addObject(Object3d* obj);
    void addLight(Light* light);
    void render(string path, unsigned int width, unsigned int height);
    void rayIntersectsSphere(const Vector3d& rayOrigin, const Vector3d& rayDirection, const Object3d* sphere);
};
*/
