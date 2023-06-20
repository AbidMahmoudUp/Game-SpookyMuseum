/**
* @file enemy.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "enemy.h"

/**
* @brief loading the enemy 
* @param enemy *e used to load the enemy
* @param int pos_x the position of the enemy 
* @param int num used to know the type of the enemy we're loading (the male monster or the female monster)  
* @return nothing
*/
void init_enemy(enemy *e,int pos_x,int num)
{int i;
char gauche[40],attack[40],droite[40];
if(num==1)
{
for (i=1 ;i<=9; i++)
{
 sprintf(gauche,"enemy_gauche/%d.png",i);
 e->gauche[i].img=IMG_Load(gauche);
}

for (i=1 ;i<=9; i++)
{
 sprintf(droite,"enemy_droite/%d.png",i);
 e->droite[i].img=IMG_Load(droite);
}

for (i=1 ;i<=7; i++)
{
 sprintf(attack,"enemy_attack/%d.png",i);
 e->attack[i].img=IMG_Load(attack);
}

e->pos.x=pos_x;
e->pos.y=420;
e->pos.h=300;
e->pos.w=400;
}
else if(num==2)
{
for (i=1 ;i<=11; i++)
{
 sprintf(gauche,"enemy_gaucheo/%d.png",i);
 e->gauche[i].img=IMG_Load(gauche);
}
for (i=1 ;i<=11; i++)
{
 sprintf(droite,"enemy_droiteo/%d.png",i);
 e->droite[i].img=IMG_Load(droite);
}
for (i=1 ;i<=4; i++)
{
 sprintf(attack,"enemy_attacko/%d.png",i);
 e->attack[i].img=IMG_Load(attack);
}
e->pos.x=pos_x;
e->pos.y=350;
e->pos.h=300;
e->pos.w=300;
}
}








/**
* @brief loading all the enemies
* @param enemy e[] used to load all the enemies
* @param int posenemies[]  the position of the all the enemies 
* @param int lvl the level   
* @return nothing
*/
void init_enemies(enemy e[],int lvl,int posenemies[])
{
   init_enemy(&e[0],posenemies[0],1);
   init_enemy(&e[1],posenemies[1],2);
   init_enemy(&e[2],posenemies[2],1);

}
























/**
* @brief initialize the input to zero
* @param inputenemy *I used to save the input of the enemy  
* @return nothing
*/
void init_input_enemy(inputenemy *I)
{
for(int i=0;i<3;i++)
   {
    I->attack[i]=0   ;         
    I->deplacer[i]=0 ;
    I->afficher[i]=0 ;
    I->run[i]=0 ;
   }
} 



/**
* @brief get the input of the enemy 
* @param inputenemy *I used to save the input of the enemy  
* @param Background b used to know the time to move and display the  enemy 
* @param enemy e[] is the list of all the enemies
* @return nothing
*/
void get_input_enemy(inputenemy *I,Background b,enemy e[],int etat_perso)
{
//input attack de l'enemy
for(int i=0;i<3;i++)
   {
    if(e[i].pos.x<=700)
       I->attack[i]=1 ;
    else 
       I->attack[i]=0 ; 
   
if((e[i].pos.x<=1000)&&(e[i].pos.x>300))
{
   if(etat_perso==1)
  {
   I->attack[i]=0 ;
   I->run[i]=1 ; 
  }
 else  
  I->run[i]=0 ; 
   
}

 }
///////////////////////////////
//input deplacement et affichage  de l'enemy
if(b.scroll.x<=1000)
  {
    I->deplacer[0]=1 ;
    I->afficher[0]=1 ;
  }

if((b.scroll.x>=1000)&&(b.scroll.x<=2000))
  {
    I->deplacer[1]=1 ;
    I->afficher[1]=1 ;
  }

if((b.scroll.x>=2000)&&(b.scroll.x<=3000))
  {
    I->deplacer[2]=1 ;
    I->afficher[2]=1 ;
  }
//input running from the player 

}







/**
* @brief move the enemy  
* @param enemy e is the enemy that we want to move 
* @return nothing
*/
void deplacer_enemy(enemy *e)
{
 e->pos.x= e->pos.x-5;
}







/**
* @brief move all the enemies  
* @param int lvl is the level
* @param inputenemy I is the state of the enemy(input)
* @param enemy e[] is the list of all the enemies that we want to move 
* @return nothing
*/

