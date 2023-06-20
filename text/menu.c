#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "jeu.h"
#include "image.h"

	void menu(SDL_Surface *ecran){
	text txt;
	//construct Mix_music pointer 
	 Mix_Music *music ;
	 Mix_Chunk *son ;
	//declaration image de menu principal
	image start,setting,exit,starto,settingso,exito,Menu_anime[300] ;
	//declaration image settings
	image background,backgroundv2,c[10],variable[10],barre1,barre2,fullscreeno,fullscreen,normalo,normal,credit,credito,load,loado ;
	//declaration image difficulty
	image easy,medium,hard,easyo,mediumo,hardo;
	//declaration images mode (solo ou duo) 
	
	
	SDL_Event event;	
	int continuer=3,curseur=0,volumeactuel=60,volumeson=60,i=2,cursor=0,set=0,niveauu=0;
	int playson=0,k=0,j=2,creditt,loadd,resolution;
	char anime[300];
	SDL_Rect postxt;
	
	
	init_song(&music);	 
	 //play music 
	Mix_PlayMusic(music,1);
	init_son(&son);
	init_txt(&txt);
	initstart(&start);
	initcredit(&credit);
	initcredito(&credito);
	initload(&load);
	initloado(&loado);
	initsetting(&setting);
	initexit(&exit);
	initstarto(&starto);
	initsettingso(&settingso);
	initexito(&exito);
	initanime(Menu_anime,anime);
	           initbackground(&background);
                  initbackgroundv2(&backgroundv2);
	          initeasy(&easy);
	          initmedium(&medium);
	          inithard(&hard);
	          initeasyo(&easyo);
	          initmediumo(&mediumo);
	          inithardo(&hardo);
	////chargement des images des fonctions

	                          

	
//la boucle infinie !!	
	while(continuer){
				if (k>90)
				{
				//inisialisation of image menu principale
				k=1;
				}
					
				    afficher_anime(Menu_anime,ecran,anime,k);
				    SDL_Delay(80);
				    k++;
				    afficher(setting,ecran);
	                            afficher(start,ecran);
	                            afficher(exit,ecran); 
	                            afficher(credit,ecran);
	                            afficher(load,ecran);
				    
				    
				    
				    
				    switch(cursor)
            	{	
            	        case 1:
            	        
			 afficher(starto,ecran);
            		break;
            		case 2:
            		afficher(loado,ecran);
            		break;
            		case 3:
            		 afficher(settingso,ecran);
            		break;
            		case 4:
            		afficher(credito,ecran);
            		break;
            		case 5:
            		afficher(exito,ecran);
			break;
            	}	
            	if( playson==1)
            	{
            	  Mix_PlayChannel(-1,son,0);
            	  playson=0;
            	}
            	
            	else if(niveauu==1)
            	{ ///load images

            	  niveau(ecran,background,backgroundv2,easy,medium,hard,easyo,mediumo,hardo,resolution);
            	  niveauu=0;
            	}
		
		else if(set==1)
		{
			settings(ecran,music,volumeactuel,son,&volumeson,i,j,background,backgroundv2,c,variable,barre1,barre2,fullscreen,fullscreeno,normal,normalo,&resolution);
            	 volumeactuel=Mix_VolumeMusic(-1);
            	 set=0;
		}		     		
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	while (SDL_PollEvent(&event)){
	switch(event.type){
		case SDL_QUIT:
		continuer=0;
			break;
          case SDL_KEYDOWN:
          playson=1;
	 switch(event.key.keysym.sym){
case SDLK_p:
curseur=1;
continuer=3;	
break;
case SDLK_s:
curseur=2;
continuer=3;	
break;
case SDLK_ESCAPE:
continuer=0;	
break;


}
case SDL_MOUSEMOTION :
		 if((event.motion.x>13 )&&(event.motion.x<213)&&(event.motion.y>100)&&(event.motion.y<166))
            	{//affiche starto.png lorsque la souris est a la position de start.png
                       curseur=1;         
                       cursor=1;
                } 

else if((event.motion.x>13 )&&(event.motion.x<213)&&(event.motion.y>200)&&(event.motion.y<266))
              {//affiche loado.png lorsque la souris est a la position de exit.png
            		curseur=2;         
                       cursor=2;
              }
else if((event.motion.x>13 )&&(event.motion.x<213)&&(event.motion.y>300)&&(event.motion.y<366))
              {//affiche settingso.png lorsque la souris est a la position de setting.png
                       curseur=3;         
                       cursor=3;
              }        
else if((event.motion.x>13 )&&(event.motion.x<213)&&(event.motion.y>400)&&(event.motion.y<466))
              {//affiche settingso.png lorsque la souris est a la position de exit.png
            		curseur=4;         
                       cursor=4;
              }
              
else if((event.motion.x>13 )&&(event.motion.x<213)&&(event.motion.y>500)&&(event.motion.y<566))
              {//affiche settingso.png lorsque la souris est a la position de exit.png
            		curseur=5;         
                       cursor=5;
              }     
else{       
cursor=0;
}
break;                       
                       
       case SDL_MOUSEBUTTONUP:
        
            if(event.button.button==SDL_BUTTON_LEFT)
            	{ 
            	
            	switch(curseur)
            	{	case 1:
            	        playson=1;
            		niveauu=1;
            		break;
            		case 2:
            		playson=1;
            		break;
            		case 3:
            		playson=1;
            		set=1;
            		break;
            		case 4:
            		playson=1;
            		break;
            		case 5:
            		playson=1;
            		continuer=0;
            		break;
            	}	
            	}           	
            		
	
}
}
//afficher_text(txt,ecran);	
SDL_Flip(ecran);

} 
          //LIBÉRATION de music
	 Mix_FreeMusic(music);
	//close every thing
	liberer_all(ecran,txt,start,setting,exit,starto,settingso,exito,Menu_anime,background,backgroundv2,c,variable,barre1,barre2,fullscreeno,fullscreen,normalo,normal);      
	SDL_Quit();
	
	
	}
	
	
	
