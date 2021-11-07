#include "illini.h"

Illini::Illini(string filemane, int c1, int c2):Image(filemane){
    readFromFile(filemane);
   for(unsigned x=0;x<width();x++)
       for(unsigned y=0;y<height();y++){
           HSLAPixel &P=getPixel(x,y);


           if(P.h<=c2&&P.h>=c1){
                           if((c2-P.h)<(P.h-c1)){
                               P.h=c2;
                           }else{
                               P.h=c1;

                           }

}


}


}

