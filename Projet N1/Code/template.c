/**
 * \file template.c
 * \brief Description des fonctions d'affichages
 * \author Thomas.B
 * \version 1.0
 * \date 20 Juin 2020
 *
 * Fonctions d'affichage servant de template pour les différentes pages de tests
 *
 */

#include "main.h"


/**
 * \fn void Display_TestTop()
 * \brief Création du bandeau d'entête
 *
 * \param none
 * \return none
 */

void Display_TestTop(){

	static float xCoin1, yCoin1, xCoin2, yCoin2;

	xCoin1 = 0;
	yCoin1 = HauteurFenetre;
	xCoin2 = LargeurFenetre;
	yCoin2 = HauteurFenetre - HauteurFenetre/10;

	couleurCourante(220,220,220);

	rectangle( xCoin1,  yCoin1,  xCoin2,  yCoin2);


}

/**
 * \fn void Display_TestName(char* name)
 * \brief Affichage du nom de la page
 *
 * \param name nom de la page actuelle
 * \return none
 */

void Display_TestName(char* name){

		int n=0, taille;

		while (name[n] != '\0') {
			n++;
		}
		epaisseurDeTrait(2);

		couleurCourante(120,138,89);
		taille = tailleChaine(name, 20);
		afficheChaine(name,20, (LargeurFenetre - taille)/2, HauteurFenetre - HauteurFenetre/20 - 5);

}

/**
 * \fn void Display_TestScore(int score)
 * \brief Affichage du Score actuel
 *
 * \param score score ectuel
 * \return none
 */

void Display_TestScore(int score){
int taille;
char ScoreText[10], text[20];

sprintf(text, "Score : ");
sprintf(ScoreText, "%d", score);


strcat(text, ScoreText);

	couleurCourante(120,138,89);
	taille = tailleChaine(text, 16);
	afficheChaine(text,16, 8*LargeurFenetre/9 - taille/2, HauteurFenetre/20 - 5);

}

/**
 * \fn void Display_TestScore(int score)
 * \brief Affichage du Score actuel
 *
 * \param score score ectuel
 * \return none
 */

void Display_TestTime(time_t old, time_t new){

int taille;
char ScoreText[10], text[20];
sprintf(text, "Time : ");
unsigned long secondes = (unsigned long) difftime( new, old );
sprintf(ScoreText, "%ld s", secondes);


strcat(text, ScoreText);

	couleurCourante(120,138,89);
	taille = tailleChaine(text, 16);
	afficheChaine(text,16, 8*LargeurFenetre/9 - taille/2, 2 * HauteurFenetre/20 - 5);

}

void Display_TestBegin(){

	static float xCoin1, yCoin1, xCoin2, yCoin2;

	xCoin1 = LargeurFenetre/8;
	yCoin1 = (HauteurFenetre - HauteurFenetre/10)/6;
	xCoin2 = 7*LargeurFenetre/8;
	yCoin2 = 5*(HauteurFenetre - HauteurFenetre/10)/6;

	couleurCourante(220,220,220);

	rectangle( xCoin1,  yCoin1,  xCoin2,  yCoin2);

	int taille;

		couleurCourante(120,138,89);
		taille = tailleChaine("Cliquez sur l'ecran pour commencer", 24);
		afficheChaine("Cliquez sur l'ecran pour commencer",24, (LargeurFenetre - taille)/2, (HauteurFenetre - HauteurFenetre/10)/2-5);
}

void Display_TestEnd(int score){

	static float xCoin1, yCoin1, xCoin2, yCoin2;
	char ScoreText[10], text[30];

	sprintf(text, "Votre score est de : ");
	sprintf(ScoreText, "%d", score);


	strcat(text, ScoreText);


	xCoin1 = LargeurFenetre/8;
	yCoin1 = (HauteurFenetre - HauteurFenetre/10)/6;
	xCoin2 = 7*LargeurFenetre/8;
	yCoin2 = 5*(HauteurFenetre - HauteurFenetre/10)/6;

	couleurCourante(220,220,220);

	rectangle( xCoin1,  yCoin1,  xCoin2,  yCoin2);

	int taille;

	couleurCourante(120,138,89);
	taille = tailleChaine(text, 24);
	afficheChaine(text,24, (LargeurFenetre - taille)/2, (HauteurFenetre - HauteurFenetre/10)/2-5);

	couleurCourante(240,240,240);
	rectangle( 2*LargeurFenetre/8,  3*(HauteurFenetre - HauteurFenetre/10)/12,   3*LargeurFenetre/8,   5*(HauteurFenetre - HauteurFenetre/10)/12);
	couleurCourante(140,140,140);
	taille = tailleChaine("Quitter", 15);
	afficheChaine("Quitter", 15, 5*LargeurFenetre/16- taille/2,  4*(HauteurFenetre - HauteurFenetre/10)/12);

	couleurCourante(240,240,240);
	rectangle( 5*LargeurFenetre/8,  3*(HauteurFenetre - HauteurFenetre/10)/12,   6*LargeurFenetre/8,   5*(HauteurFenetre - HauteurFenetre/10)/12);
	couleurCourante(140,140,140);
	taille = tailleChaine("Rejouer", 15);
	afficheChaine("Rejouer", 15, 11*LargeurFenetre/16 - taille/2,   4*(HauteurFenetre - HauteurFenetre/10)/12);

}

int Check_TestBegin(){

  int check=0;

  if(abscisseSouris() <= LargeurFenetre && abscisseSouris() >= 0 && ordonneeSouris() <= HauteurFenetre && ordonneeSouris() >= 0){
    check=1;
  }
  return check;
}


int Check_TestQuitter(){

  int check=0;

  if(abscisseSouris() <= 3*LargeurFenetre/8 && abscisseSouris() >= 2*LargeurFenetre/8 && ordonneeSouris() <= 5*((HauteurFenetre - HauteurFenetre/10)/12) && ordonneeSouris() >=  3*(HauteurFenetre - HauteurFenetre/10)/12){
    check=1;
  }
  return check;
}

int Check_TestRejouer(){

  int check=0;

  if(abscisseSouris() <= 6*LargeurFenetre/8 && abscisseSouris() >=  5*LargeurFenetre/8 && ordonneeSouris() <= 5*((HauteurFenetre - HauteurFenetre/10)/12) && ordonneeSouris() >=  3*(HauteurFenetre - HauteurFenetre/10)/12){
    check=1;
  }
  return check;
}
