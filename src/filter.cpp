#include "filter.h"

void applyInvert(Image& img){
    for(Pixel& p : img.pixels){
        p.r = 255 - p.r;
        p.g = 255 - p.g;
        p.b = 255 - p.b;
    }
}