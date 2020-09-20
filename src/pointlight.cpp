#include "pointlight.hpp"

PointLight::PointLight(const Vec3f& color, float intensity, const Vec3f& pos, const Vec3f& att)
    : Light(color, intensity), pos{pos}, att{att} {}

Vec3f PointLight::directionAtPoint(const Vec3f& p) const {
    Vec3f dir = p - pos;
    dir.norm();
    return dir;
}

float PointLight::intensityAtPoint(const Vec3f& p) const {
    float distance = (pos - p).length();
    float attFactor = att.x + (att.y * distance) + (att.z * distance * distance);
    return intensity / attFactor;
}

float PointLight::pointDistance(const Vec3f& p) const {
    return (pos - p).length();
}
