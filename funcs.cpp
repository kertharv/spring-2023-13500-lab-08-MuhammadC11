#include <iostream>
#include <string>
#include "imageio.h"

void invert(std::string input)
{

    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w); // read it from the file "inImage.pgm"
    // h and w were passed by reference and
    // now contain the dimensions of the picture
    // and the 2-dimesional array img contains the image data

    // Now we can manipulate the image the way we like
    // for example we copy its contents into a new array
    int out[MAX_H][MAX_W];

    for (int row = 0; row < h; row++)
    {
        for (int col = 0; col < w; col++)
        {
            out[row][col] = 255 - img[row][col];
        }
    }

    // and save this new image to file "outImage.pgm"
    writeImage("taskA.pgm", out, h, w);
}

void invertHalf(std::string input)
{
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w); // read it from the file "inImage.pgm"
    // h and w were passed by reference and
    // now contain the dimensions of the picture
    // and the 2-dimesional array img contains the image data

    // Now we can manipulate the image the way we like
    // for example we copy its contents into a new array
    int out[MAX_H][MAX_W];

    for (int row = 0; row < h; row++)
    {
        for (int col = 0; col < w; col++)
        {
            if (col < w / 2)
            {
                out[row][col] = img[row][col];
            }
            else
            {
                out[row][col] = 255 - img[row][col];
            }
        }
    }

    // and save this new image to file "outImage.pgm"
    writeImage("taskB.pgm", out, h, w);
}

void box(std::string input)
{
    // draws a white box exactly in the middle of the picture. The dimensions of the box should be 50% by 50% of the original picture’s width and height.

    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w); // read it from the file "inImage.pgm"

    int out[MAX_H][MAX_W];

    for (int row = 0; row < h; row++)
    {
        for (int col = 0; col < w; col++)
        {
            if (row > h / 4 && row < h / 4 * 3 && col > w / 4 && col < w / 4 * 3)
            {
                out[row][col] = 255;
            }
            else
            {
                out[row][col] = img[row][col];
            }
        }
    }

    writeImage("taskC.pgm", out, h, w);
}

void frame(std::string input)
{
    // draws a white box exactly in the middle of the picture. The dimensions of the box should be 50% by 50% of the original picture’s width and height.

    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w); // read it from the file "inImage.pgm"

    int out[MAX_H][MAX_W];

    for (int row = 0; row < h; row++)
    {
        for (int col = 0; col < w; col++)
        {
            if ((((row == h / 4 || row == (h - h / 4)) && (col > w / 4 && col < (w - w / 4)))) || ((col == w / 4 || col == (w - w / 4)) && (row > h / 4 && row < (h - h / 4))))
            // if the
            {
                out[row][col] = 255;
            }
            else
            {
                out[row][col] = img[row][col];
            }
        }
    }
    writeImage("taskD.pgm", out, h, w);
}