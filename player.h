/**
* @file player.h
*/
#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "jeu.h"
#define JUMP           4 
#define REPOS          3
#define RIGHT          2
#define LEFT           1
#define GRAVITY_SPEED  4
#define JUMP_HAUTEUR   13
#define MAX_FALL_SPEED 400
#define AXE_X		15
#define ATTACK_RIGHT   1
#define ATTACK_LEFT    2
#define WALK_RIGHT     2 
#define WALK_LEFT      1 
#define JUMP_RIGHT     4
#define JUMP_LEFT      5
#define IDLE           3 
#define SPEED          5
#define INIT           8
/**
* @struct player
* @brief struct for the player.

*/
struct player
{	SDL_Surface *sprite; /*!< surface du personage.*/
	int x,y; /*!< les cordonner du personage.*/
	int w,h; /*!< la largeur et la hauteur du personage .*/
	SDL_Surface *vie; /*!< surface de l icone de vie.*/
	SDL_Rect posvie; /*!< les cordoner de l image de vie.*/
	SDL_Rect pos;	/*!< les cordoner de l image de score.*/
	SDL_Surface *score;  /*!< surface de l icone de score.*/
	int etat,direction,onGround; /*!< des variable pour tester les sens et l etat*/
	float v_x ,v_grav, v_saut,v_y ;/*!< des variable pour les vecteur x et y et la gravite pour le saut*/
	int frameNumber,jump,frameTimer;/*!< des compteurs pour l animation*/
	double acceleration , vitesse ;/*!< des variable pour acceleration */
	
};
/**
* @struct imagee
* @brief struct for the background.

*/
struct imagee
{
SDL_Rect pos; /*!< les cordonner du background .*/
SDL_Surface * img ;/*!< surface de l image du background .*/
};
typedef struct imagee imagee ;

typedef struct player player;
/**
* @struct txt
* @brief struct for the text.

*/
struct txt
{
SDL_Rect pos; /*!< cordonner du text .*/
SDL_Surface *t ;/*!< surface du text .*/
TTF_Font *p;/*!< la font du text .*/

};
typedef struct txt txt ;
/**
* @struct Input
* @brief struct for the input.

*/
struct Input
{	int left,right,up,down,jump,resume,speed,attack;/*!< des variables pour l input du player 1  .*/
	int left1,right1,up1,down1,jump1,resume1,speed1; /*!< des variables pour l input du player 2  .*/

};
typedef struct Input Input;





typedef struct
{
  SDL_Surface *imgBack1;
  SDL_Rect posBack1;  
  SDL_Rect scroll;
} Background;

Background initBack(Background b,int lvl);
void afficherBack(Background b, SDL_Surface *ecran);
void scrollingBack(Background *b, player *p, Input I,int *updated);
//------------------------------------------------------------------
#define END_RIGHT 1609
#define END_LEFT  0
//------------------------------------------------------------------
void init_txt_score(txt *txt,int score);
void init_txt_vie(txt *txt,int vie);
void afficher_txt(txt t,SDL_Surface *ecran);
void getInput(Input *input,int *pause);
void deplacerPerso(player *perso , Input *in,Background *b,int *updated,Uint32 dt,int num_perso);
void sauter (player *perso);
void afficherPerso(player *perso , SDL_Surface *ecran);
void animerPerso(player *perso , SDL_Surface *ecran);
void init_player(player *perso,int posperso,int num_perso);
void delay(unsigned int frameLimit);
extern void changeAnimation(player *entity, char *name);
void init_vie(player *vie);
void afficher_vie(player vie , SDL_Surface *ecran);
void colision (player *perso);
void init_coin(player *coin);
void init_background_pause(imagee *background);
void init_resume_pause(imagee *resume);
void init_resumeo_pause(imagee *resume);
void init_restart_pause(imagee *resume);
void init_restarto_pause(imagee *resume);
void init_saveandquit_pause(imagee *resume);
void init_saveandquito_pause(imagee *resume);
void afficher_pause(imagee p,SDL_Surface *ecran);
void init_win_lvl(imagee *load);
void init_lose_lvl(imagee *load);
void afficherTous(player *perso ,player vie, player coin ,SDL_Surface *ecran , Background b,txt txt_scoree,txt txt_viee);
//------------------------PARTIE MULTIPLAYER---------------------------
void getInputForTwo(Input *input);
void init_player2(player *perso);
void deplacer_player2(player *perso,Input *in);
void deplacerPerso1(player *perso , Input *in);
void init_player1(player *perso);
void load(int *l,char *nom_fich);
#endif
















