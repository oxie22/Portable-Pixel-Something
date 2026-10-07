# PortablePixelSomething
## A lightweight c++ image and animation rendering library from scratch.
<img width="462" height="49" alt="ppsomething" src="images/ppsomething-export.png" />

This project handles raw pixel buffers and uses the [Netpbm](https://en.wikipedia.org/wiki/Netpbm) Portable Pixel Map format to modify images,
and uses FFmpeg to convert them back to png or the frames exported into mp4.

Made for fun and learning, this is my first project in this much depth ＼(ﾟｰﾟ＼)
## Dependencies
- C++ compiler(supports c++ 20)
- FFmpeg
- Cmake (building the proj)

# Documentation
### Pixel
*image.h*
A pixel is a struct with three uint8_t values, r g b which can go from 0 to 255.

    Pixel myPixel{255,200,20};

#### Pixel  pixelAdd(Pixel  p1, Pixel  p2)
Returns addition of p1 and p2

    Pixel p3 = pixelAdd(Pixel{100,0,0}, Pixel{155,0,0});
    //p3 = Pixel{255,0,0);

#### Pixel  pixelSub(Pixel  p1, Pixel  p2)
Returns subtraction of p2 from p1

    Pixel p3 = pixelSub(Pixel{255,0,0}, Pixel{155,0,0});
    //p3 = Pixel{100,0,0};
    
#### pixelLerp(Pixel p1, Pixel p2, float t)
Linear interpolation from p1 to p2 at t

    Pixel myPixel = pixelLerp(Pixel{255,0,0}, Pixel{0,0,255}, 0.5);
    //interpolates from p1(red) to p2(blue) at 0.5 so its inbetween values 
### Image
*image.h*
    Image(int pixel_width, int pixel_height, Pixel color);
An image is  a vector of pixels.

An example showing how to load a ppm file into a image i.e. make it store the values

    Image myImage;
    std::string filepath = "images/img.ppm";
    myImage.load(&filepath);
   
Image functions:
#### load(std::string& filepath)
Loads a ppm file into the Image

    myImg.load("images/myImg.ppm");

#### bake(std::string& filepath)
Bakes an image, i.e creates a .ppm file in storage with the data of the image struct

    myImg("images/myImg2.ppm");

#### putPixel(int w, int h, Pixel ColorVal)
Sets a pixel of color values of p at x, y in the Image.

    myImg.putPixel(2,3,Pixel{255,0,0});


### Filters
*"filters.h"*
#### applyInvert(Image& myImg)
Applies an invert filter on the image given

    applyInvert(myImg);
