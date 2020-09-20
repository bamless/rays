#ifndef MATRIX4F_H
#define MATRIX4F_H

#include <cassert>
#include <initializer_list>
#include <iostream>

#include "vec3.hpp"

struct Matrix4f {
    union {
        float m[4][4];
        float data[16];
        struct {
            float m00, m01, m02, m03;
            float m10, m11, m12, m13;
            float m20, m21, m22, m23;
            float m30, m31, m32, m33;
        };
    };

    Matrix4f() { setIdentity(); }

    Matrix4f(std::initializer_list<float> il) {
        assert(il.size() == 16);
        std::copy(std::begin(il), std::end(il), data);
    }

    void setIdentity();

    friend Matrix4f operator*(const Matrix4f& m1, const Matrix4f& m2);
    friend Vec3f operator*(const Matrix4f& m, const Vec3f& v);

    friend std::ostream& operator<<(std::ostream& os, const Matrix4f& m);
};

#endif