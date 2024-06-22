void save (partie t[]);
/* Gestion evenmentielle !!, fonction de deplacement du P4 */
void deplacement(){
    int i;
    SDL_EnableKeyRepeat(80, 80);// Activation de la répétition des touches
    while (continuer){
        /* Recuperation des evenements */
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            /* Si on appuie sur la croix, on quitte*/
            case SDL_QUIT:
            continuer=0;
            arret=1;
            break;

            /* Des que l'on appuis sur la touche */
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    /* Si on appuie sur echap, on quitte */
                    case SDLK_ESCAPE:
                    continuer=0;
                    arret=1;
                    break;

                    case SDLK_s:
                         ligne=0;
                         sauvegarder=1;
                         save(t);
                    break;

                    case SDLK_RIGHT:
                    /* decale le jeton vers la gauche, le bloque des que c'est different de vide ! */
                         if (couleur[memo1C+1][memo1L]!=vide)break;
                         couleur[memo1C][memo1L]=vide;
                         memo1C++;
                         couleur[memo1C][memo1L]=memo1N;
                    break;

                    case SDLK_LEFT:
                     /* decale le jeton vers la droite, le bloque des que c'est different de vide ! */
                        if (couleur[memo1C-1][memo1L]!=vide)break;
                         couleur[memo1C][memo1L]=vide;
                         memo1C--;
                         couleur[memo1C][memo1L]=memo1N;
                    break;

                    case SDLK_DOWN:

                    /* Si la case du dessous n'est pas vide alors on n'interdit la descente */
                        if (couleur[memo1C][memo1L-1]!=vide)break;
                    /* On descend le jeton tant que la case n'est pas vide  */
                        while(couleur[memo1C][memo1L-1]==vide){
                             couleur[memo1C][memo1L]=vide;
                             memo1L--;
                             couleur[memo1C][memo1L]=memo1N;
                        }

                        /*On incremente une valeur a chaque coup qu'on descend un jeton, Si le tableau et plein on affiche match nul.*/
                        verif_plein++;
                        if (verif_plein>=64){
                            perdu=3;
                            fin=1;
                            continuer=0;
                        }

                        /* On lance le coup de l'ia si le joueur a activer l'ia */
                        if (choix_player==1){
                            /* ON verifie si qlq a gagner */
                           if (verif(couleur)==0){
                               ia_joue=1;
                               /*CHOIX DE l'IA, ia() --> IA par condition ajout_pion --> algo MINMAX*/
                               if (choix_ia==1){
                                 ia();
                               }else {
                                NIVEAU=choix_ia*2;
                                ajout_pion(couleur, 1, choix_colone(couleur, 1));
                                choix_couleur=1;
                               }
                               /* on ajoute le coue de l'ia et on verifie*/
                               verif_plein++;
                               if (verif_plein>=64){
                                    perdu=3;
                                    fin=1;
                                    continuer=0;
                                }
                               ia_joue=0;
                           }else choix_couleur=1;
                        }

                        /* On change le jeton */
                         if(choix_couleur==0)choix_couleur=1;
                         else choix_couleur=0;
                         /* On verifie si il y a un gagnant */
                         verif(couleur);
                         /* On retire le jeton du haut */
                         if (fin==1)break;
                         for (i=1; i!=TAILLE-1; i++){
                            couleur[i][TAILLE-1]=vide;
                        }
                         /* On remet le jeton en haut */
                         alea();
                         break;

                    default:
                    /* Ne rien faire */
                    break;

                }break;
        }
     /* On réaffiche */
      affiche(couleur);

    }
}





