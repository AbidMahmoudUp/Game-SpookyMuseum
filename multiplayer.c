#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include"player.h"
#include "jeu.h" 
#include "enemy.h"
#include "enigme.h"
void multiplayer(SDL_Surface *ecran)
{	int continuer=1,updated=0;	
	Input in;
	player perso1,perso2;
	Background b;
	SDL_Event event;
//-----------------------INIT----------------
	init_player1(&perso1);
	init_player2(&perso2);
	b=initBack(b,1);
		while(continuer)
		{	SDL_BlitSurface(b.imgBack1,&(b.scroll), ecran,NULL);
			afficherPerso(&perso1,ecran);
			afficherPerso(&perso2,ecran);
			getInputForTwo(&in);
			deplacerPerso1(&perso1,&in);
			deplacer_player2(&perso2,&in);
			animerPerso(&perso1,ecran);
			animerPerso(&perso2,ecran);
			SDL_Flip(ecran);
		}
}
