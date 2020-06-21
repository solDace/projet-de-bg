#include "main.h"

void Display_MsgAccueil(){
int taille;
  couleurCourante(0,0,0);
  taille = tailleChaine("Quel est votre nom : ", 40);
  afficheChaine("Quel est votre nom : ", 40, (LargeurFenetre-taille)/2, HauteurFenetre/2-20);
}

void Display_MsgBienvenue(char name[30]){
  char text[MAX_NAME + 15];
  sprintf(text,"Bienvenue " );
  strcat(text, name);

  int taille;
  couleurCourante(0,0,0);
  taille = tailleChaine(text, 40);
  afficheChaine(text, 40, (LargeurFenetre-taille)/2, HauteurFenetre/2-20);
}
