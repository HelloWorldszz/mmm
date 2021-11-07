#include "grayscale.h"

Grayscale::Grayscale(string filemane):Image()
{

readFromFile(filemane);
}

void Grayscale ::Gs(){
    //parcourir tous mes pixles
        //parcourir tous mes pixles
        for(unsigned x=0;x<width();x++)
            for(unsigned y=0;y<height();y++){
                HSLAPixel &P=getPixel(x,y);
                P.s=0;



    }

}
