#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "vec3.hpp"

class Light {
protected:
    Vec3f color;
    float intensity;

public:
    Light(const Vec3f& color, float intensity) : color{color}, intensity{intensity} {}
    virtual ~Light() = default;

    virtual Vec3f directionAtPoint(const Vec3f& p) const = 0;
    virtual float intensityAtPoint(const Vec3f& p) const = 0;
    virtual float pointDistance(const Vec3f& p) const = 0;

    const Vec3f& getColor() const { return color; }
};

#endif /* end of include guard: LIGHT_HPP */
