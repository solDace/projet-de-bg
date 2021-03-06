#include "main.h"

/**
 * \file memoire.c
 * \brief Description des fonctions permettant le fonctionnement des test memoires
 * \author Thomas.B
 * \version 1.0
 * \date 25 Juin 2020
 *
 * Fonction traitant des test memoires
 *
 */
int mod = 999,choix=0,one_matrice = 0,win = 0;

/**
 * \fn void Display_ColorButtons(int carre)
 * \brief Affichage les carrés
 *
 * \param carre numéro du carré à allumer
 * \return none
 */

void Display_ColorButtons(int carre){

  couleurCourante(100, 0, 0);
  rectangle(2*LargeurFenetre/15, 6*(HauteurFenetre - HauteurFenetre/10)/7,5*LargeurFenetre/15,4*(HauteurFenetre - HauteurFenetre/10)/7 );
  couleurCourante(0, 100, 0);
  rectangle(6*LargeurFenetre/15, 6*(HauteurFenetre - HauteurFenetre/10)/7,9*LargeurFenetre/15,4*(HauteurFenetre - HauteurFenetre/10)/7 );
  couleurCourante(0, 0, 100);
  rectangle(10*LargeurFenetre/15, 6*(HauteurFenetre - HauteurFenetre/10)/7,13*LargeurFenetre/15,4*(HauteurFenetre - HauteurFenetre/10)/7);


  couleurCourante(100, 100, 0);
  rectangle(2*LargeurFenetre/15, 3*(HauteurFenetre - HauteurFenetre/10)/7,5*LargeurFenetre/15,(HauteurFenetre - HauteurFenetre/10)/7 );
  couleurCourante(0, 100, 100);
  rectangle(6*LargeurFenetre/15, 3*(HauteurFenetre - HauteurFenetre/10)/7,9*LargeurFenetre/15,(HauteurFenetre - HauteurFenetre/10)/7 );
  couleurCourante(100, 0, 100);
  rectangle(10*LargeurFenetre/15, 3*(HauteurFenetre - HauteurFenetre/10)/7,13*LargeurFenetre/15,(HauteurFenetre - HauteurFenetre/10)/7 );


  switch (carre) {
    case 1:
    couleurCourante(200, 0, 0);
    rectangle(2*LargeurFenetre/15, 6*(HauteurFenetre - HauteurFenetre/10)/7,5*LargeurFenetre/15,4*(HauteurFenetre - HauteurFenetre/10)/7 );
    break;
    case 2:
    couleurCourante(0, 200, 0);
    rectangle(6*LargeurFenetre/15, 6*(HauteurFenetre - HauteurFenetre/10)/7,9*LargeurFenetre/15,4*(HauteurFenetre - HauteurFenetre/10)/7 );
    break;
    case 3:
    couleurCourante(0, 0, 200);
    rectangle(10*LargeurFenetre/15, 6*(HauteurFenetre - HauteurFenetre/10)/7,13*LargeurFenetre/15,4*(HauteurFenetre - HauteurFenetre/10)/7);
    break;
    case 4:
    couleurCourante(200, 200, 0);
    rectangle(2*LargeurFenetre/15, 3*(HauteurFenetre - HauteurFenetre/10)/7,5*LargeurFenetre/15,(HauteurFenetre - HauteurFenetre/10)/7 );
    break;
    case 5:
    couleurCourante(0, 200, 200);
    rectangle(6*LargeurFenetre/15, 3*(HauteurFenetre - HauteurFenetre/10)/7,9*LargeurFenetre/15,(HauteurFenetre - HauteurFenetre/10)/7 );
    break;
    case 6:
    couleurCourante(200, 0, 200);
    rectangle(10*LargeurFenetre/15, 3*(HauteurFenetre - HauteurFenetre/10)/7,13*LargeurFenetre/15,(HauteurFenetre - HauteurFenetre/10)/7 );
    break;
  }


}

/**
 * \fn void Display_TestMemoire(int mode)
 * \brief Affichage le message central
 *
 * \param mode attente ou à l'utilisateur de jouer
 * \return none
 */

