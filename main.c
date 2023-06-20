#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "jeu.h"
#include "image.h"
#include "player.h"

SDL_Surface *ecran;




int main(void)
{initeverything();
menu(ecran); 

return 0;
}


void initeverything()
{
SDL_Init(SDL_INIT_EVERYTHING);
SDL_WM_SetIcon(IMG_Load("icone.png") , NULL);
ecran = SDL_SetVideoMode(1300,600,32,SDL_HWSURFACE|SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
SDL_WM_SetCaption("Spooky Museum",NULL);

} 

