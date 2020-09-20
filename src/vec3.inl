#include <cmath>

template <typename T>
Vec3<T>& Vec3<T>::operator+=(const Vec3<T>& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

template <typename T>
Vec3<T>& Vec3<T>::operator*=(const Vec3<T>& v) {
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
}

template <typename T>
Vec3<T>& Vec3<T>::operator*=(T scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

template <typename T>
Vec3<T>& Vec3<T>::operator-=(const Vec3<T>& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

template <typename T>
Vec3<T>& Vec3<T>::operator/=(T scalar) {
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
}

template <typename T>
Vec3<T> operator-(Vec3<T> v) {
    v.x = -v.x;
    v.y = -v.y;
    v.z = -v.z;
    return v;
}

template <typename T>
T Vec3<T>::length2() const {
    return x * x + y * y + z * z;
}

template <typename T>
T Vec3<T>::length() const {
    return sqrt(length2());
}

template <typename T>
Vec3<T>& Vec3<T>::norm() {
    T len = length2();
    if(len > 0) {
        len = sqrt(len);
        x /= len;
        y /= len;
        z /= len;
    }
    return *this;
}

template <typename T>
Vec3<T> operator+(Vec3<T> v1, const Vec3<T>& v2) {
    v1 += v2;
    return v1;
}

template <typename T>
Vec3<T> operator*(Vec3<T> v1, const Vec3<T>& v2) {
    v1 *= v2;
    return v1;
}

template <typename T>
Vec3<T> operator*(Vec3<T> v, T scalar) {
    v *= scalar;
    return v;
}

template <typename T>
Vec3<T> operator-(Vec3<T> v1, const Vec3<T>& v2) {
    v1 -= v2;
    return v1;
}

template <typename T>
Vec3<T> operator/(Vec3<T> v, T scalar) {
    v /= scalar;
    return v;
}

template <typename T>
T dot(const Vec3<T>& v1, const Vec3<T>& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

template <typename T>
Vec3<T> cross(const Vec3<T>& v1, const Vec3<T>& v2) {
    return Vec3<T>(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
}

template <typename T>
Vec3<T> reflect(const Vec3<T>& vec, const Vec3<T>& normal) {
    return normal * (-2 * dot(vec, normal)) + vec;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vec3<T>& v) {
    os << "vec3(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}
