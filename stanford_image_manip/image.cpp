#include "image.h"

Image::Image(string filemane):PNG()
{

readFromFile(filemane);
}

void Image ::lighten(double amount){
    //parcourir tous mes pixles
    for(unsigned x=0;x<width();x++)
        for(unsigned y=0;y<height();y++){
            HSLAPixel &P=getPixel(x,y);
            //augumenter la luminence
            P.l+=amount;
            //ne pas depasser 1
            P.l=(P.l<1)? P.l :1;
            //ne pas depasser 0
            P.l=(P.l<0)? 0: P.l;

        }

}

void Image ::saturate(double amount){
    //parcourir tous mes pixles
        //parcourir tous mes pixles
        for(unsigned x=0;x<width();x++)
            for(unsigned y=0;y<height();y++){
                HSLAPixel &P=getPixel(x,y);
                //augumenter la luminence
                P.s+=amount;
                //ne pas depasser 1
                P.s=(P.s<1)? P.s :1;
                //ne pas depasser 0
                P.s=(P.s<0)? 0: P.s;



    }

}
void Image ::rotateColor(double angle){
    for(unsigned x=0;x<width();x++)
        for(unsigned y=0;y<height();y++){
            HSLAPixel &P=getPixel(x,y);
        P.h+=angle;
        //s'asurer que P.h<360
        while(P.h<360)
            P.h+=360;
        //s'asurer que P.h>360
        while(P.h>360)
            P.h-=360;

        }

}

