#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include"player.h"
#include "jeu.h" 
#include "enemy.h"

void pause(SDL_Surface *ecran,int *restartt,player perso,Background b,int lvl,int viee,int score,enemy e[],int num_perso,imagee background,imagee resume,imagee resumeo,imagee restart,imagee restarto,imagee saveandquit,imagee saveandquito)
{
///declaration
	SDL_Event event;
	int continuer=3,curseur=0,cursor=0,resumee=0,save=0;       

while(continuer){
        afficher_pause(background,ecran);
        afficher_pause(resume,ecran);
	afficher_pause(restart,ecran);
        afficher_pause(saveandquit,ecran);
       if(save==1)
          {    
                save_game(perso,b,lvl,viee,score,e,num_perso);
                exit(0);
          }
    switch(cursor)
            	{	
            	        case 1:
			 afficher_pause(resumeo,ecran);
            		break;
            		case 2:
            		afficher_pause(restarto,ecran);
            		break;  
                        case 3:
            		afficher_pause(saveandquito,ecran);
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
		 if((event.motion.x>100 )&&(event.motion.x<200)&&(event.motion.y>100)&&(event.motion.y<166))
            	{//affiche starto.png lorsque la souris est a la position de start.png
            		curseur=1;
            		cursor=1;
            		
            	}
else if((event.motion.x>100 )&&(event.motion.x<200)&&(event.motion.y>200)&&(event.motion.y<266))
              {//affiche settingso.png lorsque la souris est a la position de setting.png
            		curseur=2;   
            		cursor=2;      
              } 

else if((event.motion.x>100 )&&(event.motion.x<250)&&(event.motion.y>300)&&(event.motion.y<366))
              {//affiche settingso.png lorsque la souris est a la position de setting.png
            		curseur=3;   
            		cursor=3;      
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
            	        continuer=0;
            		break;
            		case 2:
                        *restartt=1;
                        continuer=0;
            		break;
                        case 3:
                        save=1;
            		break;
            	}	
            	}
            	
       

}}
SDL_Flip(ecran);
}


     SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));

}
