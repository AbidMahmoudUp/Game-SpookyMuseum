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
void choix_solo(image cinematique[],imagee win,imagee lose,image p1[],image p2[],Background b,image background,SDL_Surface *ecran,player perso,player vie,player coin,enemy e[],txt txt_scoree,txt txt_viee,imagee background_pause,imagee resume,imagee resumeo,imagee restart,imagee restarto,imagee saveandquit,imagee saveandquito,image choose,image background_enigme,image temps[],image vict,image def)
{
///declaration
	SDL_Event event;
	int continuer=3,curseur=0,cursor=0,playy=0,i=1,posenemies[4]={1000,1200,1000};      
while(continuer){
  afficher(background,ecran);
  afficher(choose,ecran);
    afficher(p1[0],ecran);
    afficher(p2[0],ecran);
    switch(cursor)
            	{	
            	    case 1:
                    afficher(p1[1],ecran);
            	    break;
            	    case 2:
                    afficher(p2[1],ecran);
                    break;   
             }
                  switch(playy)
            	{	
            	        case 1: 
                        
                         /* for(i=1;i<=690;i++)
                            {    if(cinematique[i].img!=NULL)
                                  {
                                 SDL_BlitSurface(cinematique[i].img, NULL, ecran,&cinematique[i].pos);
                                  }
                                 SDL_Flip(ecran);
                                 SDL_Delay(100);
                                
                           }*/	
                         init_player(&perso,80,1);                       		
	 play(b,win,lose,1,80,0,3,0,posenemies,ecran,perso,vie,coin,e,txt_scoree,txt_viee,1,background_pause,resume,resumeo,restart,restarto,saveandquit,saveandquito,background_enigme,temps,vict,def);
			 playy=0;
            		break;
            		case 2:
                            /* for(i=1;i<=690;i++)
                            {    if(cinematique[i].img!=NULL)
                                  {
                                 SDL_BlitSurface(cinematique[i].img, NULL, ecran,&cinematique[i].pos);
                                  }
                                 SDL_Flip(ecran);
                                 SDL_Delay(100);
                                
                           }*/	
                          init_player(&perso,80,2);                      		
	 play(b,win,lose,1,80,0,3,0,posenemies,ecran,perso,vie,coin,e,txt_scoree,txt_viee,2,background_pause,resume,resumeo,restart,restarto,saveandquit,saveandquito,background_enigme,temps,vict,def);
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
		 if((event.motion.x>300 )&&(event.motion.x<380)&&(event.motion.y>200)&&(event.motion.y<400))
            	{
            		curseur=1;
            		cursor=1;
            		
            	}
else if((event.motion.x>600 )&&(event.motion.x<680)&&(event.motion.y>200)&&(event.motion.y<400))
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




