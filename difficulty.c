#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "jeu.h"
#include "image.h"
#include"player.h"
#include "enemy.h"
void niveau(SDL_Surface *ecran,image background1,image backgroundo,image cinematique[],imagee win,imagee lose,image solo,image duo,image soloo,image duoo,Background b,image background,player perso,player vie,player coin,enemy e[],txt txt_scoree,txt txt_viee,image p1[],image p2[],imagee background_pause,imagee resume,imagee resumeo,imagee restart,imagee restarto,imagee saveandquit,imagee saveandquito,image choose,image background_enigme,image temps[],image vict,image def)
{
///declaration
	SDL_Event event;
	int continuer=3,curseur=0,cursor=0,modee=0;
while(continuer){
    
	afficher(background1,ecran);
	
	
    	
	            switch(cursor)
            	{	
            	        case 1:
			 afficher(backgroundo,ecran);
            		break;
             }
                  switch(modee)
            	{	
            	        case 1:
			 mode(cinematique,win,lose,solo,duo,soloo,duoo,b,background,ecran,perso,vie,coin,e,txt_scoree,txt_viee,p1,p2,background_pause,resume,resumeo,restart,restarto,saveandquit,saveandquito,choose,background_enigme,temps,vict,def);
			 modee=0;
            		break;
             }
           
while (SDL_PollEvent(&event)){
switch(event.type){
   case SDL_QUIT:	
   continuer=0;
   break;
  case SDL_KEYDOWN:
	 switch(event.key.keysym.sym){
case SDLK_ESCAPE:
continuer=0;	
			}
break; 
   case SDL_MOUSEMOTION :
		 if((event.motion.x>216 )&&(event.motion.x<320)&&(event.motion.y>80)&&(event.motion.y<190))
            	{//affiche starto.png lorsque la souris est a la position de start.png
            		curseur=1;
            		cursor=1;
            	}       
         else 
       {
    cursor=0;
       }
       case SDL_MOUSEBUTTONUP:
            if(event.button.button==SDL_BUTTON_LEFT)
            	{
            	switch(curseur)
            	{	case 1:
            	        modee=1;
			continuer=3;
            		break;
            	}	
            	}
            	
       

}}
SDL_Flip(ecran);
}


	SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));



}



