#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "material.hpp"
#include "ray.hpp"

class Shape {
private:
    Material mat;

public:
    Shape(const Material& m) : mat{m} {}
    virtual ~Shape() = default;

    void setMaterial(const Material& m) { mat = m; }

    Material& getMaterial() { return mat; }

    virtual float intersect(const Ray& r) const = 0;
    virtual Vec3f normalAtPoint(const Vec3f& p) const = 0;
};

#endif /* end of include guard: SHAPE_HPP */
