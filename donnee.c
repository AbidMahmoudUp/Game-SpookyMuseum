/**
* @file donnee.c
*/
#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "jeu.h"
#include "time.h"
#include "enemy.h" 
#include "enigme_txt.h"
#include "enigme.h"
#include "xo.h" 
void init_win_lvl(imagee *load)
{
load->img = IMG_Load("background/win.png");
load->pos.x=0;
load->pos.y=0;
}
void init_lose_lvl(imagee *load)
{
load->img = IMG_Load("background/lose.png");
load->pos.x=0;
load->pos.y=0;
}
Background initBack(Background b,int lvl)
{  
  if (lvl==1)
  b.imgBack1 = IMG_Load("background/map1.png");
  else
  b.imgBack1 = IMG_Load("background/map3.png");

  b.posBack1.x = 0;
  b.posBack1.y = 20;
  b.scroll.x = 0;
  b.scroll.y = 20;
  b.scroll.w = 12098;
  b.scroll.h = 1007;
return b;
}
void afficherBack(Background b, SDL_Surface *ecran)
{

  SDL_BlitSurface(b.imgBack1, &(b.scroll), ecran,NULL );
}
void scrollingBack(Background *b, player *p, Input I,int *updated)
{
if((I.left==1)&&(p->x<300))
{
	*updated=0;
}
else if ((I.left==0)&&(p->x<300))
{
	*updated=0;
}
if(*updated==1)
p->x=299;

if(p->x>300)
  { 
    *updated=1;
  }
else if((p->x<300)&&(*updated=0)&&(I.right==1))
 {
 b->scroll.x = p->x ;
 b->posBack1.x =p->x; 
 }
else if((p->x<300)&&(*updated=1)&&(I.right==1))
 {
 b->scroll.x +=4 ;
 b->posBack1.x +=4; 
 }
}

void init_txt_score(txt *txt,int score)
{char s[30];
	// POSITION de txt
	txt->pos.x=180;
	txt->pos.y=25;
	TTF_Init();
	SDL_Color couleur={255,128,0};
	sprintf(s,"%d",score);
	//initialisation de couleur de txt 
	//chargement d'une police et initisation de la taille 
	txt->p=TTF_OpenFont("text/game.ttf",40);
	
	txt->t=TTF_RenderText_Blended(txt->p,s,couleur);
	// bliter la surface de txt
	 //fermer la police 
	 TTF_CloseFont (txt->p);
	 //arreter sdl_ttf
	 TTF_Quit();
}
void init_txt_vie(txt *txt,int vie)
{char s[30];
	// POSITION de txt
	txt->pos.x=85;
	txt->pos.y=25;
	TTF_Init();
	SDL_Color couleur={255,128,0};
	sprintf(s,"%d",vie);
	//initialisation de couleur de txt 
	//chargement d'une police et initisation de la taille 
	txt->p=TTF_OpenFont("text/game.ttf",40);
	
	txt->t=TTF_RenderText_Blended(txt->p,s,couleur);
	// bliter la surface de txt
	 //fermer la police 
	 TTF_CloseFont (txt->p);
	 //arreter sdl_ttf
	 TTF_Quit();
}
void afficher_txt(txt te,SDL_Surface *ecran)
{
SDL_BlitSurface(te.t, NULL, ecran,&te.pos);
}
//-------------------------------------------------------------------------------
/**
* @brief initialisation du personage
* @param perso the player
* @param posperso pour la sauvegarde de la position
* @return nothing
*/
void init_player(player *perso,int posperso,int num_perso)
{		
	if(num_perso==1)
        perso->sprite=IMG_Load("Animationpersonage/right.png");
        else if (num_perso==2)
        perso->sprite=IMG_Load("Animationpersonage/right2.png");
	perso->x=posperso;
	perso->y=400;
	perso->w=LARGEUR_JOUEUR;
	perso->h=HAUTEUR_JOUEUR;
	perso->direction=0;
	perso->etat=REPOS;
	perso->frameNumber=0;
	perso->frameTimer=INIT;
	perso->v_x=4;
	perso->v_grav=0.3;
	perso->v_saut=-4.5;
	perso->v_y=perso->v_saut;
	perso->onGround=1;
	perso->acceleration=0;
	perso->vitesse=0.005;
	
}
//-------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/**
* @brief initialisation de la vie
* @param vie la vie du personage
* @return nothing
*/
void init_vie(player *vie)
{
	vie->sprite=IMG_Load("background/life.png");
	vie->posvie.x=20;
	vie->posvie.y=20;
}
/**
* @brief affichage de la vie
* @param vie la vie
* @param ecran la surface ou on va bliter l image 
* @return nothing
*/
void afficher_vie(player vie , SDL_Surface *ecran)
{
	SDL_BlitSurface(vie.sprite,NULL,ecran,&vie.posvie);
} 
//------------------------------------------------------------------------------
SDL_Surface *loadImage(char *name)
{
       SDL_Surface *temp = IMG_Load(name);
       SDL_Surface *image;
      if (temp == NULL)
      {
           printf("Failed to load image %s\n", name);
          return NULL;
       }
          image = temp;
       if (image == NULL)
       {
           printf("Failed to convert image %s to native format\n", name);
           return NULL;
       }
       return image;

}
//-------------------------------------------------------------------------------
/**
* @brief changement de l image 
* @param entity the player
* @param name le shemas ou ce trouve l image
* @return nothing
*/
void changeAnimation(player *entity, char *name)
{
    //On libère l'animation précédente
    if (entity->sprite != NULL)
    {
        SDL_FreeSurface(entity->sprite);
    }
    //On charge la nouvelle
    entity->sprite = IMG_Load(name);
    //On réinitialise la frame et le timer
    entity->frameNumber = 0;
    entity->frameTimer = INIT;
}
         
