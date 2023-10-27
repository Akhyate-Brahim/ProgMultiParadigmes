/**********************************************
* Pixel header                                *  
*---------------------------------------------*
* Julien Deantoni --- No Copyright 2016       *
*     v0.2 2016/11/30                         *
**********************************************/
#pragma once

#ifndef _PIXEL_H
#define _PIXEL_H


#include <iostream>
class Pixel{
public:
    unsigned short int R =0;	// Red
    unsigned short int G =0;	// Green
    unsigned short int B =0;	// Blue

    void makeItGrey() ;
    void makeItBW(unsigned int threshold);
    friend std::ostream& operator<<(std::ostream& os, const Pixel& pix);
};
#endif