SDL_Surface *ecran = NULL,*fond = NULL,*jaune = NULL,*rouge = NULL, *vide=NULL,* noir= NULL, *fond_menu=NULL;    //DECLARATION DES SURFACES
SDL_Surface *couleur[TAILLE][TAILLE],*texte=NULL,*score=NULL;//Tableau + surface texte
SDL_Rect pos,pos_ecriture,pos_score,choix_menu,pos_menu; //POSITION
/*Necessaire au texte*/
SDL_Color couBlanc = {255, 255, 255};
TTF_Font *police = NULL;
SDL_Event event; //GESTION EVENMENTIELLE

/*prototype*/
void alea();
void affiche();
int verif(SDL_Surface * couleur[TAILLE][TAILLE]);
int ajout_pion(SDL_Surface * couleur[TAILLE][TAILLE], int color, int colone);
int choix_colone(SDL_Surface * couleur[TAILLE][TAILLE], int color);
int min_max(SDL_Surface * couleur[TAILLE][TAILLE], int color, int nv);
void copie_casier(SDL_Surface *C[TAILLE][TAILLE], SDL_Surface *O[TAILLE][TAILLE]);

/*Structure de la partie !! */
struct partie{
  int partie[10];
  int score_P1;
  int score_P2;
  char pseudo_P1[20];
  char pseudo_P2[20];
  char tableau[TAILLE][TAILLE];
};
typedef struct partie partie;
partie t[100];


char TEXTE[100];
char CHOIX[100];
char LOAD[100];
char SCORE[100];
char PSEUDO[20] = "Player1";// stocke l'entrée de l'utilisateur (pseudo) si l'utilisateur rentre rien player1
char PSEUDO2[20] = "Player2";// stocke l'entrée de l'utilisateur (pseudo) si l'utilisateur rentre rien player2

SDL_Surface *memo1N=NULL;
int continuer = 1, choix_couleur=0;
int memo1L,memo1C;//CASE du tableau
int verif_plein=0;//Variable qui s'increment à chaque coup jouer, pour savoir quand le tableau et plein
int fin=0,perdu=0,arret=0;//Les conditions de sortie
int score1=0,score2=0;//Les scores des joueurs
int choix_player;//les differents choix , choisi dans le menu
int sauvegarder=0,choix_sauvegarde=0;
int ligne;//nbre de lignes dans le fichier .txt
int ia_joue=0,choix_ia=1,NIVEAU; // les variables neccesaire à l'ia




