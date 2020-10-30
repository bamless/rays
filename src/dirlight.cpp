#include "dirlight.hpp"

#include "ray.hpp"

DirLight::DirLight(const Vec3f& color, float intensity, const Vec3f& dir)
    : Light(color, intensity), dir{dir} {}

Vec3f DirLight::directionAtPoint(const Vec3f& p) const {
    (void)p;
    return dir;
}

float DirLight::intensityAtPoint(const Vec3f& p) const {
    (void)p;
    return getIntensity();
}

float DirLight::pointDistance(const Vec3f& p) const {
    (void)p;
    return RAY_MAX;
}
