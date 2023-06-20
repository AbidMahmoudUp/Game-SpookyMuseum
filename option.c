#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "jeu.h"
#include "image.h"
void settings(SDL_Surface *ecran,Mix_Music *music,int volumeactuel,Mix_Chunk *son,int *volumeson,int i,int j,image Menu_anime2[],image Menu_anime2f[],image c[],image variable[],image barre1,image barre2,image fullscreen,image fullscreeno,image normal,image normalo,int *resolution) 
{//declaration  des variables;
	SDL_Event event;
	int continuer=1,curseur,cursor,playson=1,k=1; 	 
//la boucle infinie !!
	while(continuer)
	{	// laffichage du arriere plan sur l ecran !!
	            if(k==35)
             {
             k=1;
             }
             afficher(Menu_anime2f[k],ecran);
               k++;
	 if(*resolution==1)
                {
	       ecran =SDL_SetVideoMode(1300,600,32,SDL_HWSURFACE| SDL_DOUBLEBUF);
		afficher(Menu_anime2f[k],ecran);
               k++;
		}
	 else if(*resolution==0)
	 {
	 ecran =SDL_SetVideoMode(800,600,32,SDL_HWSURFACE| SDL_DOUBLEBUF);
	 afficher(Menu_anime2[k],ecran);
                 k++;
	 }
	 else 
	 {
	 ecran =SDL_SetVideoMode(1300,600,32,SDL_HWSURFACE| SDL_DOUBLEBUF);
		afficher(Menu_anime2f[k],ecran);
                 k++;
	 }	
                SDL_Delay(100);	
	        afficher(fullscreen,ecran);
	        afficher(normal,ecran);
	        afficher(barre1,ecran);
	        afficher(barre2,ecran);
	       
		
		switch(cursor)
            	{	
            	        case 1:
			afficher(fullscreeno,ecran);
            		break;
            		case 2:
            		afficher(normalo,ecran);
            		break;

    
            	}
            	  if( playson==1)
            	{
            	  Mix_PlayChannel(-1,son,0);
            	  playson=0;
            	}
		barre1.img=c[i].img;
	        afficher(barre1,ecran);
	        
	        barre2.img=variable[j].img;
		afficher(barre2,ecran);
		while (SDL_PollEvent(&event)){
		switch(event.type)
		{	
			case SDL_QUIT: // assure la sortie de la fonction
			continuer=0;
			break;
			
			case SDL_KEYDOWN:// on va utulise le clavier !!
			switch(event.key.keysym.sym){
			playson=1;
			case SDLK_ESCAPE:
			 Mix_PlayChannel(-1,son,0);
			continuer=0;
			break;
			case SDLK_f: 
			*resolution=1;
			break;
			case SDLK_n: 
			*resolution=0;
			break;
			case SDLK_UP:
			 playson=1;
			if(i<4)
			{	
				i++;
			}	
			else if(i>=4)
			{	
				i=4;
			}	
				
						
			break;
			case SDLK_DOWN:
			 playson=1;
			if(i==0)
			{	//afficher(barre1,ecran);		
	
			}
			if(i>0)
			{	
			  i--;
			  break;
			}
			break;
			case SDLK_RIGHT:
			 playson=1;
			if(j<4)
			{	
				j++;
			}
		
			break;
			case SDLK_LEFT:
			playson=1;
			if(j==0)
			{	//afficher(barre2,ecran);
			}
			if(j>0)
			{	j--;	
			
				break;
			}
			break;
		}
		
	case SDL_MOUSEMOTION :
if((event.motion.x>350 )&&(event.motion.x<460)&&(event.motion.y>20)&&(event.motion.y<120))
            	{//affiche starto.png lorsque la souris est a la position de start.png
                       curseur=1;         
                       cursor=1;}                       
 else if((event.motion.x>350 )&&(event.motion.x<460)&&(event.motion.y>150)&&(event.motion.y<240))
              {//affiche settingso.png lorsque la souris est a la position de setting.png
                       curseur=2;         
                       cursor=2;
              }              
else
{       
cursor=0;
}                       
         break;              
       case SDL_MOUSEBUTTONUP:
        
            if(event.button.button==SDL_BUTTON_LEFT)
            	{ 
            	playson=1;
            	switch(curseur)
            	{	case 1:
            	       *resolution=1;
            		break;
            		case 2:
            		*resolution=0;
            		break;
            	}	
            	} 
            	}
	/////////set the music volume 	
	 switch(i){
	 case 0:
	 Mix_VolumeMusic(0);
	 break;
	  case 1:
	 Mix_VolumeMusic(25);
	 break;
	  case 2:
	 Mix_VolumeMusic(60);
	 break;
	  case 3:
	 Mix_VolumeMusic(100);
	 break;
	  case 4:
	 Mix_VolumeMusic(128);
	 break;
	 }
	 
	 ////////set the sound volume 
	  switch(j){
	 case 0:
	 Mix_VolumeChunk(son,0);
	 *volumeson=Mix_VolumeChunk(son,0);
	 break;
	  case 1:
	 Mix_VolumeChunk(son,25);
	 *volumeson=Mix_VolumeChunk(son,25);
	 break;
	  case 2:
	 Mix_VolumeChunk(son,60);
	 *volumeson=Mix_VolumeChunk(son,25);
	 break;
	  case 3:
	 Mix_VolumeChunk(son,100);
	 *volumeson=Mix_VolumeChunk(son,100);
	 break;
	  case 4:
	 Mix_VolumeChunk(son,128);
	 *volumeson=Mix_VolumeChunk(son,128);
	 break;
	 }
	 
	 
	       
	 }
	 SDL_Flip(ecran);
	}
	SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
	}
