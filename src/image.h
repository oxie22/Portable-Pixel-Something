#pragma once

#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
#include <fstream>

struct Pixel{ 
    uint8_t r{0};
    uint8_t g{0};
    uint8_t b{0};

    Pixel() = default;
    Pixel(uint8_t red, uint8_t green, uint8_t blue);
    friend std::ostream& operator<<(std::ostream& os, const Pixel& obj);


};

struct Image{
    int width;
    int height;
    std::vector<Pixel> pixels;

    Image(int w, int h, Pixel color = {0, 0, 0});
    Image(const char* cstr_filepath);

    void bake(std::string filepath);
    void putPixel(int x, int y, Pixel color);
};
