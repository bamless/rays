#ifndef POINT_LIGHT_HPP
#define POINT_LIGHT_HPP

#include "light.hpp"

class PointLight : public Light {
private:
	Vec3f pos;
	Vec3f att;

public:
	PointLight(const Vec3f& color, float intensity,
		       const Vec3f& pos, const Vec3f& att);

	Vec3f directionAtPoint(const Vec3f& p) const;
	float intensityAtPoint(const Vec3f& p) const;
	float pointDistance(const Vec3f& p) const;
};

#endif /* end of include guard: POINT_LIGHT_HPP */
