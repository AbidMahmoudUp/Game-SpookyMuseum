#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "enigme_txt.h"


void loading_temps_txt(imageee load[])
{
char file[30];
int i;
for (i=1 ;i<=65; i++)
{
 sprintf(file,"temps_txt/%d.png",i);
load[i].img = IMG_Load(file);
load[i].pos.x=510;
load[i].pos.y=145;	 			
}
}

imageee loading_background_txt(imageee load)
{
load.img = IMG_Load("images_txt/back.png");
load.pos.x=0;
load.pos.y=0;
return load;
}

imageee loading_vict_txt(imageee load)
{
load.img = IMG_Load("images_txt/vict.png");
load.pos.x=0;
load.pos.y=0;

return load;
}

imageee loading_def_txt(imageee load)
{
load.img = IMG_Load("images_txt/def.png");
load.pos.x=0;
load.pos.y=0;

return load;
}

void loading_all_txt(imageee *background,imageee *vict,imageee *def)
{
*background=loading_background_txt(*background);
*vict=loading_vict_txt(*vict);
*def=loading_def_txt(*def);
}
void afficher_img_txt(imageee p,SDL_Surface *ecran)
{
SDL_BlitSurface(p.img, NULL, ecran,&p.pos);

}
void afficher_txt_enigme(TEXT p,SDL_Surface *ecran)
{
SDL_BlitSurface(p.t, NULL, ecran,&p.pos);

}
void init_question_txt(TEXT *txt,char ch[])
{
	// POSITION de txt
	txt->pos.x=35;
	txt->pos.y=45;
	TTF_Init();
	
	
	SDL_Color couleur={128,128,0};
	
	
	//initialisation de couleur de txt 
	//chargement d'une police et initisation de la taille 
	txt->p=TTF_OpenFont("text_txt/game.ttf",30);
	
	txt->t=TTF_RenderText_Blended(txt->p,ch,couleur);
	// bliter la surface de txt

	 //fermer la police 
	 TTF_CloseFont (txt->p);
	 //arreter sdl_ttf
	 TTF_Quit();
}


void init_rep1_txt(TEXT *txt,char ch[],int x,int num_reponse)
{
	// POSITION de txt
       if(num_reponse==1)
        {
	txt->pos.x=35;
	txt->pos.y=200;
        }
       if(num_reponse==2)
        {
	txt->pos.x=35;
	txt->pos.y=300;
        }
       if(num_reponse==3)
        {
	txt->pos.x=35;
	txt->pos.y=400;
        }
	TTF_Init();
	
	
	SDL_Color couleur;
	if(x==1)
         {
        couleur.r=128 ;
        couleur.g=128 ;
        couleur.b=0;
          }
        else if(x==2)
          {
        couleur.r=255 ;
        couleur.g=128 ;
        couleur.b=0;
          }
	
	//initialisation de couleur de txt 
	//chargement d'une police et initisation de la taille 
	txt->p=TTF_OpenFont("text_txt/game.ttf",30);
	
	txt->t=TTF_RenderText_Blended(txt->p,ch,couleur);
	// bliter la surface de txt

	 //fermer la police 
	 TTF_CloseFont (txt->p);
	 //arreter sdl_ttf
	 TTF_Quit();
}

