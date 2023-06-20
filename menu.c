#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "jeu.h"
#include "image.h"
#include "player.h"
#include "enemy.h"

void menu(SDL_Surface *ecran){
 image background_enigme,temps[90],vict,def;
  loading_all(&background_enigme,&vict,&def);
  loading_temps(temps);
  image choose;
  init_choose(&choose);
 imagee background_pause,resume,resumeo,restart,restarto,saveandquit,saveandquito;
  init_background_pause(&background_pause);
 init_resume_pause(&resume);
 init_resumeo_pause(&resumeo);
 init_restart_pause(&restart);
 init_restarto_pause(&restarto);
 init_saveandquit_pause(&saveandquit);
 init_saveandquito_pause(&saveandquito);
        image p1[2],p2[2];
        init_p1_p2(p1,p2);
        txt txt_scoree,txt_viee;
        init_txt_score(&txt_scoree,0);
        init_txt_vie(&txt_viee,3);
        enemy e[8];
        int posenemies[4]={1000,1200,1000};
        init_enemies(e,1,posenemies);
        player perso,vie,coin;
 	text txt;
         init_player(&perso,80,1);
         init_vie(&vie);
         init_coin(&coin); 
	//construct Mix_music pointer 
	 Mix_Music *music , *music1;
	 Mix_Chunk *son ,*son1;
	//declaration image de menu principal
	image start,setting,exit,starto,settingso,exito,Menu_anime[300],Menu_animef[95],Menu_anime2[95],Menu_anime2f[95],intro_anime[300] ;
	//declaration image settings
	image backgroundv2,c[10],variable[10],barre1,barre2,fullscreeno,fullscreen,normalo,normal,credit,credito,load,loado ;
	//declaration image difficulty
	image back,backo;
	//declaration images mode (solo ou duo) 
	image creditbackground ,credit_tab[9],anime_credit[10];
	 image cinematique[700] ;
          char anime1[35] ;
        //declaration load game 
         image background,loading[40];
         imagee win,lose; 
         Background b;
         b=initBack(b,1);
         image soloo,duoo,solo,duo;
         initsolo(&solo);
         initduo(&duo);
         initsoloo(&soloo);
         initduoo(&duoo);
   
 
         init_cinematique(cinematique,anime1);  
	
	SDL_Event event;	
	int continuer=3,curseur=0,volumeactuel=60,volumeson=60,i=2,cursor=0,set=0,niveauu=0;
	int playson=0,k=0,j=2,creditt,loadd,resolution=1,p=1,verif=0,q=0,loadgame=0;
	char anime[300],intro[300],animecredit[10];
	SDL_Rect postxt;
	init_soncredit(&son1);
	init_songcredit(&music1);
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
	//initintro(intro_anime,intro);
	initexit(&exit);
	initstarto(&starto);
	initsettingso(&settingso);
	initexito(&exito);
	initanime(Menu_anime,anime);
        initanimef(Menu_animef);
        initanime2(Menu_anime2);
        initanime2f(Menu_anime2f);
        initbackgroundv2(&backgroundv2);
        init_barre1_barre2(&barre1,&barre2,volumeactuel,volumeson,&i,&j);
        initmusic_sound(c,variable);
        initfullscreen(&fullscreen);
        initfullscreeno(&fullscreeno);
        initnormal(&normal);
        initnormalo(&normalo);
        initcreditanime(anime_credit,animecredit);
        inittab_credit(credit_tab);
         init_lvl1(&back);
         init_lvl1o(&backo);
	////chargement des images des fonctions
//init images
init_loading(loading);
initbackgroundv2(&background);      
init_win_lvl(&win);
init_lose_lvl(&lose);	
						
	                          

	
//la boucle infinie !!	
	while(continuer){
				if (verif==0)
				{ //afficher_intro(intro_anime,ecran,intro,p);
				p++;
				SDL_Delay(50);
				}
				if(p==177)
				{	verif=1;
				}
				if(verif==1)
				{
				if (k>90)
				{
				//inisialisation of image menu principale
				k=1;
				}
					
				    if(resolution==1)
                                  {ecran =SDL_SetVideoMode(1300,600,32,SDL_HWSURFACE| SDL_DOUBLEBUF);	
				   afficher(Menu_animef[k],ecran);
				    SDL_Delay(80);
				    k++;
                                  }
                                else if(resolution==0)
                                    {
                                    ecran =SDL_SetVideoMode(800,600,32,SDL_HWSURFACE| SDL_DOUBLEBUF);
                                    afficher(Menu_anime[k],ecran);
				    SDL_Delay(80);
				    k++;
                                    }
                                 else 
                                  {
                                   ecran =SDL_SetVideoMode(1300,600,32,SDL_HWSURFACE| SDL_DOUBLEBUF);
                                   afficher(Menu_animef[k],ecran);
				    SDL_Delay(80);
				    k++;

                                  }
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

            	  niveau(ecran,back,backo,cinematique,win,lose,solo,duo,soloo,duoo,b,background,perso,vie,coin,e,txt_scoree,txt_viee,p1,p2,background_pause,resume,resumeo,restart,restarto,saveandquit,saveandquito,choose,background_enigme,temps,vict,def);
            	  niveauu=0;
            	}
		
		else if(set==1)
		{
	settings(ecran,music,volumeactuel,son,&volumeson,i,j,Menu_anime2,Menu_anime2f,c,variable,barre1,barre2,fullscreen,fullscreeno,normal,normalo,&resolution);
            	 volumeactuel=Mix_VolumeMusic(-1);
            	 set=0;
		}
		else if (creditt==1)
		{	
			Mix_PlayMusic(music1,1);
			appcredit(ecran,credit_tab,q,creditbackground,continuer,animecredit,anime_credit,son1);
			creditt=0;
			Mix_PlayMusic(music,1);				
		}		     		
               else if(loadgame==1)
            	{ ///load game

            	 load_the_game(background,loading,win,lose,ecran,perso,vie,coin,e,txt_scoree,txt_viee);
            	  loadgame=0;
            	}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	while (SDL_PollEvent(&event)){
	switch(event.type){
		case SDL_QUIT:
		continuer=0;
			break;
          case SDL_KEYDOWN:
          
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
                       
       case SDL_MOUSEBUTTONDOWN:
        
            if(event.button.button==SDL_BUTTON_LEFT)
            	{ 
            	
            	switch(curseur)
            	{	case 1:
            	        playson=1;
            		niveauu=1;
            		break;
            		case 2:
            		playson=1;
                        loadgame=1;
            		break;
            		case 3:
            		playson=1;
            		set=1;
            		break;
            		case 4:
            		playson=1;
            		creditt=1;
            		break;
            		case 5:
            		playson=1;
            		continuer=0;
            		break;
            	}	
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
	liberer_all(ecran,txt,start,setting,exit,starto,settingso,exito,Menu_anime,backgroundv2,c,variable,barre1,barre2,fullscreeno,fullscreen,normalo,normal);      
	SDL_Quit();
	
	
	}
	
	
	
