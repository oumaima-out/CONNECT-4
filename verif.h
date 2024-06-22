int verif(SDL_Surface * couleur[TAILLE][TAILLE]){
    int i,j;
    perdu=0;
    for(i=1;i!=TAILLE-1;i++){
        for(j=1;j!=TAILLE-1;j++){

            //TEST COLONNE
            if(couleur[i][j] == couleur[i][j+1] &&couleur[i][j] == couleur[i][j+2] &&couleur[i][j] == couleur[i][j+3] && couleur[i][j]!=vide){
                    if ( couleur[i][j] == jaune){
                        perdu=1;
                    }
                    else if ( couleur[i][j] == rouge){
                         perdu=2;
                    }
                    break;
            }
            //TEST LIGNE
            else if(couleur[i][j] == couleur[i+1][j] &&couleur[i][j] == couleur[i+2][j] &&couleur[i][j] == couleur[i+3][j] && couleur[i][j]!=vide){

                if ( couleur[i][j] == jaune){
                    perdu=1;
                }
                else if ( couleur[i][j] == rouge){
                     perdu=2;
                }

                break;
            }
            //TEST 1ere DIAGONNALE
            else if(couleur[i][j] == couleur[i+1][j+1] &&couleur[i][j] == couleur[i+2][j+2] &&couleur[i][j] == couleur[i+3][j+3] && couleur[i][j]!=vide){

                if ( couleur[i][j] == jaune){
                    perdu=1;
                }
                else if ( couleur[i][j] == rouge){
                     perdu=2;
                }
                break;
            }
        }
    }

    for(j=1;j!=TAILLE-1;j++){
        for(i=TAILLE-1;i>=1;i--){
            //TEST 2eme Diagonnale
            if(couleur[i][j] == couleur[i-1][j+1] &&couleur[i][j] == couleur[i-2][j+2] &&couleur[i][j] == couleur[i-3][j+3] && couleur[i][j]!=vide){

                if ( couleur[i][j] == jaune){
                    perdu=1;
                }
                else if ( couleur[i][j] == rouge){
                     perdu=2;
                }

                break;
            }

        }
    }
    if (verif_plein==64){
        perdu=3;
        fin=1;
        }
    if (perdu!=0 && ia_joue==0){
        continuer=0;
        fin=1;
    }
    return perdu;
}




