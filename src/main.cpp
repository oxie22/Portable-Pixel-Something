#include <iostream>
#include "image.h"
#include "filter.h"
int main(){   
    Image myImage(100, 100, Pixel{255,0,0});
    //width height color image;
    Image demo;
    demo.load("sampleImage.ppm")
    //filename of the image you want to be used

    applyInvert(demo);
    //invert filter applied
    demo.putPixel(10, 200, Pixel{255,0,0});
    
    demo.bake("destination/filename.ppm");
}