//-------------------------------------------------------------------------------
/**
* @brief initialisation score
* @param coin le symbole du score 
* @return nothing
*/
void init_coin(player *coin)
{
	coin->sprite=IMG_Load("background/coins.png");
	coin->posvie.x=100;
	coin->posvie.y=5;
}
/**
* @brief affichage du score
* @param coin symbole du score
* @param ecran la surface ou on va bliter l image 
* @return nothing
*/
void afficher_coin(player coin , SDL_Surface *ecran)
{
	SDL_BlitSurface(coin.sprite,NULL,ecran,&coin.posvie);
}
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
/**
* @brief affichage de tous les image
* @param perso the player
* @param vie  l image du vie 
* @param coin  l image du score 
* @param b  l image du background 
* @param txt_scoree  limage du  le text du score 
* @param txt_vie  l image du text du vie 
* @return nothing
*/
void afficherTous(player *perso ,player vie, player coin ,SDL_Surface *ecran , Background b,txt txt_scoree,txt txt_viee)
{	
	SDL_BlitSurface(b.imgBack1,&(b.scroll), ecran,NULL);
	afficherPerso(perso,ecran);
	afficher_vie(vie,ecran);
	afficher_coin(coin,ecran);
        afficher_txt(txt_scoree,ecran);
        afficher_txt(txt_viee,ecran);
	
		
}
//-------------------------------------------------------------------------------
/**
* @brief animation du personage
* @param perso  player
* @param ecran la surface ou on va bliter l image 
* @return nothing
*/
void animerPerso(player *perso , SDL_Surface *ecran)
{
	if(perso->frameTimer<=0)
	{
		
		perso->frameTimer=INIT;
		perso->frameNumber++;
		if(perso->frameNumber>=perso->sprite->w/LARGEUR_JOUEUR)
		{
			perso->frameNumber=0;
		}
	}
	else
	{
		perso->frameTimer--;
	}
		
}
//-------------------------------------------------------------------------------
/**
* @brief affichage du personage
* @param perso l image du player
* @param ecran la surface ou on va bliter l image 
* @return nothing
*/
void afficherPerso(player *perso , SDL_Surface *ecran)
{	
	SDL_Rect dest;
	SDL_Rect src;
	//   afficheage de la distination-------------------------------
	dest.x=perso->x;
	dest.y=perso->y;
	dest.w=LARGEUR_JOUEUR;
	dest.h=HAUTEUR_JOUEUR;
	//---------------------
	src.x=perso->frameNumber*LARGEUR_JOUEUR;
	src.y=0;
	src.w=LARGEUR_JOUEUR;
	src.h=HAUTEUR_JOUEUR;
	//---------------------
	SDL_BlitSurface(perso->sprite,&src,ecran,&dest);	
}
//-------------------------------------------------------------------------------
/**
* @brief le deplacement du personage 
* @param perso the player
* @param in input donner par le clavier 
* @param b background
* @param updated varible pour le scrolling
* @param dt le temp pour l acceleration
* @return nothing
*/
void deplacerPerso(player *perso , Input *in,Background *b,int *updated,Uint32 dt,int num_perso)
{	
	int pos_courante, verif=0;
	colision(perso);
	if(in->up==1)
	{	perso->y -=perso->vitesse * dt + perso->acceleration *0.5* dt * dt ;
		if(perso->y<0)
 		{
 			perso->y=0;
 		}
 		
	}
	else if (in->down==1)
	{	perso->y +=perso->vitesse * dt + perso->acceleration *0.5* dt * dt ;
		if(perso->y+HAUTEUR_JOUEUR>HAUTEUR_ECRAN)
 		{
 			perso->y=HAUTEUR_ECRAN-HAUTEUR_JOUEUR;
 		}
		
	}
	
	 if(in->left==1)
	{	perso->x -= perso->acceleration *0.5* dt * dt +perso->vitesse * dt  ;
		perso->direction=LEFT;
		if(perso->x<0)
		{
			perso->x=0;
		}
		if(perso->etat != WALK_LEFT)
		{	perso->etat=WALK_LEFT;
                        if(num_perso==1)
			changeAnimation(perso,"Animationpersonage/backwards.png");
                        else if(num_perso==2)
                         changeAnimation(perso,"Animationpersonage/backwards2.png");
			//perso->sprite=IMG_Load("Animationpersonage/backwards.png");
			//perso->frameNumber=0;	
		}
		
		
	
		
	}
	else if(in->right==1)
	{       
               
		perso->x +=perso->acceleration *0.5* dt * dt +perso->vitesse * dt ;
		perso->direction=RIGHT;
		if(perso->x+LARGEUR_JOUEUR>=LARGEUR_ECRAN)
 		{	perso->x=LARGEUR_ECRAN-LARGEUR_JOUEUR;
 		}
 	    
 		
 		
		if(perso->etat != WALK_RIGHT)
		{	perso->etat=WALK_RIGHT;
                        if(num_perso==1)
			changeAnimation(perso,"Animationpersonage/forward.png");
                        else if(num_perso==2)
                         changeAnimation(perso,"Animationpersonage/forward2.png");
			//perso->sprite=IMG_Load("Animationpersonage/forward.png");
			//perso->frameNumber=0;
		}


	}
	
	else if ((in->right==0)&&(in->left==0)&&(in->jump==0)&&(in->speed==0)&&(in->attack==0))
	{	if(perso->etat!=IDLE)
		{
			perso->etat=IDLE;
			if(perso->direction==LEFT)
			{       if(num_perso==1)
				changeAnimation(perso,"Animationpersonage/left.png");
                                else if(num_perso==2)
                                 changeAnimation(perso,"Animationpersonage/left2.png");
				//perso->sprite=IMG_Load("Animationpersonage/left.png");
				//perso->frameNumber=0;
				
			}
			else 
			{
				 if(num_perso==1)
				changeAnimation(perso,"Animationpersonage/right.png");
                                else if(num_perso==2)
                                 changeAnimation(perso,"Animationpersonage/right2.png");
				//perso->sprite=IMG_Load("Animationpersonage/right.png");
				//perso->frameNumber=0;
			}
		}
		
		
	}
	else if(in->speed==1)
	{
		perso->acceleration+=0.0005;
		if(perso->acceleration>0.01)
		{
			
			
				perso->acceleration +=-0.001;
			
		}
	}	
	 if (in->jump==1)
	{	
		perso->y -=JUMP_HAUTEUR;	
		pos_courante=perso->y -JUMP_HAUTEUR;
		
		if((perso->direction==RIGHT)&&(perso->etat != JUMP_RIGHT))
		{	perso->etat=JUMP_RIGHT;
                        if(num_perso==1)
			changeAnimation(perso,"Animationpersonage/JumpRight.png");
                         else if(num_perso==2)
                          changeAnimation(perso,"Animationpersonage/JumpRight2.png");
		}	
		else if ((perso->direction==LEFT)&&(perso->etat != JUMP_LEFT))
		{	perso->etat=JUMP_LEFT;
			  if(num_perso==1)
			changeAnimation(perso,"Animationpersonage/JumpLeft.png");
                         else if(num_perso==2)
                          changeAnimation(perso,"Animationpersonage/JumpLeft2.png");
		}	
	}
	perso->y+=GRAVITY_SPEED;
	if((perso->y<MAX_FALL_SPEED) &&(perso->direction==RIGHT) )
	{	perso->x+=perso->v_x;
		perso->y+=perso->v_y;
		perso->v_y+=perso->v_grav ;
	}
	else if((perso->y<MAX_FALL_SPEED) &&(perso->direction==LEFT) )
	{	perso->x-=perso->v_x;
		perso->y+=perso->v_y;
		perso->v_y+=perso->v_grav ; 
	}	
	if(perso->y>=MAX_FALL_SPEED)
	{
		perso->v_y=perso->v_saut;
		perso->y=MAX_FALL_SPEED;
	}
	
	else if((in->speed==1)&&(in->right==1))
	{
		perso->x +=perso->acceleration *0.5* dt * dt +perso->vitesse * dt ;
		perso->direction=RIGHT;
		if(perso->x+LARGEUR_JOUEUR>=LARGEUR_ECRAN)
 		{	perso->x=LARGEUR_ECRAN-LARGEUR_JOUEUR;
 		}
		if(perso->etat != WALK_RIGHT)
		{	perso->etat=WALK_RIGHT;
			 if(num_perso==1)
			changeAnimation(perso,"Animationpersonage/forward.png");
                         else if(num_perso==2)
                          changeAnimation(perso,"Animationpersonage/forward2.png");
			//perso->sprite=IMG_Load("Animationpersonage/forward.png");
			//perso->frameNumber=0;
		}
	}
	else if ((in->speed==1)&&(in->left==1))
	{	perso->x -=perso->acceleration *0.5* dt * dt +perso->vitesse * dt ;
		perso->direction=LEFT;
		if(perso->x<0)
		{
			perso->x=0;
		}
		if(perso->etat != WALK_LEFT)
		{	perso->etat=WALK_LEFT;
			 if(num_perso==1)
			changeAnimation(perso,"Animationpersonage/backward.png");
                         else if(num_perso==2)
                          changeAnimation(perso,"Animationpersonage/backward2.png");
			//perso->sprite=IMG_Load("Animationpersonage/backwards.png");
			//perso->frameNumber=0;	
		}
	}
		if(in->attack==1)
		{
			if((perso->direction==RIGHT)&&(perso->etat!=ATTACK_RIGHT))
			{
				perso->etat=ATTACK_RIGHT;
                                if(num_perso==1)
				changeAnimation(perso,"Animationpersonage/AttackRight.png");
                                else if(num_perso==2)
                                changeAnimation(perso,"Animationpersonage/AttackRight2.png");
			}
			else if ((perso->direction==LEFT)&&(perso->etat!=ATTACK_LEFT))
			{
				perso->etat=ATTACK_LEFT;
				if(num_perso==1)
				changeAnimation(perso,"Animationpersonage/AttackLeft.png");
                                else if(num_perso==2)
                                changeAnimation(perso,"Animationpersonage/AttackLeft2.png");
			}
		}
	
	scrollingBack(&(*b),&(*perso),*in,&(*updated));
}
//------------------------------------
/**
* @brief la collision avec les extrimter de  l ecran 
* @param perso the player
* @return nothing
*/
void colision (player *perso)
{
	if(perso->y<0)
 		{
 		
 			perso->y=0;
 		}
 		if(perso->x<0)
		{
			perso->x=0;
		}
 	if(perso->x+LARGEUR_JOUEUR>=LARGEUR_ECRAN)
 		{
 			perso->x=LARGEUR_ECRAN-LARGEUR_JOUEUR;
 		}
 	if(perso->y+HAUTEUR_JOUEUR>HAUTEUR_ECRAN)
 		{
 			perso->y=HAUTEUR_ECRAN-HAUTEUR_JOUEUR;
 		}
 	
}
//------------------------------------
void delay(unsigned int frameLimit)
{

    unsigned int ticks = SDL_GetTicks();

    if (frameLimit < ticks)
    {
        return;
    }

    if (frameLimit > ticks + 16)
    {
        SDL_Delay(16);
    }

    else
    {
        SDL_Delay(frameLimit - ticks);
    }
}
//-------------------------------------------------------------------------------
/**
* @brief l input donner par le clavier 
* @param input l input donner par le clavier
* @param pause variable pour la pause;
* @return nothing
*/
void getInput(Input *input,int *pause)
{
    

SDL_Event event;


    SDL_PollEvent(&event);
    
        switch (event.type)
        {

            case SDL_QUIT:
                exit(0);
            break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        *pause=1;
                    break;

                    case SDLK_LEFT:
                        input->left = 1;
                    break;

                    case SDLK_RIGHT:
                        input->right = 1;
                    break;

                    case SDLK_DOWN:
                        input->down = 1;
                    break;

                    case SDLK_UP:
                        input->up = 1;
                    break;

                    case SDLK_SPACE:
                        input->jump = 1;
                    break;
		    case SDLK_p:
			input->attack= 1;
		    break;
		    case SDLK_LALT:
                    	input->speed = 1;
                    default:
                    break;
                }
            break;

            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {

                    case SDLK_LEFT:
                        input->left = 0;
                    break;

                    case SDLK_RIGHT:
                        input->right = 0;
                    break;

                    case SDLK_DOWN:
                        input->down = 0;
                    break;

                    case SDLK_UP:
                        input->up = 0;
                    break;

                    case SDLK_SPACE:
                        input->jump= 0;
                    break;
	            case SDLK_LALT:
                    	input->speed = 0;
                    break;
		    case SDLK_p:
			input->attack=0;
	   	    break;
                    default:
                    break;
                }
            break;


        }

    }
