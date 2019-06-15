#include "scene.hpp"
#include "shape.hpp"
#include "plane.hpp"
#include "sphere.hpp"
#include "light.hpp"
#include "dirlight.hpp"
#include "pointlight.hpp"

#include "matrix4f.hpp"
#include <iostream>

#include <memory>

const int FOV = 75;
const int SAMPLES = 2;

const Vec3f COLOR_WHITE(1, 1, 1);
const Vec3f COLOR_BLACK(0, 0, 0);
const Vec3f COLOR_RED(1, 0, 0);
const Vec3f COLOR_GREEN(0, 1, 0);
const Vec3f COLOR_BLUE(0, 0, 1);

int main() {

	Material m1(COLOR_WHITE, false, 1, 100);
	Material m2(Vec3f(0.3, 0.9, 0.65), true, 1, 40);
	Material m3(COLOR_GREEN, false, 0.4, 175);
	Material m4(Vec3f(0.8, 0.8, 0), true, 0, 0);

	Scene scene;
	scene.getCamera().lookAt(Vec3f(5, 3.5, -10), Vec3f(0, 1, 1));

	scene.addShape(std::make_unique<Sphere>(m1, Vec3f(0, 0, 5), 1));
	scene.addShape(std::make_unique<Sphere>(m1, Vec3f(0, 0, -5), 1));
	scene.addShape(std::make_unique<Sphere>(m2, Vec3f(3.8, 2.3, 2), 1.7278));
	scene.addShape(std::make_unique<Sphere>(m3, Vec3f(1.2, -0.2, -3.6), 0.586));
	scene.addShape(std::make_unique<Plane>(m4, Vec3f(0, -1, 0), Vec3f(0, -1, 0)));

	scene.addLight(std::make_unique<DirLight>(COLOR_WHITE, 0.3, Vec3f(-1).norm()));
	scene.addLight(std::make_unique<PointLight>(COLOR_WHITE, 0.8, Vec3f(3.98, 3, -8), Vec3f(1, 0.001, 0.0087)));

	Image image(1920, 1080);
	scene.render(image, FOV, SAMPLES);

	image.writeToFile(Format::PPM, "out.ppm");
}
