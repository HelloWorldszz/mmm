#ifndef GRAYSCALE_H
#define GRAYSCALE_H
#include "image.h"

class Grayscale:public Image
{

public:
    //constructeur par defaut
    using Image::Image;
    Grayscale(string);
    void Gs();

};

#endif // GRAYSCALE_H
