#ifndef RGBPIXELXY_HPP
#define RGBPIXELXY_HPP

#include <stdlib.h>
#include <math.h>
#include <iostream>


class RGBPixelXY
{
    unsigned int coordX=0;  // from 0 to N
    unsigned int coordY=0;  // from 0 to N
    
    unsigned char colorR=0; // 0-255 (0x00 - 0xff)
    unsigned char colorG=0; // 0-255 (0x00 - 0xff)
    unsigned char colorB=0; // 0-255 (0x00 - 0xff)
    int sumRGB=0;         //Sum of the R + G + B attributes of the pixel
    int originFile=0;     //Attribute for identifying to what image the pixel belongs to
    
 
public:
    RGBPixelXY();
    RGBPixelXY(unsigned int paramX, unsigned int paramY, int poriginFile);
    RGBPixelXY(unsigned int paramX, unsigned int paramY, unsigned char paramR, unsigned char paramG, unsigned char paramB);    
    ~RGBPixelXY();

    unsigned int getX();
    unsigned int getY();
    unsigned char getR();
    unsigned char getG();
    unsigned char getB();
    int getSumRGB();      //Returns the sumRGB value
    
    int getOriginFile();             //Returns the originFile value
    void setOriginFile(int ofile);   //Sets the originFile value
    
    void setComponents(unsigned char paramR, unsigned char paramG, unsigned char paramB);
    
    void normalizeToRedGreenOrBlue();
    bool isBlack();
    bool isNotBlack();
    unsigned int getDistACentro(unsigned int width, unsigned int height);
    bool getFromRaw(const unsigned char *image, unsigned int width, unsigned int height, unsigned int p_x, unsigned int p_y);
    bool setIntoRaw(unsigned char *image, unsigned int width, unsigned int height, unsigned int p_x, unsigned int p_y);

};

#endif // RGBPIXELXY_HPP
