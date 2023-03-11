#pragma once

#include "Vector3d.h"
#include "Color.h"

class Object3d {
public:
    Object3d(Vector3d position, float size);
    void SetColor(Color color);
    ///virtual*/ ~Object3d();
    //virtual float distance(const Vector3d& point) const;
    float distance();
    Color getColor();
    Vector3d getCenter();
    float getRadius();
private:
    Vector3d m_position;
    float m_size;
    Color m_color;
    float size;
};



/*

class Object3d {
private:
	Vector3d origin;
	Color color;

protected:
	explicit Object3d(const Vector3d&);

public:
	void SetColor(Color);
};
*/

