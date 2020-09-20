#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <cmath>
#include <cstddef>
#include <string>

#include "vec3.hpp"

enum class Format { PPM };

class Image final {
public:
    struct PixelRGB {
        unsigned char r, g, b;
        PixelRGB(unsigned char r, unsigned char g, unsigned char b) : r{r}, g{g}, b{b} {}

        PixelRGB() : r{0}, g{0}, b{0} {}
    };

    const std::size_t width, height;

private:
    PixelRGB* data;

public:
    Image(std::size_t width, std::size_t height);
    ~Image();

    void setPixel(std::size_t x, std::size_t y, const PixelRGB& pixel);
    PixelRGB& getPixel(std::size_t x, std::size_t y) const;

    void writeToFile(Format fmt, std::string path) const;
};

Image::PixelRGB float3ToRGB8(const Vec3f& c);

#endif /* end of include guard: IMAGE_HPP */
