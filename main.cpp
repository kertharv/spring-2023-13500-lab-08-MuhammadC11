#include <iostream>
#include <string>
#include "imageio.h"
#include "funcs.h"
int main()
{
    std::string image = "inImage.pgm";
    invert(image);
    invertHalf(image);
    box(image);
    frame(image);
    scale(image);
    pixelate(image);
    return 0;
}