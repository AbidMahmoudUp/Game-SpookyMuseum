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
void mode(image cinematique[],imagee win,imagee lose,image solo,image duo,image soloo,image duoo,Background b,image background,SDL_Surface *ecran,player perso,player vie,player coin,enemy e[],txt txt_scoree,txt txt_viee,image p1[],image p2[],imagee background_pause,imagee resume,imagee resumeo,imagee restart,imagee restarto,imagee saveandquit,imagee saveandquito,image choose,image background_enigme,image temps[],image vict,image def)
{
///declaration
	SDL_Event event;
	int continuer=3,curseur=0,cursor=0,playy=0,i=1,posenemies[4]={1000,1200,1000};      
while(continuer){
  afficher(background,ecran);
  afficher(solo,ecran);
  afficher(duo,ecran);
    switch(cursor)
            	{	
            	    case 1:
	       	    afficher(soloo,ecran);
            	    break;
            	    case 2:
            	    afficher(duoo,ecran);
                    break;   
             }
                  switch(playy)
            	{	
            	        case 1: 
			
			choix_solo(cinematique,win,lose,p1,p2,b,background,ecran,perso,vie,coin,e,txt_scoree,txt_viee,background_pause,resume,resumeo,restart,restarto,saveandquit,saveandquito,choose,background_enigme,temps,vict,def);
			 playy=0;
            		break;
            		case 2:
                          /* for(i=1;i<=690;i++)
                            {
                                 if(cinematique[i].img!=NULL)
                                  {
                                 SDL_BlitSurface(cinematique[i].img, NULL, ecran,&cinematique[i].pos);
                                  }
                                 SDL_Flip(ecran);
                                 SDL_Delay(100);
                            }
			*/
            		 multiplayer(ecran);
			 playy=0;
            		break;   
             }
while (SDL_PollEvent(&event)){
switch(event.type){
   case SDL_QUIT:	
   exit(0);
   break;
  case SDL_KEYDOWN:
	 switch(event.key.keysym.sym){
case SDLK_ESCAPE:
continuer=0;	
			}
break; 
   case SDL_MOUSEMOTION :
		 if((event.motion.x>13 )&&(event.motion.x<290)&&(event.motion.y>45)&&(event.motion.y<200))
            	{
            		curseur=1;
            		cursor=1;
            		
            	}
else if((event.motion.x>13 )&&(event.motion.x<290)&&(event.motion.y>300)&&(event.motion.y<450))
              {
            		curseur=2;   
            		cursor=2;      
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
            	        playy=1;
            		break;
            		case 2:
            		playy=2;
            		break;
            	}	
            	}
            	
       

}}
SDL_Flip(ecran);
}


	SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));

	


}




