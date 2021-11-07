---
Projet 1 : HSLA Images
---
**Réalisé par : _Adil Erraad,Said El
Ouardi_**

[Link to another page](./another-page.html).

# HSLA Images

## Introduction

Dans le cadre de notre projet nous nous sommes intéressés à la
manipulation IMAGES HSLA (HSLA :(Hue, saturation, luminance)).
A titre d’exemple le niveau de gris et illini de l’image …etc.

## HSL
>HSL is short for Hue, Saturation and Luminance.
>The HSL color space defines colors more naturally: Hue specifies the base color, the other two values then let you specify the saturation of that color and how bright the color should be.

## Experiment Image

  <p align="center"> <img  src="https://user-images.githubusercontent.com/86808736/138588539-da77dac1-6615-401d-9b98-ab5a781d9fdd.png"> <br></p>
  
## HSLP
  ```cpp
  //image header

class Image:public PNG
{
public:
    using PNG::PNG;
    Image(string);
    void saturate(double amount=0.1);
    void lighten(double amount=0.1);
    void rotateColor(double angle);


};

#endif // IMAGE_H

```


### Hue  [0°-360°] 

As you can see in the image, hue specifies the color. Hue is normally specified as either degrees ranging from 0° to 360° or as numbers from 0 to 6, in the image at the left side both starting at the 3 o'clock position and measured anti-clockwise.

<p align="center">There are 6 base colors:</p>

| Hue           | Degree°        |        Color |
| ------------- | ------------- | -------------|
| 0  | 0°  | red|
| 1  | 60°  |yellow |
| 2  |120° |green |
| 3 | 180°  |cyan |           
| 4  | 240°  |blue |
| 5  | 300°  |magneta |
| 6  | 360° |red |

<p align="center">*Example [Hue=90°]</p>


 <p align="center"> <img  src="https://user-images.githubusercontent.com/86808736/138588617-329d0454-199b-48a2-9303-209264bbabee.png"> <br></p>
 
 ```cpp
// Cpp Code for change the hue by angle=90°:
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

```


### Saturartion  [0%-100%]

After specifying the color using the hue value you can specify the saturation of your color. In the HSL color wheel the saturation specifies the distance from the middle of the wheel. So a saturation value of 0 (0%) means "center of the wheel", i.e. a grey value, whereas a saturation value of 1 (100%) means "at the border of the wheel", where the color is fully saturated.

<p align="center"> <img  src="https://user-images.githubusercontent.com/86808736/138590339-4381fad6-fac4-484b-9e31-a12b275f805a.jpg"> <br></p>

<p align="center">*Example [Saturation=40%]</p>

 <p align="center"> <img  src="https://user-images.githubusercontent.com/86808736/138589265-536bc89c-4e5f-4558-9537-96907804f6af.png"> <br></p>
 
 ```cpp
// Cpp Code for change the saturartion by amount=40%°:
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
```

### Luminance  [0%-100%]

The third parameter in the HSL color space is the luminance. This lets you specify how "bright" the color should be. 0% means, the brightness is 0, and the color is black. 100% means maximum brightness, and the color is white.
If you slowly increase the luminance, you will see the color changing from black at 0% and then through a darker version of your color, to your color in its full brightness at 50%, and then getting brighter until finally it reaches white at 100%.

The following six luminance sliders show you what happens with colors if you change the luminance:

  <p align="center"> <img  src="https://user-images.githubusercontent.com/86808736/138558157-63b1da2c-40ee-4f0c-8c88-0725a4559812.png"> <br></p>
  

<p align="center">*Example [Luminance=40%]</p>

 <p align="center"> <img  src="https://user-images.githubusercontent.com/86808736/138589284-dcce46a4-3388-423f-b378-0fd6eac92a10.png"> <br></p>

 ```cpp
// Cpp Code for change the luminance by amount=40%°:
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
```

### GrayScale