enigme_txt loading_enigme_txt(int num_fichier)
  { 
    enigme_txt e;
    ///initialisation question 
    int i1=0;
    char ch1[30],c1,quest[50];
    sprintf(ch1,"question_txt/%d/question.txt",num_fichier);
    FILE* question=fopen(ch1,"r+");
      while((c1=fgetc(question))!=EOF)
        {
         quest[i1]=c1 ;
          if(quest[i1]==':')
          {
             i1++;
             quest[i1]='\0';
          } 
             i1++;
        }
       init_question_txt(&e.question,quest);
    ////////
    ////initialisation reponse 1
    int i2=0 ;
    char ch2[30],c2,rep1[10];
    sprintf(ch2,"question_txt/%d/reponse1.txt",num_fichier);
    FILE* reponse1=fopen(ch2,"r+");
      while((c2=fgetc(reponse1))!=EOF)
        {
         rep1[i2]=c2 ;
          if(rep1[i2]==';')
             rep1[i2]='\0';
           i2++;
        }
       init_rep1_txt(&e.reponse1,rep1,1,1);
       init_rep1_txt(&e.reponse1o,rep1,2,1);
    //
    ////initialisation reponse 2
     int i3=0 ;
    char ch3[30],c3,rep2[10];
    sprintf(ch3,"question_txt/%d/reponse2.txt",num_fichier);
    FILE* reponse2=fopen(ch3,"r+");
     while((c3=fgetc(reponse2))!=EOF)
        {
         rep2[i3]=c3 ;
         if(rep2[i3]==';')
             rep2[i3]='\0';
           i3++;
        }
  
     init_rep1_txt(&e.reponse2,rep2,1,2);
       init_rep1_txt(&e.reponse2o,rep2,2,2);
   //



   ////initialisation reponse 3
   int i4=0 ;
    char ch4[30],c4,rep3[10];
    sprintf(ch4,"question_txt/%d/reponse3.txt",num_fichier);
    FILE* reponse3=fopen(ch4,"r+");
    while((c4=fgetc(reponse3))!=EOF)
        {
         rep3[i4]=c4 ;
        if(rep3[i4]==';')
             rep3[i4]='\0';

           i4++;
        }
      init_rep1_txt(&e.reponse3,rep3,1,3);
       init_rep1_txt(&e.reponse3o,rep3,2,3);
   //
////initialisation resultat
   int i5=0 ;
    char ch5[30],c5;
    sprintf(ch5,"question_txt/%d/resultat.txt",num_fichier);
    FILE* result=fopen(ch5,"r+");
    while((c5=fgetc(result))!=EOF)
    {   if(i5==0){
         switch(c5)
       {
       case '1':
        e.resultat=1 ;
        break;
       case '2':
        e.resultat=2 ;
        break;
       case '3':
        e.resultat=3 ;
        break;
        }}
     i5++;
    }

  return e;
  }

void afficher_enigme_txt(enigme_txt e,SDL_Surface *ecran)
{
afficher_txt_enigme(e.question,ecran);
afficher_txt_enigme(e.reponse1,ecran);
afficher_txt_enigme(e.reponse2,ecran);
afficher_txt_enigme(e.reponse3,ecran);
}


void animer_txt(imageee clock[],int i,SDL_Surface *ecran)
{
 afficher_img_txt(clock[i],ecran);
 

} 


int result_txt(enigme_txt e,imageee vict,imageee def,int defo,int victo,SDL_Surface *ecran)
{
int resultat;
if (victo==1)
  {
                 
     afficher_img_txt(vict,ecran);
     switch(e.resultat)    
  	{	
           case 1:
   		afficher_txt_enigme(e.reponse1o,ecran);
           break;
 	   case 2:
                 afficher_txt_enigme(e.reponse2o,ecran);
           break;
           case 3:
               	 afficher_txt_enigme(e.reponse3o,ecran);
       	   break;
        }
                 
      resultat=1;
  }
   
   if(defo==1)
     {
        afficher_img_txt(def,ecran);
        switch(e.resultat)
            {	
              case 1:
            	afficher_txt_enigme(e.reponse1o,ecran);
      	      break;
       	      case 2:
            	 afficher_txt_enigme(e.reponse2o,ecran);
     	      break;
              case 3:
             	afficher_txt_enigme(e.reponse3o,ecran);
       	      break;
                   
            }
                 
       resultat=0;
     
    }    


return resultat;
}



void after_result_txt(int resultat,int *continuer)
{
if(resultat==1)
     {
          SDL_Delay(3000);
          *continuer=0;
     }
if(resultat==0)
     {
          SDL_Delay(3000); 
          *continuer=0;
     }
}

void liberer_les_images_txt(enigme_txt e,imageee background,imageee temps[],imageee vict,imageee def)
{int i;

               SDL_FreeSurface(background.img);
               SDL_FreeSurface(vict.img);
               SDL_FreeSurface(def.img);

               for (i=1;i<66;i++)
                 {
                 SDL_FreeSurface(temps[i].img);
                 }
               
                 SDL_FreeSurface(e.question.t);
                 SDL_FreeSurface(e.reponse1.t);
                 SDL_FreeSurface(e.reponse2.t); 
                 SDL_FreeSurface(e.reponse3.t);
                 
                 SDL_FreeSurface(e.reponse1o.t);
                 SDL_FreeSurface(e.reponse2o.t); 
                 SDL_FreeSurface(e.reponse3o.t);
}





















