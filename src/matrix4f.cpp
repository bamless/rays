#include "matrix4f.hpp"

void Matrix4f::setIdentity() {
    for(int j = 0; j < 4; j++) {
        for(int i = 0; i < 4; i++) {
            val[M(i, j)] = i == j ? 1 : 0;
        }
    }
}

Matrix4f operator*(const Matrix4f& m1, const Matrix4f& m2) {
    Matrix4f res;
    for(int j = 0; j < 4; j++) {
        for(int i = 0; i < 4; i++) {
            for(int k = 0; k < 4; k++) {
                res.val[M(i, j)] += m1.val[M(i, k)] * m2.val[M(k, j)];
            }
        }
    }
    return res;
}

Vec3f operator*(const Matrix4f& m, const Vec3f& v) {
    float res[4] = {0};
    float vec4[4] = {v.x, v.y, v.z, 1};

    for(int i = 0; i < 4; i++) {
        for(int k = 0; k < 4; k++) {
            res[i] += m.val[M(i, k)] * vec4[k];
        }
    }

    return Vec3f(res[0], res[1], res[2]);
}

std::ostream& operator<<(std::ostream& os, const Matrix4f& m) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            os << m.val[M(i, j)] << " ";
        }
        os << std::endl;
    }
    return os;
}
