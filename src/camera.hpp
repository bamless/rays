#ifndef CAMERA_H
#define CAMERA_H

#include "ray.hpp"
#include "vec3f.hpp"
#include "matrix4f.hpp"

class Camera {
private:
    Matrix4f transform;

public:
    void lookAt(const Vec3f& from, const Vec3f& p);
    Ray generateRay(float x, float y) const;

    void setTransformationMatrix(const Matrix4f& transform);
    const Matrix4f& getTransformationMatrix() const;
};

#endif