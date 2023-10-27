#include "pixel.h"

void Pixel::makeItGrey() {
    unsigned int moyenne = (R / 3) + (G / 3) + (B / 3);
    R = moyenne;
    G = moyenne;
    B = moyenne;
}


std::ostream &operator<<(std::ostream &os, const Pixel &pix)
{
    os << pix.R << ' ' << pix.G << ' ' << pix.B << ' ';
    return os;
}
void Pixel::makeItBW(unsigned int threshold){
    unsigned int moyenne = (R / 3) + (G / 3) + (B / 3);
    if (moyenne < threshold){
        R=0;
        G=0;
        B=0;
    } else {
        R=255;
        G=255;
        B=255; 
    }
}
