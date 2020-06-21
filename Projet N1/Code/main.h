/**
 * \file main.h
 * \brief Déclaration des fonctions utilisées dans main.c
 * \author Thomas.B
 * \version 1.0
 * \date 20 Juin 2020
 *
 */


#include <stdio.h>  // Pour pouvoir utiliser printf()
#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include <string.h>
#include "../lib/BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "../lib/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "../lib/ESLib.h" // Pour utiliser valeurAleatoire()


// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 1000
#define HauteurFenetre 800

void traceMenu();
int checkMenu();


void Display_TestTop();
void Display_TestName(char* name);
void Display_TestScore(int score);
