void affiche_menu(int p){
            /* Gestion des positions , et des affichages*/
            SDL_BlitSurface(fond_menu, NULL, ecran, NULL);
            pos.x=240;
            pos.y=300;
            pos_menu.x=160;
            pos_menu.y=100;
            sprintf(CHOIX, "2 Joueurs");
            texte = TTF_RenderText_Blended(police, CHOIX, couBlanc);
            SDL_BlitSurface(texte, NULL, ecran, &pos_menu);
            pos_menu.x=160;
            pos_menu.y=180;
            sprintf(CHOIX, "IA");
            texte = TTF_RenderText_Blended(police, CHOIX, couBlanc);
            SDL_BlitSurface(texte, NULL, ecran, &pos_menu);
            pos_menu.x=160;
            pos_menu.y=260;
            sprintf(CHOIX, "Charger partie");
            texte = TTF_RenderText_Blended(police, CHOIX, couBlanc);
            SDL_BlitSurface(texte, NULL, ecran, &pos_menu);


        //CHOIX JOUEUR

        if(p==0){
            choix_menu.x=100;
            choix_menu.y=100;
        }
        else if (p==1){
            choix_menu.x=100;
            choix_menu.y=180;
            pos.x=240;
            pos.y=180;
            sprintf(PSEUDO2, "IA");
            sprintf(LOAD, "Niveau : %d",choix_ia);
            texte = TTF_RenderText_Blended(police, LOAD, couBlanc);
            SDL_BlitSurface(texte, NULL, ecran, &pos);
        }
        else {
            pos.x=240;
            pos.y=300;
            choix_menu.x=100;
            choix_menu.y=260;
            sprintf(LOAD, "%d",choix_sauvegarde);
            texte = TTF_RenderText_Blended(police, LOAD, couBlanc);
            SDL_BlitSurface(texte, NULL, ecran, &pos);
            /* Cast pour le chargement int --> char*/
            char buf=(char)(((int)'0')+choix_sauvegarde);
            load(t,buf);
        }

        SDL_BlitSurface(jaune, NULL, ecran, &choix_menu);
        SDL_Flip(ecran);


}
/*Gestion evenementielle pour le  menu*/
void menu(){
    SDL_EnableKeyRepeat(200, 200);

        affiche_menu(choix_player);
        while (continuer==1)
        {
            SDL_WaitEvent(&event);
            switch(event.type)
            {
                case SDL_QUIT:
                    continuer = 3;
                    break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            continuer = 3;
                            break;

                        case SDLK_SPACE:
                            continuer = 0;
                            break;
                        case SDLK_UP:
                            if (choix_player==2)choix_player=1;
                            else if (choix_player==1)choix_player=0;
                            else choix_player=2;
                            break;
                        case SDLK_DOWN:
                            if (choix_player==0)choix_player=1;
                            else if (choix_player==1)choix_player=2;
                            else choix_player=0;
                            break;

                        case SDLK_LEFT:
                            if (choix_player==2){
                            if (choix_sauvegarde==0)break;
                            choix_sauvegarde--;
                            }
                            else if (choix_player==1){
                                if (choix_ia==1)break;
                                choix_ia--;
                            }

                            break;

                        case SDLK_RIGHT:
                            if (choix_player==2){
                            if (choix_sauvegarde==99)break;
                                choix_sauvegarde++;
                            }
                            else if (choix_player==1){
                                if (choix_ia==3)break;
                                choix_ia++;
                            }

                            break;


                        case SDLK_RETURN:
                            continuer = 0;
                            break;
                         default:
                         /* Ne rien faire */
                         break;
                    }
                    break;
            }
        affiche_menu(choix_player);
        }
}

