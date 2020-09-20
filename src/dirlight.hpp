#ifndef DIR_LIGHT_HPP
#define DIR_LIGHT_HPP

#include "light.hpp"

class DirLight : public Light {
private:
    Vec3f dir;

public:
    DirLight(const Vec3f& color, float intensity, const Vec3f& dir);

    Vec3f directionAtPoint(const Vec3f& p) const;
    float intensityAtPoint(const Vec3f& p) const;
    float pointDistance(const Vec3f& p) const;
};

#endif /* end of include guard: DIR_LIGHT_HPP */
