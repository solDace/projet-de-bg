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
#include <time.h> // Pour pouvoir utiliser srand() et time()


#include "../lib/BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "../lib/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "../lib/ESLib.h" // Pour utiliser valeurAleatoire()


// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 1000
#define HauteurFenetre 800
#define MAX_TRY 200
#define MAX_NAME 30
#define MAX_PLAYERS 50

typedef struct  coord{
	int x;
	int y;
}coord;

void traceMenu();
int checkMenu();

void Display_TestTop();
void Display_TestName(char* name);
void Display_TestScore(int score);
void Display_TestTime(time_t old, time_t new);
void Display_TestBegin();
coord Display_Circle (coord ancien);
void Display_TestEnd(int score);
// Fonction de trace de cercle
void cercle(float centreX, float centreY, float rayon);


int Check_Circle(coord circle);
int Check_TestBegin();
int Check_TestQuitter();
int Check_TestRejouer();


void resTest1(char pName[MAX_NAME]);
void resTest2(char pName[MAX_NAME]);
void resTest3(char pName[MAX_NAME]);
void resTest4(char pName[MAX_NAME]);
void resTest5(char pName[MAX_NAME]);
void resTest6(char pName[MAX_NAME]);
void PageResultat();


int ReadScore(int score[MAX_PLAYERS], char pName[MAX_NAME],char files[MAX_NAME]);
int SaveScore(int score, char pName[MAX_NAME],char files[MAX_NAME]);
