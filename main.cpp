#include <iostream>
#include <string>
#include "imageio.h"
#include "funcs.h"
int main()
{
    std::string img = "inImage.pgm";
    invert(img);
    invertHalf(img);
    box(img);
    frame(img);
}