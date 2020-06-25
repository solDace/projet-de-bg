#include "main.h"

/**
 * \file accueil.c
 * \brief Description des fonctions d'affichage des pages de saisie du nom d'utilisateur
 * \author Thomas.B
 * \version 1.0
 * \date 25 Juin 2020
 *
 * Fonction concernant les pages récupérant le nom d'utilisateur
 *
 */

/**
 * \fn void Display_MsgAccueil ()
 * \brief affiche la page demandant le nom
 *
 * \param none
 * \return none
 */
 
void Display_MsgAccueil(){
int taille;
  couleurCourante(0,0,0);
  taille = tailleChaine("Quel est votre nom : ", 40);
  afficheChaine("Quel est votre nom : ", 40, (LargeurFenetre-taille)/2, HauteurFenetre/2-20);
}

/**
 * \fn void Display_MsgBienvenue ()
 * \brief affiche la page souhaitant la bienvenue à l'utilisateur
 *
 * \param nom utilisateur
 * \return none
 */
 
void Display_MsgBienvenue(char name[30]){
  char text[MAX_NAME + 15];
  sprintf(text,"Bienvenue " );
  strcat(text, name);

  int taille;
  couleurCourante(0,0,0);
  taille = tailleChaine(text, 40);
  afficheChaine(text, 40, (LargeurFenetre-taille)/2, HauteurFenetre/2-20);
}
