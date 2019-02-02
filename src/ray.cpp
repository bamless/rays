#include "ray.hpp"

Ray::Ray(const Vec3f& origin, const Vec3f& dir) :
	origin{origin},
	dir{dir},
	length{RAY_MAX}
{
}

Ray::Ray(const Vec3f& origin, const Vec3f& dir, float length) :
	origin{origin},
	dir{dir},
	length{length}
{
}

Vec3f Ray::pointAtDistance(float d) const {
	return this->origin + this->dir * d;
}

const Vec3f& Ray::getOrigin() const {
	return this->origin;
}

const Vec3f& Ray::getDirection() const {
	return this->dir;
}

float Ray::getLength() const {
	return this->length;
}

std::ostream& operator<<(std::ostream& os, const Ray& r) {
	os << "ray(origin: " << r.origin << ", direction: " << r.dir <<
		", length: " << r.length;
	return os;
}
