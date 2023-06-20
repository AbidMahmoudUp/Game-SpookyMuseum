/**
* @file enigme.h
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "image.h"
/**
* @struct enigme
* @brief struct for the enigme.

*/

//------------------------------------------------
struct enigme
{
image photo1,photo2,photo2o,photo3,photo3o,photo4,photo4o;/*!< images {surface et position} de l'enigme.*/
int resultat ;/*!< resultat de l'enigme.*/
};
typedef struct enigme enigme;

void choose_file_randomly(int *fich_numero,char fichier[]);
image loading_background(image load);
void  loading_temps(image load[]);
image loading_vict(image load);
image loading_def(image load);
void loading_all(image *background,image *vict,image *def);
void afficher_image(image p,SDL_Surface *ecran);
void init_images_enigme(image *im,image *imo,char file[],char fich[],char c);
enigme loading_enigme(char file[],int num_fichier);
void afficher_enigme(enigme e,SDL_Surface *ecran);
void animer(image clock[],int i,SDL_Surface *ecran);
int result(enigme e,image vict,image def,int defo,int vecto,SDL_Surface *ecran);
void after_result(int resultat,int *continuer);
void liberer_les_images(enigme e,image background,image temps[],image vict,image def);
int enigme_image(SDL_Surface *ecran,image background,image temps[],image vict,image def);








