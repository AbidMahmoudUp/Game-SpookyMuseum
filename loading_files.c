/**
* @file loading_files.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "enigme.h"
/**
* @brief choose the number of the file 
* @param int *fich_numero used to save the number of the file
* @param char fichier has the link of the file 
* @return nothing
*/
void choose_file_randomly(int *fich_numero,char fichier[])
{
srand(time(NULL));
*fich_numero=1+rand() %7 ;
printf("%d \n",*fich_numero);
sprintf(fichier,"file/%d.txt",*fich_numero);
}




/**
* @brief loading the animation of the clock
* @param image load[] is an images list used to load the images in it 
* @return nothing
*/
void loading_temps(image load[])
{
char file[30];
int i;
for (i=1 ;i<=65; i++)
{
 sprintf(file,"temps/%d.png",i);
load[i].img = IMG_Load(file);
load[i].pos.x=510;
load[i].pos.y=145;	 			
}
}




/**
* @brief loading the background
* @param image load used to load the image 
* @return load
*/
image loading_background(image load)
{
load.img = IMG_Load("images/back.png");
load.pos.x=0;
load.pos.y=0;
return load;
}

/**
* @brief loading the winning image
* @param image load used to load the image 
* @return load
*/
image loading_vict(image load)
{
load.img = IMG_Load("images/vict.png");
load.pos.x=0;
load.pos.y=0;

return load;
}


/**
* @brief loading the lose image
* @param image load used to load the image 
* @return load
*/
image loading_def(image load)
{
load.img = IMG_Load("images/def.png");
load.pos.x=0;
load.pos.y=0;

return load;
}

/**
* @brief loading all of the lose,the winning, and the background image
* @param image *background used to load the background image 
* @param image image *vict to load the winning image
* @param image image *def used to load the lose image
* @return nothing
*/
void loading_all(image *background,image *vict,image *def)
{
*background=loading_background(*background);
*vict=loading_vict(*vict);
*def=loading_def(*def);
}


/**
* @brief display the image
* @param image p the image  to display in the screen 
* @param SDL_Surface *ecran  the surface where we're going to blit the image on it   
* @return nothing
*/
void afficher_image(image p,SDL_Surface *ecran)
{
SDL_BlitSurface(p.img, NULL, ecran,&p.pos);
}



/**
* @brief loading all of the enigme images
* @param *im used to load the image not selected  
* @param image *imo to load the selected image
* @param char file[] has the link of the not selected image
* @param char fich[] has the link of the selected image
* @param char c contains the number of the image to bring 
* @return nothing
*/
void init_images_enigme(image *im,image *imo,char file[],char fich[],char c)
{
switch(c)
       {
       case '1':
        im->img = IMG_Load(file);
        im->pos.x=10;
        im->pos.y=10; 
        break;
       case '2':
        //inititialisation image 2 de l'enigme
        im->img = IMG_Load(file);
        im->pos.x=20;
        im->pos.y=200;
        //inititialisation image 2 selectionner de l'enigme
        imo->img = IMG_Load(fich);
        imo->pos.x=20;
        imo->pos.y=200;
        break;
       case '3':
        //inititialisation image 3 de l'enigme
        im->img = IMG_Load(file);
        im->pos.x=20;
        im->pos.y=300;
        //inititialisation image 3 selectionner de l'enigme
        imo->img = IMG_Load(fich);
        imo->pos.x=20;
        imo->pos.y=300;
        break;
       case '4':
        //inititialisation image 4 de l'enigme
        im->img = IMG_Load(file);
        im->pos.x=20;
        im->pos.y=400;
        //inititialisation image 4 selectionner de l'enigme
        imo->img = IMG_Load(fich);
        imo->pos.x=20;
        imo->pos.y=400;
        break;
      }
}