void init_background_pause(imagee *background)
{
background->img = IMG_Load("background/back.png");
background->pos.x=0;
background->pos.y=0;
}

void init_resume_pause(imagee *resume)
{
resume->img = IMG_Load("boutons/resume.png");
resume->pos.x=100;
resume->pos.y=100;
}
void init_resumeo_pause(imagee *resume)
{
resume->img = IMG_Load("boutons/resumeo.png");
resume->pos.x=100;
resume->pos.y=100;
}

void init_restart_pause(imagee *resume)
{
resume->img = IMG_Load("boutons/restart.png");
resume->pos.x=100;
resume->pos.y=200;
}
void init_restarto_pause(imagee *resume)
{
resume->img = IMG_Load("boutons/restarto.png");
resume->pos.x=100;
resume->pos.y=200;
}

void init_saveandquit_pause(imagee *resume)
{
resume->img = IMG_Load("boutons/save and quit.png");
resume->pos.x=100;
resume->pos.y=300;
}
void init_saveandquito_pause(imagee *resume)
{
resume->img = IMG_Load("boutons/save and quito.png");
resume->pos.x=100;
resume->pos.y=300;
}

void afficher_pause(imagee p,SDL_Surface *ecran)
{
SDL_BlitSurface(p.img, NULL, ecran,&p.pos);
}

