#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include"player.h"
#include "jeu.h"
#include "image.h"
#include "enemy.h"

void load_the_game(image background,image loading[],imagee win,imagee lose,SDL_Surface *ecran,player perso,player vie,player coin,enemy e[],txt txt_scoree,txt txt_viee)
{
int lvl,posperso,posbackg,viee,score,i=2,posenemies[4],done=1,num_perso;
char *ch_perso="save/perso.txt",*ch_background="save/background.txt",*ch_lvl="save/lvl.txt",*ch_vie="save/vie.txt",*ch_score="save/score.txt",*ch_enemy0="save/enemy0.txt",*ch_enemy1="save/enemy1.txt",*ch_enemy2="save/enemy2.txt",*ch_num_perso="save/num_perso.txt";
Background b;

//load informations
load(&posperso,ch_perso);
load(&posbackg,ch_background);
load(&lvl,ch_lvl);
load(&viee,ch_vie);
load(&score,ch_score);
//load enemies
load(&posenemies[0],ch_enemy0);
load(&posenemies[1],ch_enemy1);
load(&posenemies[2],ch_enemy2);
load(&num_perso,ch_num_perso);
///load background
b=initBack(b,lvl);
init_enemies(e,lvl,posenemies);
init_player(&perso,80,num_perso);
///



      while(done==1)
     {
       afficher(background,ecran);
       afficher(loading[i],ecran); 
        i++;
        SDL_Delay(100);
    	if(i==40)
         {
          play(b,win,lose,lvl,posperso,posbackg,viee,score,posenemies,ecran,perso,vie,coin,e,txt_scoree,txt_viee,num_perso);
           done=0;
         }
       SDL_Flip(ecran);
      }          

  




}
