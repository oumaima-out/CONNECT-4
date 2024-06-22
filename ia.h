/* IA tout bete */
void ia(){
    int i,j,ia_joue=0;
    choix_couleur=1;
   /* Attaque */
   for(i=1;i!=TAILLE-1;i++){
        for(j=1;j!=TAILLE-1;j++){
            //TEST colonne (3 jetons)
            if(rouge == couleur[i][j] && rouge == couleur[i][j+1] &&rouge == couleur[i][j+2] && ia_joue==0){
                if (couleur[i][j+3] == vide){
                    couleur[i][j+3]=rouge;
                    ia_joue=1;
                    break;
                }
            }

            //TEST LIGNE
            //rouge 3 jetons
            else if(rouge == couleur[i][j] && rouge == couleur[i+1][j] && rouge == couleur[i+2][j] && ia_joue==0){
                if (couleur[i+3][j] == vide && couleur[i+3][j-1] != vide ){
                    couleur[i+3][j]=rouge;
                    ia_joue=1;
                    break;
                    }
                if (couleur[i+3][j] != vide && couleur[i-1][j] == vide && couleur[i-1][j-1] != vide && ia_joue==0){
                    couleur[i-1][j]=rouge;
                    ia_joue=1;
                    break;
                    }
            }

            //TEST 1ere DIAGONNALE
            else if(rouge == couleur[i][j] && rouge == couleur[i+1][j+1] &&rouge == couleur[i+2][j+2] && ia_joue==0){
                if (couleur[i+3][j+3] == vide && couleur[i+3][j+2] != vide){
                    couleur[i+3][j+3]=rouge;
                    ia_joue=1;
                    break;
                }
                if (couleur[i-3][j-3] == vide && couleur[i-3][j-2] !=vide && ia_joue==0){
                    couleur[i-3][j-3]=rouge;
                    ia_joue=1;
                    break;
                }
            }
        }
    }

    for(j=1;j!=TAILLE-1;j++){
        for(i=TAILLE-1;i>=1;i--){
            //TEST 2eme Diagonnale
            if(rouge == couleur[i][j] &&rouge == couleur[i-1][j+1] &&rouge == couleur[i-2][j+2]&& ia_joue==0){
                if (couleur[i-3][j+3] == vide && couleur[i-3][j+2] != vide){
                    couleur[i-3][j+3]=rouge;
                    ia_joue=1;
                    break;
                }
                if (couleur[i+3][j-3] == vide&&couleur[i+3][j-3] != vide && ia_joue==0){
                    couleur[i+3][j-3]=rouge;
                    ia_joue=1;
                    break;
                }
            }

        }
    }

    /* DEFENSE */
    for(i=1;i!=TAILLE-1;i++){
        for(j=1;j!=TAILLE-1;j++){
            //TEST colonne (3 jetons)
            if(jaune == couleur[i][j] && jaune == couleur[i][j+1] &&jaune == couleur[i][j+2] && ia_joue==0){
                if (couleur[i][j+3] == vide){
                    couleur[i][j+3]=rouge;
                    ia_joue=1;
                    break;
                }
            }

            //TEST LIGNE
            //Jaune 2 jetons
            else if(jaune == couleur[i][j] && jaune == couleur[i+1][j] && ia_joue==0){
                if (couleur[i+2][j] == vide && couleur[i+2][j-1] != vide ){
                    couleur[i+2][j]=rouge;
                    ia_joue=1;
                    break;
                    }
                if (couleur[i+2][j] != vide && couleur[i-1][j] == vide && couleur[i-1][j-1] != vide && ia_joue==0){
                    couleur[i-1][j]=rouge;
                    ia_joue=1;
                    break;
                    }
            }

            //TEST 1ere DIAGONNALE
            else if(jaune == couleur[i][j] && jaune == couleur[i+1][j+1] &&jaune == couleur[i+2][j+2] && ia_joue==0){
                if (couleur[i+3][j+3] == vide && couleur[i+3][j+2] != vide){
                    couleur[i+3][j+3]=rouge;
                    ia_joue=1;
                    break;
                }
                if (couleur[i-3][j-3] == vide && couleur[i-3][j-2] !=vide && ia_joue==0){
                    couleur[i-3][j-3]=rouge;
                    ia_joue=1;
                    break;
                }
            }
        }
    }

    for(j=1;j!=TAILLE-1;j++){
        for(i=TAILLE-1;i>=1;i--){
            //TEST 2eme Diagonnale
            if(jaune == couleur[i][j] &&jaune == couleur[i-1][j+1] &&jaune == couleur[i-2][j+2]&& ia_joue==0){
                if (couleur[i-3][j+3] == vide && couleur[i-3][j+2] != vide){
                    couleur[i-3][j+3]=rouge;
                    ia_joue=1;
                    break;
                }
                if (couleur[i+3][j-3] == vide&&couleur[i+3][j-3] != vide && ia_joue==0){
                    couleur[i+3][j-3]=rouge;
                    ia_joue=1;
                    break;
                }
            }

        }
    }


    /*Ia+*/
    //Attaque si 2 jetons egaux
    for(i=1;i!=TAILLE-1;i++){
        for(j=1;j!=TAILLE-1;j++){
            //TEST colonne (2 jetons)
            if(rouge == couleur[i][j] && rouge == couleur[i][j+1] && ia_joue==0){
                if (couleur[i][j+2] == vide){
                    couleur[i][j+2]=rouge;
                    ia_joue=1;
                    break;
                }
            }

            //TEST LIGNE
            //Jaune 2 jetons
            else if(rouge == couleur[i][j] && rouge == couleur[i+1][j] && ia_joue==0){
                if (couleur[i+2][j] == vide && couleur[i+2][j-1] != vide ){
                    couleur[i+2][j]=rouge;
                    ia_joue=1;
                    break;
                    }
                if (couleur[i+2][j] != vide && couleur[i-1][j] == vide && couleur[i-1][j-1] != vide && ia_joue==0){
                    couleur[i-1][j]=rouge;
                    ia_joue=1;
                    break;
                    }
            }
        }
    }
    //Attaque si 1 jetons
     for(i=1;i!=TAILLE-1;i++){
        for(j=1;j!=TAILLE-1;j++){
            //TEST colonne (1 jetons)
            if(rouge == couleur[i][j] && ia_joue==0){
                if (couleur[i][j+1] == vide){
                    couleur[i][j+1]=rouge;
                    ia_joue=1;
                    break;
                }
            }

            //TEST LIGNE
            //1 jetons
            else if(rouge == couleur[i][j] && ia_joue==0){
                if (couleur[i+1][j] == vide && couleur[i+1][j-1] != vide ){
                    couleur[i+1][j]=rouge;
                    ia_joue=1;
                    break;
                    }
                if (couleur[i+1][j] != vide && couleur[i-1][j] == vide && couleur[i-1][j-1] != vide && ia_joue==0){
                    couleur[i-1][j]=rouge;
                    ia_joue=1;
                    break;
                    }
            }
        }
    }

   /* Si l'ia ne sais pas quoi jouer random*/


   while(ia_joue==0){
        memo1N=rouge;
        memo1C=rand()%6+1;
        memo1L=6;
        if (couleur[memo1C][memo1L-1]==vide){

                    while(couleur[memo1C][memo1L-1]==vide){
                         couleur[memo1C][memo1L]=vide;
                         memo1L--;
                         couleur[memo1C][memo1L]=memo1N;
                    }
                    ia_joue=1;
        }


    }

    for (i=1; i!=TAILLE-1; i++){
        couleur[i][TAILLE-1]=vide;
    }

}

