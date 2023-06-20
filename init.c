#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "jeu.h"
#include "image.h"
#include "player.h"
void init_choose(image *p1)
{

 p1[0].img=IMG_Load("background/AAAA.png");  
 	p1[0].pos.x=45;
	p1[0].pos.y=45; 
}
void init_p1_p2(image p1[],image p2[])
{
char anime[40];
 sprintf(anime,"Animationpersonage/1.png");
 p1[0].img=IMG_Load(anime);  
 	p1[0].pos.x=300;
	p1[0].pos.y=200; 
sprintf(anime,"Animationpersonage/1o.png");
 p1[1].img=IMG_Load(anime);  
 	p1[1].pos.x=300;
	p1[1].pos.y=200;

 sprintf(anime,"Animationpersonage/2.png");
 p2[0].img=IMG_Load(anime);  
 	p2[0].pos.x=600;
	p2[0].pos.y=200; 
sprintf(anime,"Animationpersonage/2o.png");
 p2[1].img=IMG_Load(anime);  
 	p2[1].pos.x=600;
	p2[1].pos.y=200;
	 			
}
void init_loading(image Menu_anime[])
{
char anime[40];
int i;
for (i=2 ;i<=40; i++)
{
//loading menu principale
 sprintf(anime,"loading/%d.png",i);
 Menu_anime[i].img=IMG_Load(anime);  
 	Menu_anime[i].pos.x=0;
	Menu_anime[i].pos.y=0; 
	 			
}//end loading menu principale
}

void init_cinematique(image Menu_anime[],char anime[])
{int i;
for (i=1 ;i<=690; i++)
{
//loading menu principale
 sprintf(anime,"cinematique/%d.png",i);
 Menu_anime[i].img=IMG_Load(anime);  
 	Menu_anime[i].pos.x=0;
	Menu_anime[i].pos.y=0; 
	 			
}//end loading menu principale
}
//-----------------------------------------------------------------------------------
void active_music(music *musicc)
{	
	Mix_PlayMusic(musicc->m,1);
}
void active_son(son *sonn)
{	
	Mix_PlayChannel(-1,sonn->s,1);
}

//-----------------------------------------------------------------------------------
void init_txt(text *txt)
{
	// POSITION de txt
	txt->pos.x=210;
	txt->pos.y=70;
	TTF_Init();
	
	
	SDL_Color couleur={255,128,0};
	
	
	//initialisation de couleur de txt 
	//chargement d'une police et initisation de la taille 
	txt->p=TTF_OpenFont("text/game.ttf",60);
	
	txt->t=TTF_RenderText_Blended(txt->p,"Spooky Museum",couleur);
	// bliter la surface de txt

	 //fermer la police 
	 TTF_CloseFont (txt->p);
	 //arreter sdl_ttf
	 TTF_Quit();
}
//-----------------------------------------------------------------------------------
void init_song(music *music)
{
	 ////song 
	 if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
	 {
	   printf("%s",Mix_GetError());
	 }
	 
	 //load music 
	 music->m=Mix_LoadMUS("ghna/musicc.mp3");
}
//-----------------------------------------------------------------------------------
void init_songcredit(music *music)
{
	 ////song 
	 if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
	 {
	   printf("%s",Mix_GetError());
	 }
	 
	 //load music 
	 music->m=Mix_LoadMUS("ghna/credit.mp3");
}
//-----------------------------------------------------------------------------------
void init_son(son *son )
{
son->s=Mix_LoadWAV("ghna/effet.wav");
}
//-----------------------------------------------------------------------------------
void init_soncredit(son *son )
{
son->s=Mix_LoadWAV("ghna/credit.wav");
}
//-----------------------------------------------------------------------------------
void initcredit(image *credit)
{
credit->img = IMG_Load("boutons/credit.png");
credit->pos.x=13;
credit->pos.y=400;
}

