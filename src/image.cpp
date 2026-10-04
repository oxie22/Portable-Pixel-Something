#include "image.h"

#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
#include <fstream>


Pixel::Pixel(uint8_t red, uint8_t green, uint8_t blue): r(red), g(green), b(blue) {}

std::ostream& operator<< (std::ostream& os, const Pixel& obj){   
    os << (int)obj.r << ' ' << (int)obj.g << ' ' << (int)obj.b << ' ';
    return os;
}
Image::Image(int w, int h, Pixel color): width(w), height(h), pixels(w*h, color) {}

Image::Image(const char* cstr_filepath){
    std::ifstream imgFile(cstr_filepath, std::ios::binary);
    if(!imgFile.is_open()) return;

    std::string dummy;
    imgFile >> dummy >> width >> height >> dummy;
    
    imgFile.get();
    
    pixels.resize(width * height);
    
    imgFile.read(reinterpret_cast<char*>(pixels.data()), width * height * 3);
}
    
void Image::bake(std::string filepath){
    std::ofstream imgFile(filepath);
    int count = 0;
    imgFile << "P3\n" << width << " " << height << "\n255\n";
    for(const Pixel& p : pixels){
        imgFile << p;
        count++;
        if(count % width == 0)
            imgFile << '\n';
        else
            imgFile << '\t';
    }
}

void Image::putPixel(int x, int y, Pixel color){
    pixels[y * width + x] = color;
}

