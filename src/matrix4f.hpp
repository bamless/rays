#ifndef MATRIX4F_H
#define MATRIX4F_H

#include "vec3f.hpp"

#include <iostream>
#include <initializer_list>

#define M(r, c) (r * 4 + c)

struct Matrix4f {
    float val[16];

    Matrix4f() {  
        setIdentity();
    }

    Matrix4f(std::initializer_list<float> il)  {
        if(il.size() != 16) {
            throw std::invalid_argument("Initializer list must be exactly 16 in length");
        }
        std::copy(std::begin(il), std::end(il), val);
    }

    void setIdentity();

    friend Matrix4f operator*(const Matrix4f& m1, const Matrix4f& m2);
    friend Vec3f operator*(const Matrix4f& m, const Vec3f& v);

	friend std::ostream& operator<<(std::ostream& os, const Matrix4f& m);
};

#endif