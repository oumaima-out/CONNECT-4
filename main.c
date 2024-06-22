#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>//TXT
#define TAILLE 10



#include "variable.h"
#include "ia.h"
#include "fonction.h"
#include "verif.h"
#include "surface.h"
#include "menu.h"
#include "affiche.h"
#include "init.h"


int main(int argc, char *argv[]){
    //INITIALISATION DES POSITIONS DES SCORE + differentes ecriture
    pos_ecriture.x=30;
    pos_ecriture.y=10;
    pos_score.x=120;
    pos_score.y=360;

    //INITIALISATION DE LA SDL (ecran +police)
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    TTF_Init();
    police = TTF_OpenFont("police.ttf", 25);
    ecran = SDL_SetVideoMode(400, 400, 32, SDL_SWSURFACE | SDL_DOUBLEBUF| SDL_RESIZABLE | SDL_FULLSCREEN); /* Double Buffering */
    SDL_WM_SetCaption("Puissance 4", NULL);


    //ACTIVE TOUTES LES SURFACES
    surface();
    //On demande le pseudo du joueur
    speudo(PSEUDO);
    //LANCEMENT DU MENU
    if (!arret)menu();
    //On lance le choix du pseudo si on choisi de jouer a 2 !!
    if (choix_player==0 && !arret && continuer==0)speudo(PSEUDO2);

    //LANCEMENT DU JEU
    if (continuer!=3){
        do{
            while(fin==0&&arret!=1){
            init();
            }
            if(fin==1&&arret!=1){
                SDL_Delay(3000);
                verif_plein=0;
            }
            fin=0;
        }while (arret!=1);
    }

    //QUITTE LA SDL ET LIBERE LES SURFACES
    TTF_CloseFont(police);
    TTF_Quit();
    freesurface();
    SDL_Quit();

    return EXIT_SUCCESS;
}
