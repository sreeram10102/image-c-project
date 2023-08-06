#include "image_edit.h"

#include <stdlib.h>
#include <string.h>

#include "structures.h"
#include "util.h"

void rotate_counterclockwise(image_t *img) {
   // NOT_IMPLEMENTED;
   // UNUSED(img);
   int width = img -> w;
    int height = img -> h;
    pixel_t*salsa = malloc(width * height * sizeof(pixel_t));
    for(int i =0 ; i< height; ++ i){
        for(int j =0 ; j < width ; ++j){
           salsa[(width-(j+1))*height +i]=img->img[i * width + j];
        }}
        free(img->img);
img->h=width;
img->w=height;
img->img=salsa;


}


void rotate_clockwise(image_t *img) {
   // NOT_IMPLEMENTED;
    //UNUSED(img);
    int width = img -> w;
    int height = img -> h;
    pixel_t*salz = malloc(width * height * sizeof(pixel_t));
    for(int i =0 ; i< height; ++ i){
        for(int j =0 ; j < width ; ++j){
             salz[height* j + (height -(i+1))]= img->img[i*width+j] ;
            
            

             

        }
    }
    
    free(img->img);
    img->w=height;
img->h=width;
img->img=salz;



}

void mirror_horizontal(image_t *img) {
   // NOT_IMPLEMENTED;
    //UNUSED(img);
     int width = img -> w;
    int height = img -> h;
    pixel_t*alex = malloc(width * height * sizeof(pixel_t));
    for(int i =0 ; i< height; ++ i){
        for(int j =0 ; j < width ; ++j){
             alex[i*width+j]=img->img[i* width + (width -(j+1))] ;
            
           
             

        }
        
    }
    
    free(img->img);
    img->w=width;
img->h=height;
img->img=alex;


}

void mirror_vertical(image_t *img) {
   // NOT_IMPLEMENTED;
    //UNUSED(img);
    rotate_counterclockwise(img);
    rotate_counterclockwise(img);
    mirror_horizontal(img);
    //if we rotate it counterclockwise we are in the same indexes where we should be which horizontal gives you the vertical version

             

             

        
    
    
    
}

void resize(image_t *img, int new_width, int new_height) {
    //NOT_IMPLEMENTED;
    //UNUSED(img);
    //UNUSED(new_width);
    //UNUSED(new_height);
    int width= img->w;
    int height= img->h;
    
   pixel_t * ayush =malloc( new_height * new_width * sizeof(pixel_t));

    if(width < new_width && height <new_height){
        for(int i = 0;i<new_height;++i){
            for(int j =0 ; j< new_width ; ++j){
                if(i < height && j < width){
              ayush[i * new_width + j]=  img->img[i * width + j];}
                else {
               memset(&ayush[i * new_width +j],0,sizeof(pixel_t));}
               //memset(&ayush[i * new_width +j].g,0,sizeof(pixel_t));  
                //memset(&ayush[i * new_width +j].b,0,sizeof(pixel_t));}
            }  

        }
    }

    else if (width == new_width && height == new_height) {
        for(int i = 0;i<new_height;++i){
            for(int j =0 ; j< new_width ; ++j){
              ayush[i* new_width +j] = img->img[i * width + j];
            }
        }
    
    }

    else if(width > new_width && height > new_height){
        for(int i = 0;i<new_height;++i){
            for(int j =0 ; j< new_width ; ++j){
                ayush[i * new_width + j]=  img->img[i * width + j];
                
                 
            }
              

        }
    }
    else if(width > new_width && height < new_height){
        for(int i = 0;i<new_height;++i){
            for(int j =0 ; j< new_width ; ++j){
                if(i < height && j <= new_width ){
                ayush[i * new_width + j]=  img->img[i * width + j];}
                else if(new_height > i&& i > height && j <= new_width ){
                 memset(&ayush[i * new_width +j],0,sizeof(pixel_t));
                }
            }
              

        }
    }
    else if(width < new_width && height > new_height){
        for(int i = 0;i<new_height;++i){
            for(int j =0 ; j< new_width ; ++j){
                if(i < new_height && j <= width ){
                ayush[i * new_width + j]=  img->img[i * width + j];}
                else if( i <= new_height && width< j&& j < new_width ){
                 memset(&ayush[i * new_width +j],0,sizeof(pixel_t));
               }} }


                 
            
              

        
    }
    else if(width == new_width && height < new_height){
        for(int i = 0;i<new_height;++i){
            for(int j =0 ; j< new_width ; ++j){
                if(i < height && j <= new_width ){
                ayush[i * new_width + j]=  img->img[i * width + j];}
                else if(new_height > i&& i > height && j <= new_width ){
                 memset(&ayush[i * new_width +j],0,sizeof(pixel_t));
                }
            }
              

        }
    }
    else if(width < new_width && height == new_height){
        for(int i = 0;i<new_height;++i){
            for(int j =0 ; j< new_width ; ++j){
                if(i < new_height && j <= width ){
                ayush[i * new_width + j]=  img->img[i * width + j];}
                else if( i <= new_height && width< j&& j < new_width ){
                 memset(&ayush[i * new_width +j],0,sizeof(pixel_t));
               } }}
    }         
    free(img->img);
    img->h=new_height;
img->w=new_width;
img->img=ayush;
}
