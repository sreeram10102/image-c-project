#include "file_io.h"

#include <assert.h>
#include <stdlib.h>

#include "structures.h"
#include "util.h"
#include "string.h"

int image_read(image_t *img, FILE *fin) {
   // NOT_IMPLEMENTED;
   // UNUSED(img);
   // UNUSED(fin);
    int width;
    int height;
    int s1 ;
    char start[3] ;
   // fscanf(fin,"%2s",start);
    //if(strcmp("P3",start)!=0){
    //return -1;}
     
    fscanf(fin," %s %d %d %d",start,&width,&height,&s1 );
    if (width<1 || height < 1 || s1!=255){
     return -1;}

    if(strcmp("P3",start)!=0){
     return -1;}
    
    
    pixel_t* pixels = malloc(width * height * sizeof(pixel_t)) ;
    img->img = pixels;
    for(int i=0;i< width*height;++i){
        fscanf(fin,"%d %d %d",&pixels[i].r,&pixels[i].g,&pixels[i].b);
        if((pixels[i].r <0 || pixels[i].r >255 )&& (pixels[i].g <0 || pixels[i].g >255 )&& (pixels[i].b <0 ||pixels[i].b>255)){
        free(pixels);
        return -1;}
    }
    img->h = height;
    img->w= width;
    img->img= pixels;
    return 0;

}

void image_write(const image_t *img, FILE *fout) {
    //NOT_IMPLEMENTED;
    //UNUSED(img);
    //UNUSED(fout);
    fprintf(fout,"P3 %d %d 255\n",img->w,img->h);
     for(int g =0;g < img->w * img ->h;++g){
        fprintf(fout," %d %d %d ",img->img[g].r,img ->img[g].g,img->img[g].b);

     }
}

void image_free(image_t *img) {
    if (img->img != NULL) {
        free(img->img);
    }
    img->w = img->h = 0;
    img->img = NULL;
}
