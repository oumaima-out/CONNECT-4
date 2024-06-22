/* cette fonction permet de remettre les jettons jaune/rouge en haut */
void alea(){
    /* On remet la sauvegarde a 0 , pour arreter son affichage !! */
    sauvegarder=0;
    if (choix_couleur==0){
        couleur[4][TAILLE-1]=jaune;
        memo1N=jaune;
    }
    else {
        couleur[4][TAILLE-1]=rouge;
        memo1N=rouge;
    }
    memo1L=TAILLE-1;
    memo1C=4;
}

void init(){

        int i,j;
        int cpt_jaune=0,cpt_rouge=0;
        continuer = 1;

       /* INITIALISATION DU TALBEAU */
       for(i=1;i!=TAILLE;i++){
            for(j=1;j!=TAILLE;j++){
                couleur[i][j]=vide;
            }
        }
        for (i=0; i!=TAILLE; i++){
           couleur[i][0]=noir;
        }
        for (i=0; i!=TAILLE; i++){
           couleur[0][i]=noir;
           couleur[TAILLE-1][i]=noir;
        }
        /* Si on charge une partie, on charge la structure !! */
        if (choix_player==2){

           for(i=0;i!=TAILLE;i++){
                for(j=0;j!=TAILLE;j++){
                   if (t[1].tableau[i][j]=='0'){
                       couleur[i][j]=jaune;
                       cpt_jaune++;
                   }
                   else if (t[1].tableau[i][j]=='1'){
                        couleur[i][j]=rouge;
                        cpt_rouge++;
                   }
                   else if (t[1].tableau[i][j]=='2')couleur[i][j]=vide;
                   else if (t[1].tableau[i][j]=='3')couleur[i][j]=noir;
                }
            }
            sprintf(PSEUDO, "%s",t[1].pseudo_P1);
            sprintf(PSEUDO2, "%s",t[1].pseudo_P2);
            score1=t[1].score_P1;
            score2=t[1].score_P2;

            /* On regarde c'est a qui de jouer */
            if(cpt_rouge==cpt_jaune)choix_couleur=1;
            else choix_couleur=0;

            //on remet l'ia si la partie était contre l'ia
            if (PSEUDO2[0]=='I' && PSEUDO2[1]=='A' && PSEUDO2[2]=='\0' ){
            choix_player=1;
           }else choix_player=0;
        }

        /* on relance */
       alea();
       deplacement();
}