in digital photography, computer-generated imagery, and colorimetry, a grayscale image is one in which the value of each pixel is a single sample representing only an amount of light; that is, it carries only intensity information. Grayscale images, a kind of black-and-white or gray monochrome, are composed exclusively of shades of gray. The contrast ranges from black at the weakest intensity to white at the strongest.
So Graycale is Effect of reducing the saturation of each pixel.


<p align="center">*Example</p>

 <p align="center"> <img  src="https://user-images.githubusercontent.com/86808736/138589399-24d4849e-0028-4110-986c-25db17b17e26.png"> <br></p>

 ```cpp
// Cpp Code for change the saturation to 0 to get Grayscale image:
void Grayscale ::Gs(){
    //parcourir tous mes pixles
        //parcourir tous mes pixles
        for(unsigned x=0;x<width();x++)
            for(unsigned y=0;y<height();y++){
                HSLAPixel &P=getPixel(x,y);
                P.s=0;
    }
}
//header
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
```
### Illiny
It is an effect located on the image that converts each color between blue = 11 and orange = 216 to the closest color between them.

<p align="center">*Example</p>

 <p align="center"> <img  src="https://user-images.githubusercontent.com/86808736/138589518-4a3c9e5c-fc4f-4a09-9e38-8ce14b953051.png"> <br></p>

 ```cpp
// Cpp Code for illini:

Illini::Illini(string filemane, int c1, int c2):Image(filemane){
    readFromFile(filemane);
   for(unsigned x=0;x<width();x++)
       for(unsigned y=0;y<height();y++){
       
       // TODO: This implementation does not take a consideration of the 
       // of **cirtulcar** aspect of the hue color
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
//header

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

```

### Spotlight

A function that focuses light on a specific point of the image based on coordinates by raising the degree of illumination and partial opacity for the rest of the parts.

<p align="center">*Example Spotlight[500,200]</p>

 <p align="center"> <img  src="https://user-images.githubusercontent.com/86808736/138618110-897f7d8e-29ae-4a34-9cf7-996e34dbc7af.png"> <br></p> 
 <p align="center">*change SpotPoint[900,300]</p>
 <p align="center"> <img  src="https://user-images.githubusercontent.com/86808736/138618127-8d695337-9ea2-4c04-9803-e24382ea8654.png"> <br></p> 



```cpp
// Cpp Code for Spotlight :

Spotlight::Spotlight(string filemane,int X,int Y):Image(filemane),x(X),y(Y)
{
    for(unsigned x = 0; x < width()  ; x++){
       for(unsigned y = 0; y < height(); y++)
       {
          //reference on the pixel
          HSLAPixel &P = getPixel(x, y);
               double distance=sqrt((x-X)*(x-X)+(y-Y)*(y-Y));
               double dec = 1-distance*0.5/100 ;
               if (distance>160) {
                   dec=0.2;
               }
               P.l = dec*P.l;
             }
}
}

//ChangeSpotPoint by [900,300]
void Spotlight::changeSpotPoint(int centerX, int centerY){


    for(unsigned X = 0; X < width()  ; X++){
       for(unsigned Y = 0; Y < height(); Y++)
       {
          //reference on the pixel
          HSLAPixel &P = getPixel(X, Y);

               double distance1=sqrt((x-X)*(x-X)+(y-Y)*(y-Y));
               double distance=sqrt((X-centerX)*(X-centerX)+(Y-centerY)*(Y-centerY));
               double dec = 1-distance*0.5/100 ;
               double inc = 1-distance1*0.5/100 ;
               if (distance1>160) {
                   inc=0.2;
                }
                P.l =P.l/inc;
               if (distance>160) {
                   dec=0.2;
               }
               P.l = dec*P.l;
               }
               }
               }
//header

class Spotlight:public Image
{
public:
    int x,y;
    Spotlight(string filemane,int x,int y);
    void changeSpotPoint(int x, int y);
};

#endif // SPOTLIGHT_H

Todo : Also finish the Spotlight class
