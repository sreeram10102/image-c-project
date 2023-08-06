#include "flood_fill.h"

#include <stdbool.h>
#include <stdlib.h>

#include "structures.h"
#include "util.h"

#include <stdlib.h>
void helper(image_t *img, int x, int y, pixel_t *target_color,pixel_t*curr_pixel_cl){
  int width = img-> w;

if (x < 0 || y < 0 || x >= img->w || y >= img->h){
  return;
}
else if(
  img->img[y * width + x].r == curr_pixel_cl->r &&
   img->img[y * width + x].g == curr_pixel_cl->g &&
  img->img[y * width + x].b == curr_pixel_cl->b){
    flood(img,  x,  y, target_color);
}




     
      
}    

void flood(image_t *img, int x, int y, pixel_t *target_color) {
int width = img-> w;
int height = img-> h;

if (x < 0 || y < 0 || x >= width || y >= height){
        //free(start);
           return;
          }
 //int b , r , g;         
 
pixel_t *curr_pixel_cl= malloc(sizeof(pixel_t));
curr_pixel_cl[0]= img->img[y * width + x];


   

// if (img->img->r == target_color->r &&
//     img->img->g == target_color->g &&
//     img->img->b == target_color->b) {
//         return;
//           }     
// else{
    img->img[y * width + x]= *target_color;

    

        
           helper(img, x - 1, y, target_color,curr_pixel_cl);
        
        
        
         helper(img, x + 1, y, target_color,curr_pixel_cl);
         
          
          
         helper(img, x , y-1, target_color,curr_pixel_cl);
          
        
       
         helper(img, x , y+1, target_color,curr_pixel_cl);
         
 free(curr_pixel_cl) ;  
}
 
   



                  
   
 
  

  
    

    




 

   
