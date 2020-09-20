#include "matrix4f.hpp"

void Matrix4f::setIdentity() {
    for(int j = 0; j < 4; j++) {
        for(int i = 0; i < 4; i++) {
            m[i][j] = i == j ? 1 : 0;
        }
    }
}

Matrix4f operator*(const Matrix4f& matrix1, const Matrix4f& matrix2) {
    Matrix4f res;
    for(int j = 0; j < 4; j++) {
        for(int i = 0; i < 4; i++) {
            for(int k = 0; k < 4; k++) {
                res.m[i][j] += matrix1.m[i][k] * matrix2.m[k][j];
            }
        }
    }
    return res;
}

Vec3f operator*(const Matrix4f& matrix, const Vec3f& v) {
    float res[4] = {0};
    float vec4[4] = {v.x, v.y, v.z, 1};

    for(int i = 0; i < 4; i++) {
        for(int k = 0; k < 4; k++) {
            res[i] += matrix.m[i][k] * vec4[k];
        }
    }

    return Vec3f(res[0], res[1], res[2]);
}

std::ostream& operator<<(std::ostream& os, const Matrix4f& matrix) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            os << matrix.m[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}