/* fonction qui permet de recuperer le pseudo des joueurs*/
void speudo(char login[20]){
    /* On colle le fond noir */
    SDL_BlitSurface(fond_menu, NULL, ecran, NULL);
    /*Defini les positions*/
    SDL_Rect pos_pseudo;
    pos_pseudo.x=150;
    pos_pseudo.y=150;
    SDL_Event eventSaisie; //  variable d'evenements
    SDL_EnableUNICODE(1);  // Cette ligne permet d'activer l'UNICODE
    int positionCurseur = 0, continuerSaisie = 1, backspace = 0;// pour continuer la saisie et positionCurseur permet de se repéré dans le tableau (pour pas supprimé une ancienne entrée)

    /* On demande au joueur de tapez son pseudo !! */
    sprintf(TEXTE, "Tapez votre pseudo, puis appuyer sur entrer");
    texte = TTF_RenderText_Blended(police, TEXTE, couBlanc);
    SDL_BlitSurface(texte, NULL, ecran, &pos_ecriture);
    sprintf(TEXTE, "%s",login);


    while(continuerSaisie) // La boucle (pour que des que le joueur appuis sur le clavier, il se passe un evenement
    {

        SDL_WaitEvent(&eventSaisie);

        if(eventSaisie.type == SDL_KEYDOWN)
        {

            if(eventSaisie.key.keysym.sym == SDLK_BACKSPACE) // Si il appuis sur la touche retour arriere...
            {
                if (positionCurseur>0){                      // ... on  recule le curseur de 1, sauf si la position et au minimum!
                positionCurseur--;
                }
                login[positionCurseur] = '\0'; // Efface l'ancienne saisie
                backspace=1;
            }
            if(eventSaisie.key.keysym.sym == SDLK_RETURN)
            {
                SDL_EnableUNICODE(0); // Si il appuis sur entrée , on desactive l'UNICODE
                continuerSaisie = 0; // On quitte la boucle
                 break;
            }
            if(eventSaisie.key.keysym.sym == SDLK_ESCAPE)
            {
                continuerSaisie = 0;
                continuer=0;
                arret=1;
                break;
            }
            if(((eventSaisie.key.keysym.unicode & 0xFF00) == 0x0000)  && eventSaisie.key.keysym.sym != SDLK_RSHIFT && eventSaisie.key.keysym.sym != SDLK_LSHIFT && (positionCurseur + 1 < 20) && continuerSaisie == 1 && backspace==0 ) // ça je n'est pas trop compris, mais le deuxieme argument et que si le curseur n'est pas a la fin du tableau ...
            {
                login[positionCurseur] = eventSaisie.key.keysym.unicode; // on enregistre la touche appuyée dans le tableau à la position du curseur
                positionCurseur++; // on avance le curseur de 1 (pour évité de supprimé l'ancienne entrée de l'utilisateur
                login[positionCurseur] = '\0'; // ...et on vide cette' nouvelle case pour la prochaine entrée.

            }

            /* On colle le fond noir */
            SDL_BlitSurface(fond_menu, NULL, ecran, NULL);


             /* On demande au joueur de tapez son pseudo !! */
            sprintf(TEXTE, "Tapez votre pseudo, puis appuyer sur entrer");
            texte = TTF_RenderText_Blended(police, TEXTE, couBlanc);
            SDL_BlitSurface(texte, NULL, ecran, &pos_ecriture);
            sprintf(TEXTE, "%s",login);

            /* On libere les surface */
            SDL_FreeSurface(texte);

            /* On colle la surface*/
            texte = TTF_RenderText_Blended(police, TEXTE, couBlanc);
            SDL_BlitSurface(texte, NULL, ecran, &pos_pseudo);

        }

        backspace=0;
        SDL_Flip(ecran);

    }

}

//Permet de sauvegarder la partie
void save (partie t[]){
    FILE* fichier = NULL;
   char chaine[512]="";

    int i,j;
    fichier = fopen("Partie.txt", "a+");
    while (fgets(chaine, 512, fichier) != NULL){
        ligne++;
    }
    /* On limite a 100 sauvegardes !! */
    if (ligne/5<100){
    fprintf(fichier, "%d\n", ligne/5);
    for(i=0;i!=TAILLE;i++){
        for(j=0;j!=TAILLE;j++){

           if (couleur[i][j]==jaune)t[1].tableau[i][j]='0';
           else if (couleur[i][j]==rouge)t[1].tableau[i][j]='1';
           else if (couleur[i][j]==vide)t[1].tableau[i][j]='2';
           else if (couleur[i][j]==noir)t[1].tableau[i][j]='3';
          fprintf(fichier,"%c",t[1].tableau[i][j]);
        }
    }
    sprintf(t[1].pseudo_P1, "%s",PSEUDO);
    sprintf(t[1].pseudo_P2, "%s",PSEUDO2);
    t[1].score_P1=score1;
    t[1].score_P2=score2;
    fprintf(fichier, "\n%s\n%s\n%d.%d\n",t[1].pseudo_P1,t[1].pseudo_P2,t[1].score_P1,t[1].score_P2);
    }
    fclose(fichier);
}

//permet de charger la partie
void load (partie t[], char num_partie){
    FILE* fichier = NULL;
    char chaine[512];
    int i,j,a=0;
    fichier = fopen("Partie.txt", "r");
    while (fgets(chaine, 512, fichier) != NULL ){

        if (num_partie==chaine[0] && (chaine[1]=='\n'|| chaine[2]=='\n')){
            /*recuperation et initialisation du tableau*/
            fscanf(fichier, "%s", chaine);
            for(i=0;i!=TAILLE;i++){
                for(j=0;j!=TAILLE;j++){
                  t[1].tableau[i][j]=chaine[a];
                  a++;
                }
            }
            /* recuperation des pseudos*/
            fscanf(fichier, "%s", t[1].pseudo_P1);
            fscanf(fichier, "%s", t[1].pseudo_P2);
            /*recuperation des scores*/
            fscanf(fichier, "%d.%d", &t[1].score_P1,&t[1].score_P2);

        }

    }


    fclose(fichier);
}