void Display_TestMemoire(int mode){
  int taille;
	couleurCourante(140,140,140);
  if(mode ==1){
	taille = tailleChaine("Memorisez", 15);
	afficheChaine("Memorisez", 15, (LargeurFenetre - taille)/2, 4*(HauteurFenetre - HauteurFenetre/10)/7 -(HauteurFenetre - HauteurFenetre/10)/14);
}
else if(mode ==2){
  taille = tailleChaine("A ton tour", 15);
  afficheChaine("A ton tour", 15, (LargeurFenetre - taille)/2, 4*(HauteurFenetre - HauteurFenetre/10)/7 - (HauteurFenetre - HauteurFenetre/10)/14);
}
}

/**
 * \fn void Create_Random_Pattern(int tab[MAX_PATTERN], int dif)
 * \brief Créé une suite aléatoire d'allumage des boutons
 *
 * \param tab tableau contenant la suite des boutons à cliquer
 * \param dif Difficulté actuel (nombre de boutons à mémoriser)
 * \return none
 */

void Create_Random_Pattern(int tab[MAX_PATTERN], int dif){

  for(int i=0; i<dif; i++){
    tab[i]=rand()%6+1;
  }
  for(int i=dif; i<MAX_PATTERN; i++){
    tab[i]=0;
  }

}

/**
 * \fn int check_Pattern(int carre)
 * \brief hitbox du carré à cliquer
 *
 * \param carre nulero du bouton à cliquer
 * \return 1 si juste / 0 si faux
 */

int check_Pattern(int carre){
  int check=0;
  switch (carre) {
    case 1:
    if(abscisseSouris() >= (2*LargeurFenetre/15) && abscisseSouris() <= 5*LargeurFenetre/15 && ordonneeSouris() >= 4*(HauteurFenetre - HauteurFenetre/10)/7 && ordonneeSouris() <= 6*(HauteurFenetre - HauteurFenetre/10)/7) {
      check = 1;
    }
    break;
    case 2:
    if(abscisseSouris() >= (6*LargeurFenetre/15) && abscisseSouris() <= 9*LargeurFenetre/15 && ordonneeSouris() >= 4*(HauteurFenetre - HauteurFenetre/10)/7 && ordonneeSouris() <= 6*(HauteurFenetre - HauteurFenetre/10)/7) {
      check = 1;
    }
    break;
    case 3:
    if(abscisseSouris() >= (10*LargeurFenetre/15) && abscisseSouris() <= 13*LargeurFenetre/15 && ordonneeSouris() >= 4*(HauteurFenetre - HauteurFenetre/10)/7 && ordonneeSouris() <= 6*(HauteurFenetre - HauteurFenetre/10)/7) {
      check = 1;
    }
    break;
    case 4:
    if(abscisseSouris() >= (2*LargeurFenetre/15) && abscisseSouris() <= 5*LargeurFenetre/15 && ordonneeSouris() >= (HauteurFenetre - HauteurFenetre/10)/7 && ordonneeSouris() <= 3*(HauteurFenetre - HauteurFenetre/10)/7) {
      check = 1;
    }
    break;
    case 5:
    if(abscisseSouris() >= (6*LargeurFenetre/15) && abscisseSouris() <= 9*LargeurFenetre/15 && ordonneeSouris() >= (HauteurFenetre - HauteurFenetre/10)/7 && ordonneeSouris() <= 3*(HauteurFenetre - HauteurFenetre/10)/7) {
      check = 1;
    }
    break;
    case 6:
    if(abscisseSouris() >= (10*LargeurFenetre/15) && abscisseSouris() <= 13*LargeurFenetre/15 && ordonneeSouris() >= (HauteurFenetre - HauteurFenetre/10)/7 && ordonneeSouris() <= 3*(HauteurFenetre - HauteurFenetre/10)/7) {
      check = 1;
    }
    break;
    case 0:
      check = 2;
     break;
  }

  return check;
}


///////////////////


/**
 * \fn int** chasard()
 * \brief créé et rempli aléatoirement un tableau 2D
 *
 * \return un tableau int 2 dimensions
 */

int** chasard(){

	int **matrice = (int**)malloc(3*sizeof(int*));

	for(int i = 0; i < 3; i++){

		matrice[i] = (int*)malloc(4*sizeof(int));

		}

	srand(time(NULL));

	for(int i = 0; i < 3;i++){

		for(int j = 0; j < 4; j++){

			matrice[i][j] = rand()%2;

			printf("%d ",matrice[i][j]);

			}

			printf("\n");

		}

		return matrice;
	}



