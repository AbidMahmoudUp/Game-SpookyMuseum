/**
* @file enemy.h
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

#include"player.h"
/**
* @struct enemy
* @brief struct for the enemy

*/
struct enemy 
{
SDL_Rect pos;/*!<  position de l'enemy.*/
imagee gauche[15],attack[15],droite[15] ; /*!< images {surface et position} de l'enemy.*/
};
typedef struct enemy enemy ;

struct inputenemy 
{
int attack[4],deplacer[4],afficher[4],run[4];/*!< l'etat de l'enemy.*/
};
typedef struct inputenemy inputenemy ;

void init_enemy(enemy *e,int pos_x,int num);
void init_enemies(enemy e[],int lvl,int posenemies[]);
void init_input_enemy(inputenemy *I);
void get_input_enemy(inputenemy *I,Background b,enemy e[],int etat_perso);
void deplacer_enemy(enemy *e);
void deplacer_enemies(enemy e[],int lvl,inputenemy I);
void afficher_enemy (imagee p,SDL_Surface *ecran);
void annimer_enemy(enemy e,int *j,SDL_Surface *ecran,int num,int etat_attack,int etat_run);
void annimer_enemies(enemy e[],int lvl,int *j,SDL_Surface *ecran,inputenemy I);
int collision_enemy_perso(player perso, enemy e);
int collision_enemies(player perso, enemy e[]);






















int move_to_the_next_lvl(imagee win,int lvl,Background *b,player *p,enemy e[],SDL_Surface *ecran,int *maxcount,int *pausee,int posenemies[],inputenemy *I);
void restart_the_mission(int *viee,int *score,int *maxcount,txt *txt_scoree,txt *txt_viee,player *perso,Background *b,enemy e[],int *restart,int lvl,int posenemies[],inputenemy *I);
void save(int a,char *nom_fich);
void save_game(player perso,Background b,int lvl,int viee,int score,enemy e[],int num_perso);


