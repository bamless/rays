#include "sphere.hpp"

#include <cmath>

Sphere::Sphere(const Material& m, const Vec3f& center, float radius)
    : Shape(m), center{center}, radius{radius} {}

float Sphere::intersect(const Ray& r) const {
    Ray transRay(r.getOrigin() - this->center, r.getDirection());

    float a = transRay.getDirection().length2();
    float b = 2 * dot(transRay.getDirection(), transRay.getOrigin());
    float c = transRay.getOrigin().length2() - this->radius * this->radius;

    float disc = b * b - 4 * a * c;
    if(disc < 0) {
        return -1;
    }

    disc = sqrt(disc);
    float p1 = (-b - disc) / (2 * a);
    float p2 = (-b + disc) / (2 * a);

    if(p1 > RAY_BIAS && p1 < r.getLength()) {
        return p1;
    } else if(p2 > RAY_BIAS && p2 < r.getLength()) {
        return p2;
    }

    return -1;
}

Vec3f Sphere::normalAtPoint(const Vec3f& p) const {
    Vec3f norm = p - center;
    norm.norm();
    return norm;
}