/**
 * \fn int nbr_one_matrice(int **matrice)
 * \brief compte le nombre de 1 dans la matrice
 *
 * \param matrice tableau 2 dimension
 * \return le nombre de 1 dans la matrice
 */


int nbr_one_matrice(int **matrice){
	one_matrice = 0;
	for(int i = 0; i < 3;i++){

		for(int j = 0; j < 4; j++){

			if(matrice[i][j] == 1){

				one_matrice++;

			}
		}
	}
	return one_matrice;
}

/**
 * \fn void freefct2(int **matrice)
 * \brief libère un tableau deux dimensions
 *
 * \param matrice tableau 2 dimension
 * \return none
 */
void freefct2(int **matrice){

	int i;

	for(i=0; i < 3;i++){

		free((int*)matrice[i]);

		}

		free((int*)matrice);

	}

/**
 * \fn void choixCouleurs(int choix)
 * \brief change la couleur courante (1=noir sinon blanc)
 *
 * \param choix variable pour choisir la couleur
 * \return none
 */
void choixCouleurs(int choix){

	if(choix == 1){

		couleurCourante(0,0,0);

		}

	else{

		couleurCourante(220,220,220);

			}
	}

/**
 * \fn void init_carre(int **matrice)
 * \brief dessine les carre dans la couleur correspondante
 *
 * \param matrice tableau deux dimension
 * \return none
 */

void init_carre(int **matrice){


	choixCouleurs(matrice[0][0]);
	rectangle(6*LargeurFenetre/30,6*(HauteurFenetre-HauteurFenetre/8)/6,10*LargeurFenetre/30,5*(HauteurFenetre-HauteurFenetre/8)/6);

	choixCouleurs(matrice[0][1]);
	rectangle(11*LargeurFenetre/30,6*(HauteurFenetre-HauteurFenetre/8)/6,15*LargeurFenetre/30,5*(HauteurFenetre-HauteurFenetre/8)/6);

	choixCouleurs(matrice[0][2]);
	rectangle(16*LargeurFenetre/30,6*(HauteurFenetre-HauteurFenetre/8)/6,20*LargeurFenetre/30,5*(HauteurFenetre-HauteurFenetre/8)/6);

	choixCouleurs(matrice[0][3]);
	rectangle(21*LargeurFenetre/30,6*(HauteurFenetre-HauteurFenetre/8)/6,25*LargeurFenetre/30,5*(HauteurFenetre-HauteurFenetre/8)/6);



	choixCouleurs(matrice[1][0]);
	rectangle(6*LargeurFenetre/30,4*(HauteurFenetre-HauteurFenetre/8)/6,10*LargeurFenetre/30,3*(HauteurFenetre-HauteurFenetre/8)/6);

	choixCouleurs(matrice[1][1]);
	rectangle(11*LargeurFenetre/30,4*(HauteurFenetre-HauteurFenetre/8)/6,15*LargeurFenetre/30,3*(HauteurFenetre-HauteurFenetre/8)/6);

	choixCouleurs(matrice[1][2]);
	rectangle(16*LargeurFenetre/30,4*(HauteurFenetre-HauteurFenetre/8)/6,20*LargeurFenetre/30,3*(HauteurFenetre-HauteurFenetre/8)/6);

	choixCouleurs(matrice[1][3]);
	rectangle(21*LargeurFenetre/30,4*(HauteurFenetre-HauteurFenetre/8)/6,25*LargeurFenetre/30,3*(HauteurFenetre-HauteurFenetre/8)/6);



	choixCouleurs(matrice[2][0]);
	rectangle(6*LargeurFenetre/30,2*(HauteurFenetre-HauteurFenetre/8)/6,10*LargeurFenetre/30,(HauteurFenetre-HauteurFenetre/8)/6);

	choixCouleurs(matrice[2][1]);
	rectangle(11*LargeurFenetre/30,2*(HauteurFenetre-HauteurFenetre/8)/6,15*LargeurFenetre/30,(HauteurFenetre-HauteurFenetre/8)/6);

	choixCouleurs(matrice[2][2]);
	rectangle(16*LargeurFenetre/30,2*(HauteurFenetre-HauteurFenetre/8)/6,20*LargeurFenetre/30,(HauteurFenetre-HauteurFenetre/8)/6);

	choixCouleurs(matrice[2][3]);
	rectangle(21*LargeurFenetre/30,2*(HauteurFenetre-HauteurFenetre/8)/6,25*LargeurFenetre/30,(HauteurFenetre-HauteurFenetre/8)/6); 

	}

  /**
 * \fn void carre_gris(int** matrice,int tab[3][4])
 * \brief dessine tout les carre en gris
 *
 * \param matrice les réponses du joueur
 * \param tab les bonnes réponses
 * \return none
 */


