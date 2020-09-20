#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "material.hpp"
#include "ray.hpp"
#include "shape.hpp"
#include "vec3.hpp"

class Sphere : public Shape {
private:
    Vec3f center;
    float radius;

public:
    Sphere(const Material& m, const Vec3f& center, float radius);

    float intersect(const Ray& r) const;
    Vec3f normalAtPoint(const Vec3f& p) const;
};

#endif /* end of include guard: SPHERE_HPP */
