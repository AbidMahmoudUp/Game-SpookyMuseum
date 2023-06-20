#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "jeu.h"

struct image
{
SDL_Rect pos;
SDL_Surface * img ;
};
typedef struct image image ;
//------------------------------------------------
struct text
{
SDL_Rect pos;
SDL_Surface *t ;
TTF_Font *p;

};
typedef struct text text ;
//--------------------------------------------------------------------------------
struct music
{
Mix_Music *m;
};
typedef struct music music;
//-----------------------------------------------------------------------------------
struct son
{
Mix_Chunk *s;
};
typedef struct son son;
//-----------------------------------------------------------------------------------
void init_txt(text *txt);
void afficher_text(text txt,SDL_Surface *ecran);
void init_song(music *music );
void init_son(son *son );
void initstart(image *start);
void initloado(image *loado);
void initload(image *load);
void initcredito(image *credito);
void initcredit(image *credit);
void initsetting(image *setting);
void initexit(image *exit);
void initstarto(image *starto);
void initsettingso(image *settingso);
void initexito(image *exito);
void initanime(image Menu_anime[],char anime[]);
void initanimef(image Menu_anime[]);
void initanime2(image Menu_anime[]);
void initanime2f(image Menu_anime[]);
void afficher(image p,SDL_Surface *ecran);
void afficher_anime(image p[],SDL_Surface *ecran,char anime[],int i);
void liberer(SDL_Surface *p);
void liberer_all(SDL_Surface *ecran,text txt,image start,image setting,image exit,image starto,image settingso,image exito,image Menu_anime[],image backgroundv2,image c[],image variable[],image barre1,image barre2,image fullscreeno,image fullscreen,image normalo,image normal);
void afficher_intro(image intro_anime[],SDL_Surface *ecran,char intro[],int i);
void initintro(image intro_anime[],char intro[]);
//////////////settings//////////////////////////
void settings(SDL_Surface *ecran,Mix_Music *music,int volumeactuel,Mix_Chunk *son,int *volumeson,int i,int j,image Menu_anime2[],image Menu_anime2f[],image c[],image variable[],image barre1,image barre2,image fullscreen,image fullscreeno,image normal,image normalo,int *resolution);
void initbackground(image *background);
void initbackgroundv2(image *background);
void initmusic_sound(image c[],image variable[]);
void init_barre1_barre2(image *barre1,image *barre2,int volumeactuel,int volumeson,int *i,int *j  );
void initfullscreen(image *fullscreen);
void initfullscreeno(image *fullscreeno);
void initnormal(image *normal);
void initnormalo(image *normalo);
///////////load_game////////////////////////////
void init_loading(image Menu_anime[]);
/////////////niveau/////////////////////////////
void init_lvl1(image *load);
void init_lvl1o(image *load);
void initbackground_difficulty(image *background);
void afficher_credit(image intro_anime[],SDL_Surface *ecran,char intro[],int i);
void appcredit(SDL_Surface *ecran,image credit_tab[],int i,image background,int done,char credit[],image intro_credit[],Mix_Chunk *son );
void inittab_credit(image c[]);
void initcreditanime(image credit_anime[],char anime[]);
void init_songcredit(music *music);
void init_soncredit(son *son );

///////////mode///////////////////////////////:
void init_cinematique(image Menu_anime[],char anime[]);
void initsolo(image *solo);
void initduo(image *duo);
void initsoloo(image *soloo);
void initduoo(image *duoo);
//soloplayer
void init_p1_p2(image p1[],image p2[]);