//-----------------------------------------------------------------------------------
void initcredito(image *credito)
{
credito->img = IMG_Load("boutons/credito.png");
credito->pos.x=13;
credito->pos.y=400;
}
//-----------------------------------------------------------------------------------
void initload(image *load)
{
load->img = IMG_Load("boutons/load.png");
load->pos.x=13;
load->pos.y=200;
}
//-----------------------------------------------------------------------------------
void initloado(image *loado)
{
loado->img = IMG_Load("boutons/loado.png");
loado->pos.x=13;
loado->pos.y=200;
}
//-----------------------------------------------------------------------------------
void initstart(image *start)
{
start->img = IMG_Load("boutons/start.png");
start->pos.x=13;
start->pos.y=100;
}
//-----------------------------------------------------------------------------------
void initsetting(image *setting)
{
setting->img= IMG_Load("boutons/setings.png");
setting->pos.x=13;
setting->pos.y=300;
}
//-----------------------------------------------------------------------------------
void initexit(image *exit)
{
exit->img= IMG_Load("boutons/exit.png");
exit->pos.x=13;
exit->pos.y=500;
}
//-----------------------------------------------------------------------------------
void initstarto(image *starto)
{
starto->img = IMG_Load("boutons/starto.png");
starto->pos.x=13;
starto->pos.y=100;
}
//-----------------------------------------------------------------------------------
void initsettingso(image *settingso)
{
settingso->img= IMG_Load("boutons/setingso.png");
settingso->pos.x=13;
settingso->pos.y=300;
}
//-----------------------------------------------------------------------------------
void initexito(image *exito)
{
exito->img= IMG_Load("boutons/exito.png");
exito->pos.x=13;
exito->pos.y=500;
}

//--------------------------------------------------------
void inittab_credit(image c[])
{	 c[0].img=IMG_Load("credit/credit.jpg");
	 c[1].img=IMG_Load("credit/credit1.jpg");
 	 c[2].img=IMG_Load("credit/credit2.jpg");
 	 c[3].img=IMG_Load("credit/credit3.jpg");
 	 c[4].img=IMG_Load("credit/credit4.jpg");
 	 c[5].img=IMG_Load("credit/credit5.jpg");
 	 c[6].img=IMG_Load("credit/credit6.jpg");
 	
}


//-----------------------------------------------------------------------------------
void initanime(image Menu_anime[],char anime[])
{int i;
for (i=0 ;i<=90; i++)
{
//loading menu principale
 sprintf(anime,"anime/%d.png",i);
 Menu_anime[i].img=IMG_Load(anime);  
 	Menu_anime[i].pos.x=0;
	Menu_anime[i].pos.y=0; 
	 			
}//end loading menu principale
}
void initanimef(image Menu_anime[])
{int i;
char anime[18];
for (i=0 ;i<=92; i++)
{
//loading menu principale
 sprintf(anime,"animef/%d.png",i);
 Menu_anime[i].img=IMG_Load(anime);  
 	Menu_anime[i].pos.x=0;
	Menu_anime[i].pos.y=0; 
	 			
}//end loading menu principale
}
//-----------------------------------------------------------------------------------
void initanime2(image Menu_anime[])
{int i;
char anime[18];
for (i=0 ;i<=35; i++)
{
//loading menu principale
 sprintf(anime,"anime2/%d.png",i);
 Menu_anime[i].img=IMG_Load(anime);  
 	Menu_anime[i].pos.x=0;
	Menu_anime[i].pos.y=0; 
	 			
}//end loading menu principale
}
void initanime2f(image Menu_anime[])
{int i;
char anime[18];
for (i=0 ;i<=35; i++)
{
//loading menu principale
 sprintf(anime,"anime2f/%d.png",i);
 Menu_anime[i].img=IMG_Load(anime);  
 	Menu_anime[i].pos.x=0;
	Menu_anime[i].pos.y=0; 
	 			
}//end loading menu principale
}

