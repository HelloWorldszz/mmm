#ifndef ILLINI_H
#define ILLINI_H
#include"image.h"


class Illini:public Image
{

public:
    using Image::Image;
    Illini();
    int color1;
    int color2;

    Illini(string filemane,int color1=11,int color2=216);
    Illini(string);
};

#endif // ILLINI_H

