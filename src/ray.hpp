#ifndef RAY_CPP
#define RAY_CPP

#include "vec3f.hpp"

#include <ostream>

const float RAY_BIAS = 1.e-4f;
const float RAY_MAX  = 1.e30f;

class Ray {
private:
	Vec3f origin;
	Vec3f dir;
	float length;

public:
	Ray(const Vec3f& origin, const Vec3f& dir);
	Ray(const Vec3f& origin, const Vec3f& dir, float length);

	Vec3f pointAtDistance(float d) const;

	const Vec3f& getOrigin() const;
	const Vec3f& getDirection() const;
	float getLength() const;

	friend std::ostream& operator<<(std::ostream& os, const Ray& r);
};

#endif /* end of include guard: RAY_CPP */
