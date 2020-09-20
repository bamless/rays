#ifndef VEC3F_HPP
#define VEC3F_HPP

#include <ostream>

template <typename T>
struct Vec3 {
    union {
        T data[3];
        struct {
            T x, y, z;
        };
    };

    Vec3() : x{0}, y{0}, z{0} {}
    Vec3(T v) : x{v}, y{v}, z{v} {}
    Vec3(T x, T y, T z) : x{x}, y{y}, z{z} {}

    Vec3<T>& operator+=(const Vec3<T>& v);
    Vec3<T>& operator*=(const Vec3<T>& v);
    Vec3<T>& operator*=(T scalar);
    Vec3<T>& operator-=(const Vec3<T>& v);
    Vec3<T>& operator/=(T scalar);

    T length2() const;
    T length() const;
    Vec3<T>& norm();
};

template <typename T>
Vec3<T> operator-(Vec3<T> v);
template <typename T>
Vec3<T> operator+(Vec3<T> v1, const Vec3<T>& v2);
template <typename T>
Vec3<T> operator*(Vec3<T> v1, const Vec3<T>& v2);
template <typename T>
Vec3<T> operator*(Vec3<T> v, T scalar);
template <typename T>
Vec3<T> operator-(Vec3<T> v1, const Vec3<T>& v2);
template <typename T>
Vec3<T> operator/(Vec3<T> v, T scalar);
template <typename T>
T dot(const Vec3<T>& v1, const Vec3<T>& v2);
template <typename T>
Vec3<T> cross(const Vec3<T>& v1, const Vec3<T>& v2);
template <typename T>
Vec3<T> reflect(const Vec3<T>& vec, const Vec3<T>& normal);
template <typename T>
std::ostream& operator<<(std::ostream& os, const Vec3<T>& v);

using Vec3f = Vec3<float>;

#include "vec3.inl"

#endif
