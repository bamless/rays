#include "camera.hpp"

void Camera::lookAt(const Vec3f& from, const Vec3f& p) {
    Vec3f tmp(0, 1, 0);
    Vec3f forward = (from - p).norm();
    Vec3f right = cross(tmp.norm(), forward);
    Vec3f up = cross(forward, right);
    transform = Matrix4f{
        right.x, up.x, forward.x, from.x, right.y, up.y, forward.y, from.y,
        right.z, up.z, forward.z, from.z, 0,       0,    0,         0,
    };
}

Ray Camera::generateRay(float x, float y) const {
    Vec3f rayOriginWorld = transform * Vec3f(0);
    Vec3f rayPixelWorld = transform * Vec3f(x, y, -1);
    return Ray(rayOriginWorld, (rayPixelWorld - rayOriginWorld).norm());
}

void Camera::setTransformationMatrix(const Matrix4f& transform) {
    this->transform = transform;
}

const Matrix4f& Camera::getTransformationMatrix() const {
    return this->transform;
}