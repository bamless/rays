#ifndef SCENE_HPP
#define SCENE_HPP

#include <memory>
#include <vector>

#include "camera.hpp"
#include "image.hpp"
#include "light.hpp"
#include "shape.hpp"

const int MAX_DEPTH = 4;
const float AMBIENT = 0.0072;

class Scene final {
private:
    Camera cam;
    std::vector<std::unique_ptr<Shape>> shapes;
    std::vector<std::unique_ptr<Light>> lights;

public:
    void render(Image& img, int fov, int aaSamples);

    void addShape(std::unique_ptr<Shape>&& s);
    void addLight(std::unique_ptr<Light>&& l);

    const std::vector<std::unique_ptr<Shape>>& getShapes() const;
    const std::vector<std::unique_ptr<Light>>& getLights() const;
    Camera& getCamera();

private:
    struct Intersection {
        Shape* hObj;
        float dHit;
    };

    Vec3f trace(const Ray& r, int depth);
    bool intersect(Intersection& in, const Ray& r);
};

#endif /* end of include guard: SCENE_HPP */