//-----------------------------------------------------------------------------------
void initcreditanime(image credit_anime[],char anime[])
{int i;
for (i=0;i<8;i++)
{
//loading menu principale
 sprintf(anime,"credit/%d.jpg",i);
 credit_anime[i].img=IMG_Load(anime);  
 	credit_anime[i].pos.x=0;
	credit_anime[i].pos.y=0; 
	 			
}//end loading menu principale
}

//-----------------------------------------------------------------------------------
void initintro(image intro_anime[],char intro[])
{int i;
for (i=0 ;i<177; i++)
{
//loading menu principale
 sprintf(intro,"intro/%d.png",i);
 intro_anime[i].img=IMG_Load(intro);  
 	intro_anime[i].pos.x=0;
	intro_anime[i].pos.y=0; 
	 			
}//end loading menu principale
}
//-----------------------------------------------------------------------------------
void afficher(image p,SDL_Surface *ecran)
{
SDL_BlitSurface(p.img, NULL, ecran,&p.pos);
}
//-----------------------------------------------------------------------------------
void afficher_text(text txt,SDL_Surface *ecran)
{
SDL_BlitSurface(txt.t, NULL, ecran,&txt.pos);

}

//-----------------------------------------------------------------------------------


void afficher_anime(image Menu_anime[],SDL_Surface *ecran,char anime[],int i)
{
sprintf(anime,"anime/%d.png",i);
SDL_BlitSurface(Menu_anime[i].img,NULL,ecran,&Menu_anime[i].pos);

}
//-----------------------------------------------------------------------------------
void afficher_intro(image intro_anime[],SDL_Surface *ecran,char intro[],int i)
{
sprintf(intro,"intro/%d.png",i);
SDL_BlitSurface(intro_anime[i].img,NULL,ecran,&intro_anime[i].pos);

}
//-----------------------------------------------------------------------------------
void afficher_credit(image intro_anime[],SDL_Surface *ecran,char intro[],int i)
{
sprintf(intro,"credit/%d.png",i);
SDL_BlitSurface(intro_anime[i].img,NULL,ecran,&intro_anime[i].pos);

}
//-----------------------------------------------------------------------------------
void liberer(SDL_Surface *p)
{

SDL_FreeSurface(p);
}
//-----------------------------------------------------------------------------------
void liberer_all(SDL_Surface *ecran,text txt,image start,image setting,image exit,image starto,image settingso,image exito,image Menu_anime[],image backgroundv2,image c[],image variable[],image barre1,image barre2,image fullscreeno,image fullscreen,image normalo,image normal)
{int i=0;
liberer(ecran);
liberer(txt.t);
liberer(start.img);
liberer(setting.img);
liberer(exit.img);
liberer(starto.img);
liberer(settingso.img);
liberer(exito.img);
for (i=0;i<90;i++)
   {
   liberer(Menu_anime[i].img);
   }
liberer(backgroundv2.img);
for (i=0;i<4;i++)
   {
   liberer(c[i].img);
   }
for (i=0;i<4;i++)
   {
   liberer(variable[i].img);
   }   
liberer(barre1.img);
liberer(barre2.img);
liberer(fullscreeno.img);
liberer(fullscreen.img);
liberer(normalo.img);   
liberer(normal.img);  

}
////////////////////////////////SETTINGS/////////////////////////////////////////////
void initbackgroundv2(image *background)
{
background->img = IMG_Load("background/back.png");
background->pos.x=0;
background->pos.y=0;
}
void initmusic_sound(image c[],image variable[])
{
	 c[0].img=IMG_Load("Music/music1.png");
 	 c[1].img=IMG_Load("Music/music2.png");
 	 c[2].img=IMG_Load("Music/music3.png");
 	 c[3].img=IMG_Load("Music/music4.png");
 	 c[4].img=IMG_Load("Music/music5.png");
 	 c[5].img=IMG_Load("Music/music5.png");
 	 fflush(stdin);
 	 variable[0].img=IMG_Load("sound/sound1.png");
  	 variable[1].img=IMG_Load("sound/sound2.png");
 	 variable[2].img=IMG_Load("sound/sound3.png");
 	 variable[3].img=IMG_Load("sound/sound4.png");
 	 variable[4].img=IMG_Load("sound/sound5.png");
}
void initfullscreen(image *fullscreen)
{
	fullscreen->img=IMG_Load("boutons/fullscreen.png");
	fullscreen->pos.x=100;
	fullscreen->pos.y=25;
}
void initfullscreeno(image *fullscreeno)
{
	fullscreeno->img=IMG_Load("boutons/fullscreeno.png");
	fullscreeno->pos.x=100;
	fullscreeno->pos.y=25;
}

