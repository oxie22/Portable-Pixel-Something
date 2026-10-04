#include <iostream>
#include "image.h"
#include "filter.h"
int main(){   
    // Image my_img("main.ppm");
    // Pixel p{20, 200, 22};
    // my_img.putPixel(0, 3, Pixel{69, 69, 69});
    // my_img.bake("main2.ppm");
    Image test("../images/todo.ppm");
    applyInvert(test);
    test.bake("../images/test.ppm");

}