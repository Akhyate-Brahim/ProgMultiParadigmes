/**********************************************
* Image manipulation header                   *  
*---------------------------------------------*
* Julien Deantoni --- No Copyright 2016       *
*     v0.2 2016/11/30                         *
**********************************************/

#pragma once
#ifndef _IMAGE_H
#define _IMAGE_H

#include <vector>
#include <string>
#include <fstream>
#include "pixel.h"

class Image {
 
private:
    std::vector<Pixel> data;

    std::string format;
    std::string comment;
    int nbColumns =0;
    int nbLines =0;
    int maxDepth =0;

public:
    Image(std::string imagePath);
    void makeGrey();
    void makeBlack_White(unsigned int threshold);

    friend std::ostream& operator<<(std::ostream& os, const Image& image);
};

#endif