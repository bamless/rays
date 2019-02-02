#include "vec3f.hpp"

#include <cmath>

Vec3f& Vec3f::operator+=(const Vec3f& v) {
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
	return *this;
}

Vec3f& Vec3f::operator*=(const Vec3f& v) {
	this->x *= v.x;
	this->y *= v.y;
	this->z *= v.z;
	return *this;
}

Vec3f& Vec3f::operator*=(float scalar) {
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
	return *this;
}

Vec3f& Vec3f::operator-=(const Vec3f& v) {
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;
	return *this;
}

Vec3f& Vec3f::operator/=(float scalar) {
	this->x /= scalar;
	this->y /= scalar;
	this->z /= scalar;
	return *this;
}

Vec3f operator-(Vec3f v) {
	v.x = -v.x;
	v.y = -v.y;
	v.z = -v.z;
	return v;
}

Vec3f operator+(Vec3f v1, const Vec3f& v2) {
	v1 += v2;
	return v1;
}

Vec3f operator*(Vec3f v1, const Vec3f& v2) {
	v1 *= v2;
	return v1;
}

Vec3f operator*(Vec3f v, float scalar) {
	v *= scalar;
	return v;
}

Vec3f operator-(Vec3f v1, const Vec3f& v2) {
	v1 -= v2;
	return v1;
}

Vec3f operator/(Vec3f v, float scalar) {
	v /= scalar;
	return v;
}

float Vec3f::dot(const Vec3f& v) const {
	return this->x * v.x + this->y * v.y + this->z * v.z;
}

Vec3f Vec3f::reflect(const Vec3f& normal) const {
	return normal * (-2 * this->dot(normal)) + *this;
}

float Vec3f::length2() const {
	return this->x * this->x + this->y * this->y + this->z * this->z;
}

float Vec3f::length() const {
	return sqrt(length2());
}

Vec3f& Vec3f::norm() {
	float len = length2();
	if(len > 0) {
		len = sqrt(len);
		this->x /= len;
		this->y /= len;
		this->z /= len;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Vec3f& v) {
	os << "vec3(" << v.x << ", " << v.y << ", " << v.z << ")";
	return os;
}
