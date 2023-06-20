#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "jeu.h"
void getInputForTwo(Input *input)
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
                        exit(0);
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
		     case SDLK_LALT:
                    	input->speed = 1;
                    break;
                    case SDLK_d:
                    	input->right1=1;
                    break;
                    case SDLK_q:
                    	input->left1=1;
                    break;
                    case SDLK_s:
                    	input->down1=1;
                    break;
                    case SDLK_z:
                    	input->up1=1;
                    break;  
                    case SDLK_a:
                    	input->speed1=1;
                    break;
                    case SDLK_e:
                    	input->jump1=1;
                    break;                                      
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
                    case SDLK_d:
                    	input->right1=0;
                    break;
                    case SDLK_q:
                    	input->left1=0;
                    break;
                    case SDLK_s:
                    	input->down1=0;
                    break;
                    case SDLK_z:
                    	input->up1=0;
                    break;  
                    case SDLK_a:
                    	input->speed1=0;
                    break;
                    case SDLK_e:
                    	input->jump1=0;
                    break;
                    default:
                    break;
                }
            break;
        }
    }
void init_player2(player *perso)
{		
	perso->sprite=IMG_Load("Animationpersonage/right.png");
	perso->x=300;
	perso->y=400;
	perso->w=LARGEUR_JOUEUR;
	perso->h=HAUTEUR_JOUEUR;
	perso->direction=0;
	perso->etat=REPOS;
	perso->frameNumber=0;
	perso->frameTimer=INIT;
	perso->v_x=4;
	perso->v_grav=0.3;
	perso->v_saut=-6.5;
	perso->v_y=perso->v_saut;
	perso->onGround=1;
	
} 
void deplacer_player2(player *perso,Input *in)
{
	int pos_courante, verif=0;
	colision(perso);
	if(in->up1==1)
	{	perso->y -=SPEED;
		if(perso->y<0)
 		{
 			perso->y=0;
 		}
 		
	}
	else if (in->down1==1)
	{	perso->y +=SPEED;
		if(perso->y+HAUTEUR_JOUEUR>HAUTEUR_ECRAN)
 		{
 			perso->y=HAUTEUR_ECRAN-HAUTEUR_JOUEUR;
 		}
		
	}
	
	 if(in->left1==1)
	{	perso->x -=SPEED;
		perso->direction=LEFT;
		if(perso->x<0)
		{
			perso->x=0;
		}
		if(perso->etat != WALK_LEFT)
		{	perso->etat=WALK_LEFT;
			changeAnimation(perso,"Animationpersonage/backwards.png");
			//perso->sprite=IMG_Load("Animationpersonage/backwards.png");
			//perso->frameNumber=0;	
		}
		
		
	
		
	}
	else if(in->right1==1)
	{
		perso->x +=SPEED;
		perso->direction=RIGHT;
		if(perso->x+LARGEUR_JOUEUR>=LARGEUR_ECRAN)
 		{	perso->x=LARGEUR_ECRAN-LARGEUR_JOUEUR;
 		}
 		
 		
 		
		if(perso->etat != WALK_RIGHT)
		{	perso->etat=WALK_RIGHT;
			changeAnimation(perso,"Animationpersonage/forward.png");
			//perso->sprite=IMG_Load("Animationpersonage/forward.png");
			//perso->frameNumber=0;
		}


	}
	
	else if ((in->right1==0)&&(in->left1==0)&&(in->jump1==0))
	{	if(perso->etat!=IDLE)
		{
			perso->etat=IDLE;
			if(perso->direction==LEFT)
			{
				changeAnimation(perso,"Animationpersonage/left.png");
				//perso->sprite=IMG_Load("Animationpersonage/left.png");
				//perso->frameNumber=0;
				
			}
			else 
			{
				changeAnimation(perso,"Animationpersonage/right.png");
				//perso->sprite=IMG_Load("Animationpersonage/right.png");
				//perso->frameNumber=0;
			}
		}
		
		
	}
	 if (in->jump1==1)
	{	
		perso->y -=JUMP_HAUTEUR;	
		pos_courante=perso->y -JUMP_HAUTEUR;
		
		if((perso->direction==RIGHT)&&(perso->etat != JUMP_RIGHT))
		{	perso->etat=JUMP_RIGHT;
			changeAnimation(perso,"Animationpersonage/JumpRight.png");
		}	
		else if ((perso->direction==LEFT)&&(perso->etat != JUMP_LEFT))
		{	perso->etat=JUMP_LEFT;
			changeAnimation(perso,"Animationpersonage/JumpLeft.png");
		}	
	}
	perso->y+=GRAVITY_SPEED;
	if((perso->y<MAX_FALL_SPEED) &&(perso->direction==RIGHT) )
	{	perso->x+=perso->v_x;
		perso->v_y+=GRAVITY_SPEED; 
	}
	else if((perso->y<MAX_FALL_SPEED) &&(perso->direction==LEFT) )
	{	perso->x-=perso->v_x;
		perso->v_y+=GRAVITY_SPEED; 
	}	
	if(perso->y>=MAX_FALL_SPEED)
	{
		perso->y=MAX_FALL_SPEED;
	}
	if((in->speed1==1)&&(in->right1==1))
	{
		perso->x +=SPEED+2;
		perso->direction=RIGHT;
		if(perso->x+LARGEUR_JOUEUR>=LARGEUR_ECRAN)
 		{	perso->x=LARGEUR_ECRAN-LARGEUR_JOUEUR;
 		}
		if(perso->etat != WALK_RIGHT)
		{	perso->etat=WALK_RIGHT;
			changeAnimation(perso,"Animationpersonage/forward.png");
			//perso->sprite=IMG_Load("Animationpersonage/forward.png");
			//perso->frameNumber=0;
		}
	}
	else if ((in->speed1==1)&&(in->left1==1))
	{	perso->x -=SPEED-2;
		perso->direction=LEFT;
		if(perso->x<0)
		{
			perso->x=0;
		}
		if(perso->etat != WALK_LEFT)
		{	perso->etat=WALK_LEFT;
			changeAnimation(perso,"Animationpersonage/backwards.png");
			//perso->sprite=IMG_Load("Animationpersonage/backwards.png");
			//perso->frameNumber=0;	
		}
	}
	
} 
void init_player1(player *perso)
{		
	perso->sprite=IMG_Load("Animationpersonage/right.png");
	perso->x=80;
	perso->y=400;
	perso->w=LARGEUR_JOUEUR;
	perso->h=HAUTEUR_JOUEUR;
	perso->direction=0;
	perso->etat=REPOS;
	perso->frameNumber=0;
	perso->frameTimer=INIT;
	perso->v_x=4;
	perso->v_grav=0.3;
	perso->v_saut=-6.5;
	perso->v_y=perso->v_saut;
	perso->onGround=1;
	
}
void deplacerPerso1(player *perso , Input *in)
{	
	int pos_courante, verif=0;
	colision(perso);
	if(in->up==1)
	{	perso->y -=SPEED;
		if(perso->y<0)
 		{
 			perso->y=0;
 		}
 		
	}
	else if (in->down==1)
	{	perso->y +=SPEED;
		if(perso->y+HAUTEUR_JOUEUR>HAUTEUR_ECRAN)
 		{
 			perso->y=HAUTEUR_ECRAN-HAUTEUR_JOUEUR;
 		}
		
	}
	
	 if(in->left==1)
	{	perso->x -=SPEED;
		perso->direction=LEFT;
		if(perso->x<0)
		{
			perso->x=0;
		}
		if(perso->etat != WALK_LEFT)
		{	perso->etat=WALK_LEFT;
			changeAnimation(perso,"Animationpersonage/backwards.png");
			//perso->sprite=IMG_Load("Animationpersonage/backwards.png");
			//perso->frameNumber=0;	
		}
		
		
	
		
	}
	else if(in->right==1)
	{
		perso->x +=SPEED;
		perso->direction=RIGHT;
		if(perso->x+LARGEUR_JOUEUR>=LARGEUR_ECRAN)
 		{	perso->x=LARGEUR_ECRAN-LARGEUR_JOUEUR;
 		}
 		
 		
 		
		if(perso->etat != WALK_RIGHT)
		{	perso->etat=WALK_RIGHT;
			changeAnimation(perso,"Animationpersonage/forward.png");
			//perso->sprite=IMG_Load("Animationpersonage/forward.png");
			//perso->frameNumber=0;
		}


	}
	
	else if ((in->right==0)&&(in->left==0)&&(in->jump==0))
	{	if(perso->etat!=IDLE)
		{
			perso->etat=IDLE;
			if(perso->direction==LEFT)
			{
				changeAnimation(perso,"Animationpersonage/left.png");
				//perso->sprite=IMG_Load("Animationpersonage/left.png");
				//perso->frameNumber=0;
				
			}
			else 
			{
				changeAnimation(perso,"Animationpersonage/right.png");
				//perso->sprite=IMG_Load("Animationpersonage/right.png");
				//perso->frameNumber=0;
			}
		}
		
		
	}
	 if (in->jump==1)
	{	
		perso->y -=JUMP_HAUTEUR;	
		pos_courante=perso->y -JUMP_HAUTEUR;
		
		if((perso->direction==RIGHT)&&(perso->etat != JUMP_RIGHT))
		{	perso->etat=JUMP_RIGHT;
			changeAnimation(perso,"Animationpersonage/JumpRight.png");
		}	
		else if ((perso->direction==LEFT)&&(perso->etat != JUMP_LEFT))
		{	perso->etat=JUMP_LEFT;
			changeAnimation(perso,"Animationpersonage/JumpLeft.png");
		}	
	}
	perso->y+=GRAVITY_SPEED;
	if((perso->y<MAX_FALL_SPEED) &&(perso->direction==RIGHT) )
	{	perso->x+=perso->v_x;
		perso->v_y+=GRAVITY_SPEED; 
	}
	else if((perso->y<MAX_FALL_SPEED) &&(perso->direction==LEFT) )
	{	perso->x-=perso->v_x;
		perso->v_y+=GRAVITY_SPEED; 
	}	
	if(perso->y>=MAX_FALL_SPEED)
	{
		perso->y=MAX_FALL_SPEED;
	}
	if((in->speed==1)&&(in->right==1))
	{
		perso->x +=SPEED+2;
		perso->direction=RIGHT;
		if(perso->x+LARGEUR_JOUEUR>=LARGEUR_ECRAN)
 		{	perso->x=LARGEUR_ECRAN-LARGEUR_JOUEUR;
 		}
		if(perso->etat != WALK_RIGHT)
		{	perso->etat=WALK_RIGHT;
			changeAnimation(perso,"Animationpersonage/forward.png");
			//perso->sprite=IMG_Load("Animationpersonage/forward.png");
			//perso->frameNumber=0;
		}
	}
	else if ((in->speed==1)&&(in->left==1))
	{	perso->x -=SPEED-2;
		perso->direction=LEFT;
		if(perso->x<0)
		{
			perso->x=0;
		}
		if(perso->etat != WALK_LEFT)
		{	perso->etat=WALK_LEFT;
			changeAnimation(perso,"Animationpersonage/backwards.png");
			//perso->sprite=IMG_Load("Animationpersonage/backwards.png");
			//perso->frameNumber=0;	
		}
	}
	
}

