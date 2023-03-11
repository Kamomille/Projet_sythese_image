#include "Sphere.h"
#include "Vector3d.h"
#include "Object3d.h"

Sphere::Sphere(Vector3d position, float size): Object3d(position, size), m_center(position)
{
}

Vector3d Sphere::getCenter()
{
    return m_center;
}
/*
float Sphere::distance(const Vector3d& point) const {
    // Calculer la distance entre le centre de la sphère et le point donné
    return 10; // (point - m_center).Magnitude() - m_radius;
}
*/

/*
double Sphere::getSurfaceArea(int radius) {
    return 4.0 * 3.14 * radius * radius;
}

// Méthode Get Center pour donner le centre
double Sphere::GetCenter() {
    return center;
}

*/














/*

// Clément

  double intersects(const Ray &ray) override {
    Vector3d CO  = this->center - ray.origin;

    Vector3d b   = 2 * (ray.direction.Dot(CO));
    double c     = CO.Dot(CO) - this->radius * this->radius;
    double delta = -4 * c;

    if (delta < 0)
      return std::numeric_limits<double>::infinity();

    double x1 = ((-b - std::sqrt(delta)) / 2).Normalize();
    double x2 = ((-b + std::sqrt(delta)) / 2).Normalize();

    if (x1 < x2 && x1 > 0)
      return x1;
    else if (x2 < x1 && x2 > 0)
      return x2;
    else
      return std::numeric_limits<double>::infinity();
  }

*/
