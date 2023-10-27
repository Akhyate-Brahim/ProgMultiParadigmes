#include "image.h"

Image::Image(std::string imagePath) {
    std::ifstream img_stream(imagePath);
    img_stream >> format;
    std::string line;
    if (std::getline(img_stream,line) && (line[0]=='#')){
        img_stream >> comment;
    }
    img_stream >> nbColumns >> nbLines;
    img_stream >> maxDepth;
    Pixel p;
    while (img_stream >> p.R >> p.G >> p.B) {
        data.push_back(p);
    }
    img_stream.close();
}


void Image::makeGrey(){
    for (Pixel &p : data){
        p.makeItGrey();
    }
}

void Image::makeBlack_White(unsigned int threshold){
    for (Pixel &p : data){
        p.makeItBW(threshold);
    }
}
std::ostream &operator<<(std::ostream &os, const Image &image)
{
    os << image.format << std::endl;
    os << "# " << image.comment << std::endl;
    os << image.nbColumns << ' ' << image.nbLines << std::endl;
    os << image.maxDepth << std::endl;
    for (Pixel p : image.data){
        os << p;
    }
    return os;
}