/* Les fonctions necessaire à l'ALGO MIN/MAX !! */
int ajout_pion(SDL_Surface * couleur[TAILLE][TAILLE], int choix_couleur, int colone)
     {
     int Ligne;
     /*On retourne 0 si le choix couleur n'est pas bon , si la colonne n'existe pas ou si la colonne et pleine !!*/
     if(choix_couleur!=0&&choix_couleur!=1)      return 0;
     if(colone<=0 && colone>=TAILLE-1)        return 0;
     if(couleur[colone][TAILLE-2]!=vide)    return 0;
     /* On ajoute et on descend le jeton tant que la ligne est vide */
     Ligne=9;
     while(couleur[colone][Ligne-1]==vide && Ligne>0){
         couleur[colone][Ligne]=vide;
         Ligne--;
         if (choix_couleur==1){
            couleur[colone][Ligne]=rouge;
         }
         else couleur[colone][Ligne]=jaune;
     }
     return 1;                                                                 //Si on a fait quelque chose on retourne 1 !
     };

/* Permet de copie le tableau temporaire dans le tableau de jeu..*/
void copie_casier(SDL_Surface *C[TAILLE][TAILLE], SDL_Surface *O[TAILLE][TAILLE])
{
     int r,c;
     for(r=0;r!=TAILLE;r++)
     for(c=0;c!=TAILLE;c++)
          O[c][r]=C[c][r];
};

