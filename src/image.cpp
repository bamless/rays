#include "image.hpp"

#include <algorithm>
#include <fstream>

const float GAMMA = 2.4;

Image::Image(std::size_t width, std::size_t height) : width{width}, height{height} {
    data = new Image::PixelRGB[width * height];
}

Image::~Image() {
    delete[] data;
}

void Image::setPixel(std::size_t x, std::size_t y, const Image::PixelRGB& pixel) {
    if(x > width - 1 || y > height - 1) {
        throw std::out_of_range("index out of range");
    }
    data[x + y * width] = pixel;
}

Image::PixelRGB& Image::getPixel(std::size_t x, std::size_t y) const {
    if(x > width - 1 || y > height - 1) {
        throw std::out_of_range("index out of range");
    }
    return data[x + y * width];
}

void Image::writeToFile(Format fmt, std::string path) const {
    (void)fmt;  // for now only ppm format is supported;
    std::ofstream file(path, std::ios::binary);
    file << "P6\n" << width << " " << height << "\n255\n";
    file.write((char*)data, sizeof(PixelRGB) * width * height);
    file.close();
}

#define clamp(v) (std::min(1.f, std::max(0.f, v)))

static float gammaEncode(float c) {
    if(c < 0.0031308) return 12.92 * c;
    return 1.055 * powf(c, 1 / GAMMA) - 0.055;
}

Image::PixelRGB float3ToRGB8(const Vec3f& c) {
    Vec3f clamped(clamp(c.x), clamp(c.y), clamp(c.z));
    return Image::PixelRGB(gammaEncode(clamped.x) * 255, gammaEncode(clamped.y) * 255,
                           gammaEncode(clamped.z) * 255);
}
