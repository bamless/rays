#ifndef PLANE_HPP
#define PLANE_HPP

#include "material.hpp"
#include "shape.hpp"
#include "vec3.hpp"

class Plane : public Shape {
private:
    Vec3f normal;
    Vec3f point;

public:
    Plane(const Material& m, const Vec3f& normal, const Vec3f& point);

    float intersect(const Ray& r) const;
    Vec3f normalAtPoint(const Vec3f& p) const;
};

#endif /* end of include guard: PLANE_HPP */
