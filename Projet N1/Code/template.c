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