void initnormal(image *normal)
{
normal->img= IMG_Load("boutons/normal.png");
	normal->pos.x=100;
	normal->pos.y=160;

}
void initnormalo(image *normalo)
{
normalo->img= IMG_Load("boutons/normalo.png");
	normalo->pos.x=100;
	normalo->pos.y=160;

}

void init_barre1_barre2(image *barre1,image *barre2,int volumeactuel,int volumeson,int *i,int *j )
{        
 	 ///SET THE  sound volume  according to the previous volume 
 	 switch(volumeactuel){
 	 case 0:
 	 *i=0;
 	 barre1->img=IMG_Load("Music/music1.png");
 	 break;
 	 case 25:
 	 *i=1;
 	 barre1->img=IMG_Load("Music/music2.png");
 	 break;
 	 case 60:
 	 *i=2;
 	 barre1->img=IMG_Load("Music/music3.png");
 	 break;
 	 case 100:
 	 *i=3;
 	 barre1->img=IMG_Load("Music/music4.png");
 	 break;
 	 case 128:
 	 *i=4;
 	 barre1->img=IMG_Load("Music/music5.png");
 	 break;
 	}
 	
 	
 	///////SET THE  sound volume  according to the previous volume 
 	 switch(volumeson){
 	 case 0:
 	 *j=0;
 	 barre2->img=IMG_Load("sound/sound1.png");
 	 break;
 	 case 25:
 	 *j=1;
 	 barre2->img=IMG_Load("sound/sound2.png");
 	 break;
 	 case 60:
 	 *j=2;
 	 barre2->img=IMG_Load("sound/sound3.png");
 	 break;
 	 case 100:
 	 *j=3;
 	 barre2->img=IMG_Load("sound/sound4.png");
 	 break;
 	 case 128:
 	 *j=4;
 	 barre2->img=IMG_Load("sound/sound5.png");
 	 break;
 	}

     	 barre1->pos.x=100;
	 barre1->pos.y=300;
	 
	 barre2->pos.x=100;
	 barre2->pos.y=400;

}
///////////////////////////difficulty/////////////////////////////
void init_lvl1(image *load)
{
load->img = IMG_Load("background/1.png");
load->pos.x=0;
load->pos.y=0;
}
void init_lvl1o(image *load)
{
load->img = IMG_Load("background/1o.png");
load->pos.x=0;
load->pos.y=0;
}
/////////////////////////////////mode////////////////////////////
void initsolo(image *solo)
{
solo->img=IMG_Load("boutons/p1.png");
	solo->pos.x=13;
	solo->pos.y=45;

}

void initduo(image *duo)
{
duo->img=IMG_Load("boutons/p2.png");
	duo->pos.x=13;
	duo->pos.y=300;	
}
void initsoloo(image *soloo)
{
soloo->img=IMG_Load("boutons/p1o.png");
	soloo->pos.x=13;
	soloo->pos.y=45;

}

void initduoo(image *duoo)
{
duoo->img=IMG_Load("boutons/p2o.png");
	duoo->pos.x=13;
	duoo->pos.y=300;	
}

