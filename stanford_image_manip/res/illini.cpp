#include "illini.h"


//Illini::Illini()
//{

//}


Illini::Illini(string filemane):Image(){
    readFromFile(filemane);



}
void Illini ::ill(){
    //parcourir tous mes pixles
        //parcourir tous mes pixles
    for(unsigned x=0;x<width();x++)
        for(unsigned y=0;y<height();y++){
            HSLAPixel &P=getPixel(x,y);

            if(P.h>=11 && P.h<216){
                P.h=11;
            }else{
                P.h=216;
            }




}

}


