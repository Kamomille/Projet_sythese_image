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


Vector3d Sphere::GetNormalAtPoint(const Vector3d hit_point) {
    Vector3d normal = hit_point - center;
    normal.normalize();
    return normal;
}



double Sphere::intersect_sphere(const Ray& ray, Vector3d light)
{
    float Light_intensity = 0.2;

    float intensity = 0;

    float distance = getNearestIntersectionsDistance(ray);
   
    if (distance >= 0) {
        Vector3d hit_point = ray.getOrigin() + ray.getDirection() * distance; // P = origine_du_rayon + direction_du_rayon * distance_au_point_d_intersection

        Vector3d normal = GetNormalAtPoint(hit_point);
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