void deplacer_enemies(enemy e[],int lvl,inputenemy I)
{
   if((I.deplacer[0]==1)&&(I.run[0]==0))
   deplacer_enemy(&e[0]);
   else if(I.run[0]==1)
      {
           e[0].pos.x= e[0].pos.x+5;
      }
   
   if((I.deplacer[1]==1)&&(I.run[1]==0))
   deplacer_enemy(&e[1]);
    else if(I.run[1]==1)
      {
           e[1].pos.x= e[1].pos.x+5;
      }
   
   if((I.deplacer[2]==1)&&(I.run[2]==0))
   deplacer_enemy(&e[2]);
   else if(I.run[2]==1)
      {
           e[2].pos.x=e[2].pos.x+5;
      }
}






/**
* @brief display an image
* @param imagee p is the image of enemy that we want to display
* @return nothing
*/
void afficher_enemy (imagee p,SDL_Surface *ecran)
{
SDL_BlitSurface(p.img, NULL, ecran,&p.pos);
}



/**
* @brief display the enemy 
* @param etat_attack is the input or the state of that enemy 
* @param int num used to know the type of the enemy we're loading (the male monster or the female monster) 
* @param enemy e is the enemy that we want to display
* @param SDL_Surface *ecran  the surface where we're going to blit the image on it 
* @return nothing
*/
void annimer_enemy(enemy e,int *j,SDL_Surface *ecran,int num,int etat_attack,int etat_run)
{
if(num==1)
{
if(etat_attack==1)
{
if(*j>=7)
*j=1;
  e.attack[*j].pos=e.pos;
   e.attack[*j].pos.y -=100 ;
  afficher_enemy (e.attack[*j],ecran);
  *j=*j+1;
}
else if(etat_run==1)
{
if(*j==9)
*j=1;
  e.droite[*j].pos=e.pos;
  afficher_enemy (e.droite[*j],ecran);
  *j=*j+1;
}
else 
{
if(*j==9)
*j=1;
  e.gauche[*j].pos=e.pos;
  afficher_enemy (e.gauche[*j],ecran);
  *j=*j+1;
}
}
else if(num==2)
{
if(etat_attack==1)
{
if(*j>=4)
*j=1;
  e.attack[*j].pos=e.pos;
  afficher_enemy (e.attack[*j],ecran);
  *j=*j+1;
}
else if(etat_run==1)
{
if(*j==11)
*j=1;
  e.droite[*j].pos=e.pos;
  afficher_enemy (e.droite[*j],ecran);
  *j=*j+1;
}
else 
{
if(*j==11)
*j=1;
  e.gauche[*j].pos=e.pos;
  afficher_enemy (e.gauche[*j],ecran);
  *j=*j+1;
}

}
}









/**
* @brief display all the enemies 
* @param enemy e[] is  the list of all the  enemies that we want to display
* @param inputenemy I is the state of the enemy(input)
* @param int lvl is the level
* @param SDL_Surface *ecran  the surface where we're going to blit the image on it 
* @return nothing
*/
void annimer_enemies(enemy e[],int lvl,int *j,SDL_Surface *ecran,inputenemy I)
{int j1=*j,j2=*j,j3=*j;
   
  if(I.afficher[0]==1)
  annimer_enemy(e[0],&(*j),ecran,1,I.attack[0],I.run[0]);
  if(I.afficher[1]==1)
  annimer_enemy(e[1],&j1,ecran,2,I.attack[1],I.run[1]);
  if(I.afficher[2]==1)
  annimer_enemy(e[2],&j2,ecran,1,I.attack[2],I.run[2]);


SDL_Delay(10);
SDL_Flip(ecran);
}










/**
* @brief get the result if there is a collison between the enemy and the player or not   
* @param enemy e is  the enemy
* @param player perso is  the player
* @return collision
*/
int collision_enemy_perso(player perso, enemy e)
{int collision=0;
	if((perso.x  >= e.pos.x+e.pos.w-170)//GAUCHE
    || (perso.x + perso.w -130 <= e.pos.x )//DROITE
    || (perso.y >= e.pos.y + e.pos.h -20)//BAS
    || (perso.y + perso.h -20 <=e.pos.y)//HAUT
    	)
   	collision=0;
   	else  
   	collision=1;
   	return collision;
    }





/**
* @brief get the result if there is a collison between all the enemies and the player or not   
* @param enemy e[] is  the list of all the  enemies 
* @param player perso is  the player
* @return collision
*/

int collision_enemies(player perso, enemy e[])
{int test=0,i=0;
 
 while((test==0)&&(i<3))
   {  
     test=collision_enemy_perso(perso,e[i]);
      i++;
   }

return test;
}






