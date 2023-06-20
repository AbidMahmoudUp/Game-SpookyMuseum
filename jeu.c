/**
* @file jeu.c
* @brief testing program.
* @author Mahmoud Abid 
* @version 0.1
* @date Apr 24 ,2022
*
* testing program for player
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include"player.h"
#include "jeu.h" 
#include "enemy.h"
#include "enigme.h"
#include "enigme_txt.h"
#include "xo.h" 

void play(Background b,imagee win,imagee lose,int lvl,int posperso,int posbackg,int viee,int score,int posenemies[],SDL_Surface *ecran,player perso,player vie,player coin,enemy e[],txt txt_scoree,txt txt_viee,int num_perso,imagee background_pause,imagee resume,imagee resumeo,imagee restart,imagee restarto,imagee saveandquit,imagee saveandquito,image background_enigme,image temps[],image vict,image def)
{
//-----------------------------------------------------------------------------------
int continuer=1,count=0,maxcount=0,pausee,restartt,gauche=0,droite=0,i=1,j=1,j1=1,j2=1,collision_enemy=0,collision_background=0,updated=0,nextlvl=0,occ_enigme=1;
int enigme=0; 
unsigned int frameLimit=SDL_GetTicks()+16;
Uint32 dt,t_prev;
Input in;
inputenemy I;
SDL_Event event;
b.scroll.x=posbackg;
perso.x=posperso;
//--------------------------------------------------------------
 while(continuer)
 {	t_prev=SDL_GetTicks();
	
        afficherTous(&perso,vie,coin,ecran,b,txt_scoree,txt_viee);
        appel_enigme(&viee,&occ_enigme,&enigme,&score,&maxcount,&txt_scoree,&txt_viee,&perso,&b,e,lose,&restartt,ecran,background_enigme,temps,vict,def) ;
        restart_the_mission(&viee,&score,&maxcount,&txt_scoree,&txt_viee,&perso,&b,e,&restartt,lvl,posenemies,&I);
        appel_pause(&pausee,&restartt,ecran,perso,b,lvl,viee,score,e,num_perso,background_pause,resume,resumeo,restart,restarto,saveandquit,saveandquito);
        get_input_enemy(&I,b,e,in.attack);
/////          
          if(collision_enemy==1)
           { if(b.scroll.x>1200)
              {
                for(i=0;i<5;i++)
                e[i].pos.x+=400;
              
            perso.x-=800;
            b.scroll.x-=800;
              }
            else 
              {
              for(i=0;i<5;i++)
              e[i].pos.x+=300;
               }
             maxcount=0;
            viee--;
            init_txt_vie(&txt_viee,viee);  
           }
     ///////       
             count=b.scroll.x;
          if(count-maxcount>=130)
         {
            score++;
            init_txt_score(&txt_scoree,score);
            maxcount=count ;
            
         }
         //////
 	 getInput(&in,&pausee);
 	 deplacerPerso(&perso,&in,&b,&updated,dt,num_perso);
          deplacer_enemies(e,lvl,I);

         animerPerso(&perso,ecran);
        
        	
 	  collision_enemy=collision_enemies(perso,e);
       //  collision_background=collisionPP(perso,mask.background);
        annimer_enemies(e,lvl,&j,ecran,I);
        lvl=move_to_the_next_lvl(win,lvl,&b,&perso,e,ecran,&maxcount,&pausee,posenemies,&I);
	dt=SDL_GetTicks()-t_prev;
 }
 	SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
 	SDL_FreeSurface(perso.sprite);
}



