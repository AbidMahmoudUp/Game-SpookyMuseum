#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "enigme.h"

int enigme_image(SDL_Surface *ecran,image background,image temps[],image vict,image def)
{
SDL_Event event ;
enigme e;
int continuer=1,click=0,victo=0,defo=0,resultat,i=1,occ=1;
char fichier[30];

///fichier
int fich_numero;
choose_file_randomly(&fich_numero,fichier);
///
e=loading_enigme(fichier,fich_numero);

while(continuer)
	{	
                if(i==65)
                  {
                   i=1;
                   occ++;                 
                  } 
                after_result(resultat,&continuer);
                afficher_image(background,ecran);
                afficher_enigme(e,ecran);
                resultat=result(e,vict,def,defo,victo,ecran);
                 if(occ!=3)
                 {
                 animer(temps,i,ecran);
                 i++;
                 SDL_Delay(100);
                 }  
                    switch(click)
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
	
		while (SDL_PollEvent(&event)){
		switch(event.type)
		{
		case SDL_QUIT:
			continuer=0;
                        resultat=0;
			break;

	  case SDL_KEYDOWN:
	      switch(event.key.keysym.sym)
			{ 
	         case SDLK_ESCAPE:
		continuer=0;
                resultat=0;
		break;
                       }
	case SDL_MOUSEMOTION :
	     if((event.motion.x>=35 )&&(event.motion.x<=205)&&(event.motion.y>=200)&&(event.motion.y<240))
            	{
                       click=2;         
                } 

              else if((event.motion.x>=35 )&&(event.motion.x<=205)&&(event.motion.y>=300)&&(event.motion.y<340))
              {
            		click=3;         
              }
              else if((event.motion.x>=35 )&&(event.motion.x<=205)&&(event.motion.y>=400)&&(event.motion.y<440))
              {
                       click=4;         
              }        
    
              else{       
                 click=0;
                  }
        break;                       
                                             
                       
       case SDL_MOUSEBUTTONUP:
        
            if(event.button.button==SDL_BUTTON_LEFT)
            	      { 
            	
            	if((click==e.resultat)&&(occ!=3))
                    {
	            victo=1;
                    }   
                else if ((click!=e.resultat)||(occ==3))
                { 
                defo=1;
            	}
			
		       }                 
                }}
		SDL_Flip(ecran);	
	}

liberer_les_images(e,background,temps,vict,def);	          
return resultat;
}



