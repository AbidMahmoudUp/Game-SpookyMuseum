#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
struct imageee
{
SDL_Rect pos;
SDL_Surface *img ;
};
typedef struct imageee imageee ;
//------------------------------------------------
struct TEXT
{
SDL_Rect pos;
SDL_Surface *t ;
TTF_Font *p;
};
typedef struct TEXT TEXT ;
//------------------------------------------------
struct enigme_txt
{
TEXT question,reponse1,reponse1o,reponse2,reponse2o,reponse3,reponse3o;
int resultat ;
};
typedef struct enigme_txt enigme_txt;


imageee loading_background_txt(imageee load);
void  loading_temps_txt(imageee load[]);
imageee loading_vict_txt(imageee load);
imageee loading_def_txt(imageee load);
void loading_all_txt(imageee *background,imageee *vict,imageee *def);//initialiser images

void afficher_img_txt(imageee p,SDL_Surface *ecran);//afficher image

void afficher_txt_enigme(TEXT p,SDL_Surface *ecran);///afficher txt

void init_question_txt(TEXT *txt,char ch[]);//initialisation text question

void init_reponse_txt(TEXT *txt,char ch[],int x,int num_reponse);//initialisation text reponse

enigme_txt loading_enigme_txt(int num_fichier);//init enigme

void afficher_enigme_txt(enigme_txt e,SDL_Surface *ecran);//afficher enigme

void animer_txt(imageee clock[],int i,SDL_Surface *ecran);//animation de temps 

int result_txt(enigme_txt e,imageee vict,imageee def,int defo,int vecto,SDL_Surface *ecran);//resultat (win or lose)
void after_result_txt(int resultat,int *continuer);//
void liberer_les_images_txt(enigme_txt e,imageee background,imageee temps[],imageee vict,imageee def);//liberer tous les images 
int enigme_txtt(SDL_Surface *ecran);//fonction principale








