#ifndef CAMERA_H
#define CAMERA_H

#include "matrix4f.hpp"
#include "ray.hpp"
#include "vec3.hpp"

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