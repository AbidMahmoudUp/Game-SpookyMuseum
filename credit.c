#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "jeu.h"
#include "image.h"
void appcredit(SDL_Surface *ecran,image credit_tab[],int i,image background,int done,char credit[9],image intro_credit[9],Mix_Chunk *son1 )
{	int j=1,verif=0;
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
	SDL_Event event;
	init_soncredit(&son1);
	while(done)
	{		if (verif==0)
				{ afficher_credit(intro_credit,ecran,credit,j);
				j++;
				SDL_Delay(1000);
				}
				if(j==8)
				{	verif=1;
				}
		if(verif==1){
		background.img=credit_tab[i].img;
		afficher(background,ecran);
			if(i==0)
			{	afficher(background,ecran);
			}
                        	
		SDL_WaitEvent(&event);
		switch(event.type)
		{
		case SDL_QUIT:
			done=0;
			break;

		case SDL_KEYDOWN:
			switch(event.key.keysym.sym)
			{ 
			case SDLK_ESCAPE:
			done=0;
			break;
			case SDLK_RIGHT:
				Mix_PlayChannel(-1,son1,0);
				if(i<7)
			{	
				i++;
					
			
			}
                       else if(i>=7)
                           i=7;
			break;
			case SDLK_LEFT:
			Mix_PlayChannel(-1,son1,0);
			if(i>0)
			{	i--;	
				
			
				break;
			}
			}
			}
			}
		SDL_Flip(ecran);	
	}
	
}
