#ifndef _XO_H_
#define _XO_H_
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>

typedef struct
{
SDL_Surface *table;
SDL_Surface *bg;
SDL_Surface *t[2];
int i[3][3];
SDL_Rect r[3][3];
int turn;
int choixx;
int choixy;
}xo;

int game(SDL_Surface *screen);


#endif
