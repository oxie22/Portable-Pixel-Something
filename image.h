#pragma once

#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
#include <fstream>
#include <algorithm>
struct Pixel{ 
    uint8_t r{0};
    uint8_t g{0};
    uint8_t b{0};

    Pixel() = default;
    Pixel(uint8_t red, uint8_t green, uint8_t blue);
    friend std::ostream& operator<<(std::ostream& os, const Pixel& obj);
};

inline Pixel pixelAdd(Pixel p1, Pixel p2){
    return Pixel{
        (uint8_t)std::min(255, p1.r + p2.r),
        (uint8_t)std::min(255, p1.g + p2.g),
        (uint8_t)std::min(255, p1.b + p2.b)
    };
}

inline Pixel pixelSub(Pixel p1, Pixel p2){
    return Pixel{
        (uint8_t)std::max(255, p1.r - p2.r),
        (uint8_t)std::max(255, p1.g - p2.g),
        (uint8_t)std::max(255, p1.b - p2.b)
    };
}

inline Pixel pixelLerp(Pixel pA, Pixel pB, float t){
    t = std::clamp(t, 0.0f, 1.0f);
    return Pixel{
        (uint8_t)(pA.r + (pB.r - pA.r) * t),
        (uint8_t)(pA.g + (pB.g - pA.g) * t),
        (uint8_t)(pA.b + (pB.b - pA.b) * t)
    };
}
    
struct Image{
    int width;
    int height;
    std::vector<Pixel> pixels;

    Image();
    Image(int w, int h, Pixel color = {0, 0, 0});

    bool load(const std::string& filepath);
    bool bake(std::string filepath);
    void putPixel(int x, int y, Pixel p);
};
