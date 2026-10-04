#include <iostream>
#include "image.h"
#include "filter.h"
int main(){   
    Image myImage(100, 100, Pixel{255,0,0});
    //width height color image;
    Image demo("sampleImage.ppm")
    //filename of the image you want to be used

    applyInvert(demo);
    //invert filter applied

    demo.bake("destinationfilename.ppm");
}
