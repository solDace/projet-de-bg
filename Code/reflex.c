/**
 * \file reflex.c
 * \brief Description des fonctions tests reflex
 * \author Thomas.B
 * \version 1.0
 * \date 21 Juin 2020
 *
 * Fonctions concernant les tests mémoire
 *
 */

#include "main.h"


/**
 * \fn void cercle(float centreX, float centreY, float rayon)
 * \brief Trace un cercle
 *
 * \param centreX,centreY coordonnées du cenre du rond
 * \param rayon rayon du cercle
 * \return none
 */

void cercle(float centreX, float centreY, float rayon)
{
	const int Pas = 20; // Nombre de secteurs pour tracer le cercle
	const double PasAngulaire = 2.*M_PI/Pas;
	int index;

	for (index = 0; index < Pas; ++index) // Pour chaque secteur
	{
		const double angle = 2.*M_PI*index/Pas; // on calcule l'angle de depart du secteur
		triangle(centreX, centreY,
				 centreX+rayon*cos(angle), centreY+rayon*sin(angle),
				 centreX+rayon*cos(angle+PasAngulaire), centreY+rayon*sin(angle+PasAngulaire));
			// On trace le secteur a l'aide d'un triangle => approximation d'un cercle
	}
}

/**
 * \fn coord Display_Circle (coord ancien)
 * \brief Affichage d'un cercle
 * \struct coord main.h Coordonnees x et y
 * \param ancien anciennes coordonnées
 * \return circle actuels coordonnées
 *
 * affiche un cercleà des coordonnées aléatoires.
 * Si les coordonnées d'entrées ne sont pas nulles, les ancienne seront conservées
 *
 */

coord Display_Circle (coord ancien){
  coord circle;
  int rayon=20;

  if(ancien.x == 0 && ancien.y==0){
    srand(time(NULL));
    circle.x=rand()%(LargeurFenetre - 40)+20;
    circle.y=rand()%(HauteurFenetre - HauteurFenetre/10 - 40)+20;
  }
  else{
    circle.x=ancien.x;
    circle.y=ancien.y;
  }
  couleurCourante(240,138,89);
  cercle(circle.x, circle.y, rayon);

  return circle;
}

/**
 * \fn int Check_Circle (coord circle)
 * \brief hitbox du cercle
 * \struct coord main.h Coordonnees x et y
 * \param coordonnées du cercle
 * \return si cliqué ou pas (=1 ou =0)
 *
 */
 
int Check_Circle(coord circle){

  int check=0;

  if(abscisseSouris() <= circle.x+20 && abscisseSouris() >= circle.x-20 && ordonneeSouris() <= circle.y+20 && ordonneeSouris() >=  circle.y-20){
    check=1;
  }
  return check;
}
