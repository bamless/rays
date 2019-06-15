#ifndef VEC3F_HPP
#define VEC3F_HPP

#include <ostream>

struct Vec3f {
	float x, y, z;

	Vec3f() : x{0}, y{0}, z{0}
	{
	}

	Vec3f(float v) : x{v}, y{v}, z{v}
	{
	}

	Vec3f(float x, float y, float z) : x{x}, y{y}, z{z}
	{
	}

	Vec3f& operator+=(const Vec3f& v);
	Vec3f& operator*=(const Vec3f& v);
	Vec3f& operator*=(float scalar);
	Vec3f& operator-=(const Vec3f& v);
	Vec3f& operator/=(float scalar);

	friend Vec3f operator-(Vec3f v);
	friend Vec3f operator+(Vec3f v1, const Vec3f& v2);
	friend Vec3f operator*(Vec3f v1, const Vec3f& v2);
	friend Vec3f operator*(Vec3f v, float scalar);
	friend Vec3f operator-(Vec3f v1, const Vec3f& v2);
	friend Vec3f operator/(Vec3f v, float scalar);
	
	float dot(const Vec3f& v) const;
	Vec3f cross(const Vec3f& v) const;
	Vec3f reflect(const Vec3f& normal) const;

	float length2() const;
	float length() const;
	Vec3f& norm();

	friend std::ostream& operator<<(std::ostream& os, const Vec3f& v);
};

#endif /* end of include guard: VEC3F_HPP */
