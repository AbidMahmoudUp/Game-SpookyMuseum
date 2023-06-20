#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "enigme_txt.h"

int enigme_txtt(SDL_Surface *ecran)
{SDL_Event event ;

imageee background,temps[90],vict,def;
enigme_txt e;
int continuer=1,click=0,victo=0,defo=0,resultat,i=1,occ=1;
///fichier
int fich_numero;
srand(time(NULL));
fich_numero=1+rand() %7 ;
///
loading_all_txt(&background,&vict,&def);
loading_temps_txt(temps);
e=loading_enigme_txt(fich_numero);

while(continuer)
	{	
                if(i==65)
                  {
                   i=1;
                   occ++;                 
                  } 
                after_result_txt(resultat,&continuer);
                afficher_img_txt(background,ecran);
                afficher_enigme_txt(e,ecran);
                resultat=result_txt(e,vict,def,defo,victo,ecran);
                 if(occ!=3)
                 {
                 animer_txt(temps,i,ecran);
                 i++;
                 SDL_Delay(100);
                 }  
                    switch(click)
            	{	
                  case 1:
   		  afficher_txt_enigme(e.reponse1o,ecran);
                  break;
 	          case 2:
                  afficher_txt_enigme(e.reponse2o,ecran);
                  break;
                  case 3:
               	 afficher_txt_enigme(e.reponse3o,ecran);
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
                       click=1;         
                } 

              else if((event.motion.x>=35 )&&(event.motion.x<=205)&&(event.motion.y>=300)&&(event.motion.y<340))
              {
            		click=2;         
              }
              else if((event.motion.x>=35 )&&(event.motion.x<=205)&&(event.motion.y>=400)&&(event.motion.y<440))
              {
                       click=3;         
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

liberer_les_images_txt(e,background,temps,vict,def);	          
return resultat;
}



