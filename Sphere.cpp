#include "Sphere.h"

Sphere::Sphere(const Vector3d& _center, double _radius)
	: Object3d(),
	center(_center),
	radius(_radius)
{
}

double Sphere::getNearestIntersectionsDistance(const Ray& ray)
{
	Vector3d co = ray.getOrigin() - center;
	double b = (co.dot(ray.getDirection()));
	double disc = b * b - (co.dot(co)) + radius * radius;
	if (disc < 0) {
		return 10000.0;
	}
	return -b - sqrt(disc);
}



double Sphere::getNearestIntersectionsDistance_2(const Ray& ray)
{
    Vector3d light(-1, -1, 1);
    float Light_intensity = 0.25;

    float intensity = 0;

    float distance = getNearestIntersectionsDistance(ray); // intersect_sphere(ray);
   
    if (distance >= 0) {
        Vector3d hit_point = ray.getOrigin() + ray.getDirection() * distance;
        Vector3d normal = hit_point - center;
        normal.normalize();

        Vector3d to_light = light - hit_point;

        float distance_to_light = to_light.getLength();
        to_light.normalize();

        intensity += Light_intensity * to_light.dot(normal) / (distance_to_light * distance_to_light);

        return intensity / (1 + distance * distance);
    }
    else {
        return 0;
    }

}


/*
Vector3d center = Vector3d(0.15, 0, 0);

Vector3d co = ray.getOrigin() - center;
double b = (co.dot(ray.getDirection()));
double disc = b * b - (co.dot(co)) + radius * radius;
if (disc < 0) {
    return 10000.0;
}
return -b - sqrt(disc);*/










float Sphere::intersect_sphere(const Ray& ray) {
    /*
    Vector3d co = ray.getOrigin() - center;

    float a = ray.getDirection().dot(ray.getDirection());
    float b = 2 * co.dot(ray.getDirection());
    float c = co.dot(co) - radius * radius;
    float disc = b * b - 4 * a * c;
    if (disc < 0) {
        return -1;
    }
    else {
        float t1 = (-b - sqrt(disc)) / (2 * a);
        float t2 = (-b + sqrt(disc)) / (2 * a);
        if (t1 < 0) {
            return t2;
        }
        else if (t2 < 0) {
            return t1;
        }
        else {
            return fmin(t1, t2);
        }
    }*/
    return 0.0;
}