/**
* @brief loading all of the enigme images 
* @param int num_fichier contains the number of the file
* @param char file has the link of the file 
* @return enigme
*/
enigme loading_enigme(char file[],int num_fichier)
  { 
    enigme e;
    char caractere_actuel,fich[30] ;
    int char_num=0;
    FILE* f=fopen(file,"r") ;

       while((caractere_actuel=fgetc(f))!=EOF)
      {
       char_num++ ;
       sprintf(file,"question/%d/%c.png",num_fichier,caractere_actuel);
       sprintf(fich,"question/%d/%co.png",num_fichier,caractere_actuel);
      if(char_num!=5)
      {
       switch(caractere_actuel)
       {
       case '1':
       init_images_enigme(&e.photo1,NULL,file,fich,caractere_actuel);
        break;
       case '2':
        init_images_enigme(&e.photo2,&e.photo2o,file,fich,caractere_actuel);
        break;
       case '3':
      init_images_enigme(&e.photo3,&e.photo3o,file,fich,caractere_actuel);      
        break;
       case '4':
       init_images_enigme(&e.photo4,&e.photo4o,file,fich,caractere_actuel);
        break;
 
      
       }
      }
     else
       {
       switch(caractere_actuel)
       {
       case '2':
        e.resultat=2 ;
        break;
       case '3':
        e.resultat=3 ;
        break;
       case '4':
        e.resultat=4 ;
        break;


       }
       }
      }
     fclose(f);
  return e;
  }

/**
* @brief display all of the enigme images
* @param enigme e the enigme that has the images to display in the screen 
* @param SDL_Surface *ecran  the surface where we're going to blit the image on it   
* @return nothing
*/
void afficher_enigme(enigme e,SDL_Surface *ecran)
{
afficher_image(e.photo1,ecran);
afficher_image(e.photo2,ecran);
afficher_image(e.photo3,ecran);
afficher_image(e.photo4,ecran);
}






/**
* @brief display the image
* @param image load[] is an images list used to display all the images in it  
* @param SDL_Surface *ecran  the surface where we're going to blit the image on it   
* @param int i is the number of the image to display 
* @return nothing
*/
void animer(image clock[],int i,SDL_Surface *ecran)
{
 afficher_image(clock[i],ecran);
} 









/**
* @brief give the result if its true or false 
* @param enigme e the enigme that has the images to display in the screen 
* @param image vict contains the winning image 
* @param image def contains the lose image  
* @param SDL_Surface *ecran  the surface where we're going to blit the image on it   
* @param int defo is the integer which is ging to contains the number 1 if the result is false   
* @param int vecto is the integer which is ging to contains the number 1 if the result is true   
* @return result
*/

int result(enigme e,image vict,image def,int defo,int victo,SDL_Surface *ecran)
{
int resultat;
if (victo==1)
  {
                 
     afficher_image(vict,ecran);
     switch(e.resultat)    
  	{	
           case 2:
   		afficher_image(e.photo2o,ecran);
           break;
 	   case 3:
                 afficher_image(e.photo3o,ecran);
           break;
           case 4:
               	 afficher_image(e.photo4o,ecran);
       	   break;
        }
                 
      resultat=1;
  }
   
   if(defo==1)
     {
        afficher_image(def,ecran);
        switch(e.resultat)
            {	
              case 2:
            	afficher_image(e.photo2o,ecran);
      	      break;
       	      case 3:
            	 afficher_image(e.photo3o,ecran);
     	      break;
              case 4:
             	afficher_image(e.photo4o,ecran);
       	      break;
                   
            }
                 
       resultat=0;
     
    }    


return resultat;
}


/**
* @brief the ending of the quiz 
* @param int *continuer that we're going to use it to stop the boucle for{}     
* @param int resultat is the result if its true or false 
* @return nothing
*/
void after_result(int resultat,int *continuer)
{
if(resultat==1)
     {
          SDL_Delay(3000);
          *continuer=0;
     }
if(resultat==0)
     {
          SDL_Delay(3000); 
          *continuer=0;
     }
}

/**
* @brief free all the surfaces 
* @param enigme e the enigme that has the images to display in the screen 
* @param image vict contains the winning image 
* @param image def contains the lose image  
* @param image temps[] is an images list used to load the images in it 
* @param image background contains the background imag 
* @return nothing
*/
void liberer_les_images(enigme e,image background,image temps[],image vict,image def)
{int i;

               SDL_FreeSurface(background.img);
               SDL_FreeSurface(vict.img);
               SDL_FreeSurface(def.img);

               for (i=1;i<66;i++)
                 {
                 SDL_FreeSurface(temps[i].img);
                 }
               
                 SDL_FreeSurface(e.photo1.img);
                 SDL_FreeSurface(e.photo2.img);
                 SDL_FreeSurface(e.photo3.img); 
                 SDL_FreeSurface(e.photo4.img);
                 
                 SDL_FreeSurface(e.photo2o.img);
                 SDL_FreeSurface(e.photo3o.img); 
                 SDL_FreeSurface(e.photo4o.img);
}





