int move_to_the_next_lvl(imagee win,int lvl,Background *b,player *p,enemy e[],SDL_Surface *ecran,int *maxcount,int *pausee,int posenemies[],inputenemy *I)
{
if((b->scroll.x>=3850)&&(lvl!=3))
{
SDL_BlitSurface(win.img, NULL, ecran,&win.pos);
SDL_Flip(ecran);
SDL_Delay(2000);
lvl++;
init_input_enemy(&(*I)) ;
*b=initBack(*b,lvl);
init_enemies(e,lvl,posenemies);
p->x=80;
*maxcount=1;
game(ecran);
ecran = SDL_SetVideoMode(1300,600,32,SDL_HWSURFACE|SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
}
else if((b->scroll.x>=3550)&&(lvl==3))
{
SDL_BlitSurface(win.img, NULL, ecran,&win.pos);
SDL_Flip(ecran);
SDL_Delay(2000);
game(ecran);
ecran = SDL_SetVideoMode(1300,600,32,SDL_HWSURFACE|SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
*pausee=1;
}
return lvl ;
}

void appel_enigme(int *viee,int *occ_enigme,int *enigme,int *score,int *maxcount,txt *txt_scoree,txt *txt_viee,player *perso,Background *b,enemy e[],imagee lose,int *restart,SDL_Surface *ecran,image background_enigme,image temps[],image vict,image def)
{int i=0;
srand(time(NULL));
 *occ_enigme=1+rand() %2 ;

if(*viee==0)
      {
        
          do
           { 
            if(*occ_enigme ==1)
            *enigme=enigme_image(ecran,background_enigme,temps,vict,def);
            else
            *enigme=enigme_txtt(ecran);
           }   
          while ((*enigme!=1)&&(*enigme!=0));
            if(*enigme==1)
             {if(b->scroll.x>1200)
              {
               for(i=0;i<5;i++)
                e[i].pos.x+=400; 
                
                perso->x-=500;
                b->scroll.x-=500;
              }
               else 
              {
              for(i=0;i<5;i++)
              e[i].pos.x+=300;
               }
                *score += 10 ;
                *viee=3;
                *maxcount=0;
                init_txt_vie(&(*txt_viee),*viee);
                init_txt_score(&(*txt_scoree),*score);
             }
            else 
            {
            SDL_BlitSurface(lose.img, NULL, ecran,&lose.pos);
            SDL_Flip(ecran);
             SDL_Delay(2000);
            *restart=1;
            }
          }

}

void restart_the_mission(int *viee,int *score,int *maxcount,txt *txt_scoree,txt *txt_viee,player *perso,Background *b,enemy e[],int *restart,int lvl,int posenemies[],inputenemy *I)
{
if(*restart==1)
          {
          perso->x=80;
	  perso->y=190;
          b->scroll.x=0;
          init_input_enemy(&(*I)) ;
          init_enemies(e,lvl,posenemies);
          *restart=0;
          *viee=3;
          *score=0;
          *maxcount=0;
          init_txt_vie(&(*txt_viee),*viee);
          init_txt_score(&(*txt_scoree),*score);
          }
}


void appel_pause(int *pausee,int *restartt,SDL_Surface *ecran,player perso,Background b,int lvl,int viee,int score,enemy e[],int num_perso,imagee background_pause,imagee resume,imagee resumeo,imagee restart,imagee restarto,imagee saveandquit,imagee saveandquito)
{
 if(*pausee==1)
          {
          pause(ecran,&(*restartt),perso,b,lvl,viee,score,e,num_perso,background_pause,resume,resumeo,restart,restarto,saveandquit,saveandquito);
          *pausee=0;
          }
}


void save(int a,char *nom_fich)
 {
   FILE *f ;
   f=fopen(nom_fich,"w");
if (f!=NULL)
{
  fprintf(f,"%d;\n",a);
  fclose(f);
}
else
    printf ("error \n");
 }

void save_game(player perso,Background b,int lvl,int viee,int score,enemy e[],int num_perso)
{
char *ch_perso="save/perso.txt",*ch_background="save/background.txt",*ch_lvl="save/lvl.txt",*ch_vie="save/vie.txt",*ch_score="save/score.txt",*ch_enemy0="save/enemy0.txt",*ch_enemy1="save/enemy1.txt",*ch_enemy2="save/enemy2.txt",*ch_num_perso="save/num_perso.txt";
save(perso.x,ch_perso);
save(b.scroll.x,ch_background);
save(lvl,ch_lvl);
save(viee,ch_vie);
save(score,ch_score);
save(e[0].pos.x,ch_enemy0);
save(e[1].pos.x,ch_enemy1);
save(e[2].pos.x,ch_enemy2);
save(num_perso,ch_num_perso);
}

void load(int *l,char *nom_fich)
 {int i=0;
     char c,ch[90];
   FILE *f ;
   f=fopen(nom_fich,"r");
if (f!=NULL)
{
  while((c=fgetc(f))!=EOF)
  {
   ch[i]=c;
   if(ch[i]==';')
       ch[i]='\0';
   
    i++;
  }
  sscanf(ch,"%d",&(*l));
  fclose(f);
}
else
    printf ("error \n");
 }

