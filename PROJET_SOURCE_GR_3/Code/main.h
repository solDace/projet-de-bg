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
#include <sys/time.h> // Pour pouvoir utiliser srand() et time()


#include "../lib/BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "../lib/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "../lib/ESLib.h" // Pour utiliser valeurAleatoire()


// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 1000
#define HauteurFenetre 800
#define MAX_TRY 200
#define MAX_NAME 30
#define MAX_PLAYERS 50
#define MAX_SCORE 50
#define MAX_PATTERN 8


typedef struct  coord{
	int x;
	int y;
}coord;

typedef struct couleur
{ 
	
	int r;
	int g;
	int b;
	
	
}coul;

void traceMenu(char pName[MAX_NAME]);
int checkMenu();
void menuFlex();
int checkFlex();
int CheckLeave();
void menuMem();
int checkMem();
void menuSync();
int checkSync();

void Display_TestTop();
void Display_TestName(char* name);
void Display_TestScore(int score);
void Display_TestTime(struct timeval old, struct timeval new);
void Display_TestBegin(int nb);
coord Display_Circle (coord ancien);
void Display_TestEnd(int score);
void Display_MsgAccueil();
void Display_MsgBienvenue(char *name);
void Display_ColorButtons();
void Create_Random_Pattern(int tab[MAX_PATTERN], int dif);
void Display_TestMemoire(int mode);

void display_command(int );
int CheckSynchro(int mode);

// Fonction de trace de cercle
void cercle(float centreX, float centreY, float rayon);

void initabbleu(char tabbleu[]);
void initabrouge(char tabrouge[]);
void initabvert(char tabvert[]);
void initabnoir(char tabnoir[]);
void initcouleurecrit(coul couleurecrit[]);
void affecritcouleur(char ecritcouleur[4][6],int c, int ce, coul couleurecrit[]);
int point_duocouleur(int c , int ce);
void afficheJF();

int Check_Circle(coord circle);
int Check_TestBegin();
int Check_TestQuitter();
int Check_TestRejouer();
int check_Pattern(int );


void resTest1(char pName[MAX_NAME]);
void resTest2(char pName[MAX_NAME]);
void resTest3(char pName[MAX_NAME]);
void resTest4(char pName[MAX_NAME]);
void resTest5(char pName[MAX_NAME]);
void resTest6(char pName[MAX_NAME]);
void PageResultat(char pName[MAX_NAME]);


int ReadScore(int score[MAX_PLAYERS], char pName[MAX_NAME],char files[MAX_NAME]);
int SaveScore(int score, char pName[MAX_NAME],char files[MAX_NAME]);
int HS1(int score[MAX_TRY],int nb);
int HS2(int score[MAX_TRY],int nb,int hs1);
int HS3(int score[MAX_TRY],int nb,int hs1, int hs2);
int MS1(int score[MAX_TRY],int nb);
int MS2(int score[MAX_TRY],int nb,int hs1);
int MS3(int score[MAX_TRY],int nb,int hs1, int hs2);

void initabbleu(char tabbleu[]);
void initabrouge(char tabrouge[]);
void initabvert(char tabvert[]);
void initabnoir(char tabnoir[]);
void initcouleurecrit(coul couleurecrit[]);
void affecritcouleur(char ecritcouleur[4][6],int c, int ce, coul couleurecrit[]);
int point_duocouleur(int c , int ce);
void afficheJF();


int** chasard();
int nbr_one_matrice(int **matrice);
void init_tab(int tab[3][4]);
void freefct2(int **matrice);
int compte_zero(int** matrice);
void init_carre(int **matrice);
void carre_gris(int** matrice,int tab[3][4]);
void carre_noir(int mat,int tab);
void verification(int tab[3][4]);
int victoire(int** matrice,int tab[3][4]);