void carre_gris(int** matrice,int tab[3][4]){

	carre_noir(matrice[0][0],tab[0][0]);
	rectangle(6*LargeurFenetre/30,6*(HauteurFenetre-HauteurFenetre/8)/6,10*LargeurFenetre/30,5*(HauteurFenetre-HauteurFenetre/8)/6);

	carre_noir(matrice[0][1],tab[0][1]);
	rectangle(11*LargeurFenetre/30,6*(HauteurFenetre-HauteurFenetre/8)/6,15*LargeurFenetre/30,5*(HauteurFenetre-HauteurFenetre/8)/6);

	carre_noir(matrice[0][2],tab[0][2]);
	rectangle(16*LargeurFenetre/30,6*(HauteurFenetre-HauteurFenetre/8)/6,20*LargeurFenetre/30,5*(HauteurFenetre-HauteurFenetre/8)/6);

	carre_noir(matrice[0][3],tab[0][3]);
	rectangle(21*LargeurFenetre/30,6*(HauteurFenetre-HauteurFenetre/8)/6,25*LargeurFenetre/30,5*(HauteurFenetre-HauteurFenetre/8)/6);




	carre_noir(matrice[1][0],tab[1][0]);
	rectangle(6*LargeurFenetre/30,4*(HauteurFenetre-HauteurFenetre/8)/6,10*LargeurFenetre/30,3*(HauteurFenetre-HauteurFenetre/8)/6);

	carre_noir(matrice[1][1],tab[1][1]);
	rectangle(11*LargeurFenetre/30,4*(HauteurFenetre-HauteurFenetre/8)/6,15*LargeurFenetre/30,3*(HauteurFenetre-HauteurFenetre/8)/6);

	carre_noir(matrice[1][2],tab[1][2]);
	rectangle(16*LargeurFenetre/30,4*(HauteurFenetre-HauteurFenetre/8)/6,20*LargeurFenetre/30,3*(HauteurFenetre-HauteurFenetre/8)/6);

	carre_noir(matrice[1][3],tab[1][3]);
	rectangle(21*LargeurFenetre/30,4*(HauteurFenetre-HauteurFenetre/8)/6,25*LargeurFenetre/30,3*(HauteurFenetre-HauteurFenetre/8)/6);



	carre_noir(matrice[2][0],tab[2][0]);
	rectangle(6*LargeurFenetre/30,2*(HauteurFenetre-HauteurFenetre/8)/6,10*LargeurFenetre/30,(HauteurFenetre-HauteurFenetre/8)/6);

	carre_noir(matrice[2][1],tab[2][1]);
	rectangle(11*LargeurFenetre/30,2*(HauteurFenetre-HauteurFenetre/8)/6,15*LargeurFenetre/30,(HauteurFenetre-HauteurFenetre/8)/6);

	carre_noir(matrice[2][2],tab[2][2]);
	rectangle(16*LargeurFenetre/30,2*(HauteurFenetre-HauteurFenetre/8)/6,20*LargeurFenetre/30,(HauteurFenetre-HauteurFenetre/8)/6);

	carre_noir(matrice[2][3],tab[2][3]);
	rectangle(21*LargeurFenetre/30,2*(HauteurFenetre-HauteurFenetre/8)/6,25*LargeurFenetre/30,(HauteurFenetre-HauteurFenetre/8)/6); 

	}

    /**
 * \fn void carre_noir(int mat,int tab){
 * \brief dessine tout les carre en gris
 *
 * \param matrice la réponse du joueur
 * \param tab la bonne réponse
 * \return none
 */


void carre_noir(int mat,int tab){

				if((mat == 1 || mat == 0) && tab == 0){

					couleurCourante(220,220,220);

					}
				else if(mat == 1 && tab == 1){

					couleurCourante(0,0,0);

					}
				else if(mat == 0 && tab == 1){

					couleurCourante(255,0,0);

					}
}

    /**
 * \fn void init_tab(int tab[3][4])
 * \brief initialise un tableau 2 dimensions
 *
 * \param tab tableau 2 dimensions
 * \return none
 */

