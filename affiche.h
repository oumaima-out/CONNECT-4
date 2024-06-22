/* Permet l'affichage global */
void affiche(SDL_Surface * couleur[TAILLE][TAILLE]){
    /* On colle la surface de fond */
    SDL_BlitSurface(fond, NULL, ecran, NULL);
    int i,j;
    /* On definie la position de pos ! */
    pos.x=55;
    pos.y=320;
    /*Gestions des affichages en fonction des variables */
    sprintf(SCORE, "P1  %d          P2  %d", score1,score2);
    if(choix_couleur==0)sprintf(TEXTE, "P1: %s", PSEUDO);
    if(choix_couleur==1)sprintf(TEXTE, "P2: %s", PSEUDO2);
    if (fin==1&&perdu==1){
        score1++;
        sprintf(TEXTE, "%s Gagne",PSEUDO);
    }
    if (fin==1&&perdu==2){
        score2++;
        sprintf(TEXTE, "%s Gagne",PSEUDO2);
    }
    if (fin==1&&perdu==3)sprintf(TEXTE, "Match Nul");
    if (sauvegarder==1){
        if (ligne/5>=100)sprintf(TEXTE, "Sauvegarde Pleine, vider le fichier partie.txt");
        else sprintf(TEXTE, "Sauvegarde: %d", ligne/5);

    }

    /* On libere les surface */
    SDL_FreeSurface(texte);
    SDL_FreeSurface(score);

    /* On colle les surfaces (texte + score => Score et player1,player2 ...)  */
    texte = TTF_RenderText_Blended(police, TEXTE, couBlanc);
    SDL_BlitSurface(texte, NULL, ecran, &pos_ecriture);
    score = TTF_RenderText_Blended(police, SCORE, couBlanc);
    SDL_BlitSurface(score, NULL, ecran, &pos_score);

    /* On lit le tableau et on l'affiche (jetons)  */
    for(i=0;i!=TAILLE;i++){
        for(j=0;j!=TAILLE;j++){
            SDL_BlitSurface(couleur[i][j], NULL, ecran, &pos);
            pos.y=pos.y-31;
        }
        pos.y=320;
        pos.x=pos.x+29;
    }

    /* On actualise l'eran */
    SDL_Flip(ecran);


}

