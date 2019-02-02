#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "vec3f.hpp"

#include <ostream>

struct Material {
	Vec3f color;
	bool isReflective;
	float shineness;
	float shineDamper;

	Material(Vec3f c, bool isReflective, float shineness, float shineDamper) :
		color{c},
		isReflective{isReflective},
		shineness{shineness},
		shineDamper{shineDamper}
	{
	}

	friend std::ostream& operator<<(std::ostream &os, const Material &m) {
		os << (m.isReflective ? "true" : "false") << " " << m.shineness << " "
			<< m.shineDamper;
		return os;
	}

};

#endif /* end of include guard: MATERIAL_HPP */
