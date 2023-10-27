/**********************************************
* ppm Image manipualtion example              *  
*---------------------------------------------*
* Julien Deantoni --- No Copyright 2016       *
*     v0.2 2016/11/30                         *
**********************************************/
// modified Sylvain Lippi
// voir <<ppm>> pour le format d'image <<Portable Pixmap>>
// tests de la classe Image

#include "image.h"
#include <iostream>
#include <fstream>

int main() {

    Image mon_image("./billc.ppm"); // lecture dans un fichier
	Image mon_image_cpy = mon_image; // copie

	mon_image.makeGrey(); // transforme l'image en niveaux de gris : R=G=B=moyenne des couleurs

    std::ofstream mon_image2("./mon_image2.ppm"); // écriture dans un fichier
    mon_image2 << mon_image;


	mon_image_cpy.makeBlack_White(12); // transforme l'image en Noir en Blanc :
	// Si moyenne des couleurs < threshold => BLANC sinon NOIR

    std::ofstream mon_image3("mon_image3.ppm"); // écriture dans un fichieer
    mon_image3 << mon_image_cpy;

    return 0;
}

