#include <iostream>
#include <string>
#include "imageio.h"

void invert(std::string input)
{

    int img[MAX_H][MAX_W];
    int height, width;
    readImage(input, img, height, width); // read it from the file "inImage.pgm"
    // h and w were passed by reference and
    // now contain the dimensions of the picture
    // and the 2-dimesional array img contains the image data

    // Now we can manipulate the image the way we like
    // for example we copy its contents into a new array
    int out[MAX_H][MAX_W];

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            out[row][col] = 255 - img[row][col];
        }
    }

    // and save this new image to file "outImage.pgm"
    writeImage("taskA.pgm", out, height, width);
}

void invertHalf(std::string input)
{
    int img[MAX_H][MAX_W];
    int height, width;
    readImage(input, img, height, width); // read it from the file "inImage.pgm"
    // h and w were passed by reference and
    // now contain the dimensions of the picture
    // and the 2-dimesional array img contains the image data

    // Now we can manipulate the image the way we like
    // for example we copy its contents into a new array
    int out[MAX_H][MAX_W];

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            if (col < width / 2)
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
    writeImage("taskB.pgm", out, height, width);
}

void box(std::string input)
{
    // draws a white box exactly in the middle of the picture. The dimensions of the box should be 50% by 50% of the original picture’s width and height.

    int img[MAX_H][MAX_W];
    int height, width;
    readImage(input, img, height, width); // read it from the file "inImage.pgm"

    int out[MAX_H][MAX_W];

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            if (row > height / 4 && row < height / 4 * 3 && col > width / 4 && col < width / 4 * 3)
            {
                out[row][col] = 255;
            }
            else
            {
                out[row][col] = img[row][col];
            }
        }
    }

    writeImage("taskC.pgm", out, height, width);
}

void frame(std::string input)
{
    // draws a white box exactly in the middle of the picture. The dimensions of the box should be 50% by 50% of the original picture’s width and height.

    int img[MAX_H][MAX_W];
    int height, width;
    readImage(input, img, height, width); // read it from the file "inImage.pgm"

    int out[MAX_H][MAX_W];

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            if ((((row == height / 4 || row == (height - height / 4)) && (col > width / 4 && col < (width - width / 4)))) || ((col == width / 4 || col == (width - width / 4)) && (row > height / 4 && row < (height - height / 4))))
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
    writeImage("taskD.pgm", out, height, width);
}

void scale(std::string input)
{
    // scales the image by a factor of 2. The new image should be twice as wide and twice as high as the original image. The new image should be filled with the original image, but each pixel in the new image should be replaced by a 2x2 square of pixels in the original image. The new image should be saved to a file called “outImage.pgm”.

    int img[MAX_H][MAX_W];
    int height, width;
    readImage(input, img, height, width); // read it from the file "inImage.pgm"

    int out[MAX_H][MAX_W];

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            out[row * 2][col * 2] = img[row][col];
            out[row * 2 + 1][col * 2] = img[row][col];
            out[row * 2][col * 2 + 1] = img[row][col];
            out[row * 2 + 1][col * 2 + 1] = img[row][col];
        }
    }

    writeImage("taskE.pgm", out, height * 2, width * 2);
}

void pixelate(std::string input)
{
    // pixelates the image by a factor of 2. The new image should be half as wide and half as high as the original image. The new image should be filled with the original image, but each pixel in the new image should be replaced by the average of the 4 pixels in the original image that it covers. The new image should be saved to a file called “outImage.pgm”.

    int img[MAX_H][MAX_W];
    int height, width;
    readImage(input, img, height, width); // read it from the file "inImage.pgm"

    int out[MAX_H][MAX_W];
    int average = 0;

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            average = (img[row][col] + img[row][col + 1] + img[row + 1][col] + img[row + 1][col + 1]) / 4;
            out[row][col] = average;
            out[row + 1][col] = average;
            out[row][col + 1] = average;
            out[row + 1][col + 1] = average;
        }
    }

    writeImage("taskF.pgm", out, height, width);
}