void init_tab(int tab[3][4]){

		for(int i = 0; i < 3;i++){

			for(int j = 0; j < 4; j++){

				tab[i][j] = 0;
			}
		}
}

    /**
 * \fn void verification(int tab[3][4])
 * \brief détecte le rectangle clické
 *
 * \param tab tableau 2 dimensions
 * \return none
 */


void verification(int tab[3][4]){


	if(abscisseSouris()>=203 && abscisseSouris()<=331 && ordonneeSouris()>=584 && ordonneeSouris()<=696){
		mod=1;
		}
	if(abscisseSouris()>=367 && abscisseSouris()<=501 && ordonneeSouris()>=584 && ordonneeSouris()<=696){
		mod=2;
		}
	if(abscisseSouris()>=535 && abscisseSouris()<=661 && ordonneeSouris()>=584 && ordonneeSouris()<=696){
		mod=3;
		}
	if(abscisseSouris()>=700 && abscisseSouris()<=831 && ordonneeSouris()>=584 && ordonneeSouris()<=696){
		mod=4;
		}
	if(abscisseSouris()>=203 && abscisseSouris()<=331 && ordonneeSouris()>=350 && ordonneeSouris()<=460){
		mod=5;
		}
	if(abscisseSouris()>=367 && abscisseSouris()<=501 && ordonneeSouris()>=350 && ordonneeSouris()<=460){
		mod=6;
		}
	if(abscisseSouris()>=535 && abscisseSouris()<=661 && ordonneeSouris()>=350 && ordonneeSouris()<=460){
		mod=7;
		}
	if(abscisseSouris()>=700 && abscisseSouris()<=831 && ordonneeSouris()>=350 && ordonneeSouris()<=460){
		mod=8;
		}
	if(abscisseSouris()>=203 && abscisseSouris()<=331 && ordonneeSouris()>=118 && ordonneeSouris()<=232){
		mod=9;
		}
	if(abscisseSouris()>=367 && abscisseSouris()<=501 && ordonneeSouris()>=118 && ordonneeSouris()<=232){
		mod=10;
		}
	if(abscisseSouris()>=535 && abscisseSouris()<=661 && ordonneeSouris()>=118 && ordonneeSouris()<=232){
		mod=11;
		}
	if(abscisseSouris()>=700 && abscisseSouris()<=831 && ordonneeSouris()>=118 && ordonneeSouris()<=232){
		mod=12;
		}


		switch(mod){
			case 1:
				tab[0][0] = 1;
				win++;
			break;
			case 2:
				tab[0][1] = 1;
				win++;
			break;
			case 3:
				tab[0][2] = 1;
			break;
			case 4:
				tab[0][3] = 1;
			break;
			case 5:
				tab[1][0] = 1;
			break;
			case 6:
				tab[1][1] = 1;
			break;
			case 7:
				tab[1][2] = 1;
			break;
			case 8:
				tab[1][3] = 1;
			break;
			case 9:
				tab[2][0] = 1;
			break;
			case 10:
				tab[2][1] = 1;
			break;
			case 11:
				tab[2][2] = 1;
			break;
			case 12:
				tab[2][3] = 1;
			break;
			}
}

    /**
 * \fn int victoire(int** matrice,int tab[3][4])
 * \brief verfifcation de la victoire
 *
 * \param tab réponses justes
 * \param matrice réponses du joueurs
 * \return 1 s'il y a victoire
 */


int victoire(int** matrice,int tab[3][4]){

	win = 0;

	for(int i = 0; i < 3;i++){

		for(int j = 0; j < 4; j++){

			if(matrice[i][j] == 1 && tab[i][j] == 1){

				win++;


			}
			else if(matrice[i][j] == 0 && tab[i][j] == 1){
				win = 13;
				}
		}
	}

	printf("%d\n",win);
	for(int i = 0; i < 3;i++){

		for(int j = 0; j < 4; j++){

			printf("%d ",matrice[i][j]);

			}

			printf("\n");

		}

	printf("\n");

	for(int i = 0; i < 3;i++){

		for(int j = 0; j < 4; j++){

			printf("%d ",tab[i][j]);

			}
			printf("\n");

		}
		return win;
	}

 
