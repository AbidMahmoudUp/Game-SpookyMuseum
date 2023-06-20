#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#define LARGEUR_ECRAN 1366
#define HAUTEUR_ECRAN 663
#define LARGEUR_JOUEUR 113
#define HAUTEUR_JOUEUR 200
#include"player.h"
void initeverything();
void menu(SDL_Surface *ecran);








#endif
