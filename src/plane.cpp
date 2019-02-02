#include "plane.hpp"

Plane::Plane(const Material &m, const Vec3f& normal, const Vec3f& point) :
	Shape(m),
	normal{normal},
	point{point}
{
}

float Plane::intersect(const Ray& r) const {
	float dDotN = this->normal.dot(r.getDirection());
	if(dDotN < 1.e-6) {
		return -1;
	}

	float p = (this->point - r.getOrigin()).dot(this->normal) / dDotN;
	if(p < RAY_BIAS || p > r.getLength()) {
		return -1;
	}

	return p;
}

Vec3f Plane::normalAtPoint(const Vec3f& p) const {
	(void) p;
	return -this->normal;
}
