p:main.o menu.o init.o mode.o jeu.o difficulty.o option.o credit.o donnee.o pause.o enemy.o loading_files.o enigme.o loading_files_txt.o enigme_txt.o loadgame.o multiplayer.o donnee2.o soloplayer.o xo.o
	gcc main.o menu.o init.o mode.o jeu.o difficulty.o option.o credit.o donnee.o pause.o enemy.o loading_files.o enigme.o loading_files_txt.o enigme_txt.o loadgame.o multiplayer.o donnee2.o soloplayer.o xo.o -o p -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g

main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g

jeu.o:jeu.c
	gcc -c jeu.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g

init.o:init.c
	gcc -c init.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g

difficulty.o:difficulty.c
	gcc -c difficulty.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
	
mode.o:mode.c
	gcc -c mode.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
	
menu.o:menu.c
	gcc -c menu.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g

option.o:option.c
	gcc -c option.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
credit.o:credit.c
	gcc -c credit.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g

donnee.o:donnee.c
	gcc -c donnee.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g

pause.o:pause.c
	gcc -c pause.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
enemy.o:enemy.c
	gcc -c enemy.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
enigme.o:enigme.c
	gcc -c enigme.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
loading_files.o:loading_files.c
	gcc -c loading_files.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
loading_files_txt.o:loading_files_txt.c
	gcc -c loading_files_txt.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
enigme_txt.o:enigme_txt.c
	gcc -c enigme_txt.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
loadgame.o:loadgame.c
	gcc -c loadgame.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
donnee2.o:donnee2.c
	gcc -c donnee2.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
multiplayer.o:multiplayer.c
	gcc -c multiplayer.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
soloplayer.o:soloplayer.c
	gcc -c soloplayer.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
xo.o:xo.c
	gcc -c xo.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g

