#include "image.h"

#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
#include <fstream>
#include <filesystem>
#include <cstdlib>

namespace fs = std::filesystem;

Pixel::Pixel(uint8_t red, uint8_t green, uint8_t blue): r(red), g(green), b(blue) {}

std::ostream& operator<< (std::ostream& os, const Pixel& obj){   
    os << (int)obj.r << ' ' << (int)obj.g << ' ' << (int)obj.b << ' ';
    return os;
}

Image::Image(): width(0), height(0) {}
Image::Image(int w, int h, Pixel color): width(w), height(h), pixels(w*h, color) {}

bool Image::load(const std::string& filepath){
    std::ifstream imgFile(filepath, std::ios::binary);
    if(!imgFile.is_open()){
        std::cerr << "Error [load]: Failed to open file at filepath" << filepath << "\n";
        return false;
    }
    std::string dummy;
    imgFile >> dummy >> width >> height >> dummy;
    
    imgFile.get();
    
    pixels.resize(width * height);
    
    imgFile.read(reinterpret_cast<char*>(pixels.data()), width * height * 3);
    return true;
}

bool Image::bake(const std::string& filepath){
    std::ofstream imgFile(filepath, std::ios::binary);

    if(!imgFile){
        std::cerr << "Error [bake]: Couldn't create file at filepath" << filepath << "\n";
        return false;
    }
    int count = 0;
    imgFile << "P6\n" << width << " " << height << "\n255\n";
    imgFile.write(reinterpret_cast<char*>(pixels.data()), width * height * 3);
    if(imgFile.fail()){
        std::cerr << "Error [bake]: Something went wrong while saving file to " << filepath << "\n";
        return false;
    }
    else
        return true;
}

void Image::putPixel(int x, int y, Pixel color){
    pixels[y * width + x] = color;
}