/* L'algo min/max */
int min_max(SDL_Surface * couleur[TAILLE][TAILLE], int choix_couleur, int nv){

     int c, r, mc, cc,F;
     /*INITIALISATION d'un tableau temporaire */
     SDL_Surface * tmpcouleur[TAILLE][TAILLE];

    F=verif(couleur);
    /* On change la couleur du jeton */
    if(choix_couleur==1)choix_couleur=0;
    else choix_couleur=1;
    /* Si on atteind la profondeur max et qu'il n'y a pas de gagnant, on retourne 0 */
    if(F==0 && nv==0) return 0;
    /* si il y a un gagnant ou retourne une valeure qui est loin de 0 si on gagne vite */
     if(F==1) return (nv+1);
     if(F==2) return -(nv+1);
     mc = -1;
     /* ce que ca rapporte */                                                                 //la meilleure colone a jouer
     r = 20;
     if(choix_couleur==0) r=-20;

     for(c=1;c!=TAILLE-1;c++)
          {
              /* on travaille sur un tableau temporaire */
          copie_casier(couleur, tmpcouleur);
          /* On joue sur differente colone et si c'est possible on continue */
          if(ajout_pion(tmpcouleur, choix_couleur, c)==1)
               {
               cc=min_max(tmpcouleur, choix_couleur, nv-1);
               /* on voit si le coup est plus rentable que le meilleur précédent */
               if(((cc<r)&&(choix_couleur==1))||((cc>r)&&(choix_couleur==0)))
                    {
                    r=cc;
                    mc=c;
                    }
               }
          };
     /* si y'en a pas eu, on retrourne 0*/
     if(r==20||r==-20) return 0;

     return r;
};

int choix_colone(SDL_Surface * couleur[TAILLE][TAILLE], int choix_couleur)
     {
     int ror[9];
     int d, c, r, mc, cc;
    srand(time(NULL));
    /*INITIALISATION d'un tableau temporaire */
     SDL_Surface * tmpcouleur[TAILLE][TAILLE];
     for(c=1;c!=TAILLE-1;c++)
          {
          do{
          mc=1;
          d=rand()%8+1;
          /* on mélange un peu l'ordre dans lequel on cherche le meilleur coup */
          for(r=1;r<c;r++)
               if(ror[r]==d) mc=0;
          }while(mc==0);
          ror[c]=d;
          };
     mc = -1;
     r = 20;
     if(choix_couleur==0) r=-20;
     for(d=1;d!=TAILLE-1;d++)
          {
          c=ror[d];
          copie_casier(couleur, tmpcouleur);
          if(ajout_pion(tmpcouleur, choix_couleur, c)==1)
               {
               cc=min_max(tmpcouleur, choix_couleur, NIVEAU);
               if(((cc<r)&&(choix_couleur==1))||((cc>r)&&(choix_couleur==0)))
                    {
                    r=cc;
                    mc=c;
                    }
               }
          };
    /* si il y a pas de coup favorisé */
     if(mc==-1)
          {
          for(c=1;c!=TAILLE-1;c++)
               {
               copie_casier(couleur, tmpcouleur);
               /* on en cherche un possible, -1 retourner si y'a pas */
               if(ajout_pion(tmpcouleur, choix_couleur, c)==1) mc=c;
               }
          }
     return mc;
};







