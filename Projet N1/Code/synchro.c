/**
 * \file memoire.c
 * \brief Description des fonctions pour les test synchro
 * \author Thomas.B
 * \version 1.0
 * \date 25 Juin 2020
 *
 * Fonction traitant des test synchro
 *
 */

#include "main.h"

/**
 * \fn void Display_command (int mode)
 * \brief affiche rectangle et "Q" et "M" pour le test "Q and M"
 *
 * \param variable permetant de savoir quoi afficher (Q ou M ou les deux)
 * \return none
 */
 
 
void display_command(int mode){

    if(mode==4 || mode==1){
    couleurCourante(220, 220, 220);

	rectangle( LargeurFenetre/6 ,  2*(HauteurFenetre - HauteurFenetre/10)/5,  3*LargeurFenetre/6 - 20,  4*(HauteurFenetre - HauteurFenetre/10)/5);
  	int taille;

		couleurCourante(120,138,89);
		taille = tailleChaine("Q", 24);
		afficheChaine("Q",24, 4*LargeurFenetre/12 - taille/2, 3*(HauteurFenetre - HauteurFenetre/10)/5-5);

}
  



    if(mode==5 || mode==1){


    couleurCourante(220, 220, 220);

rectangle( 3*LargeurFenetre/6 +20,  2*(HauteurFenetre - HauteurFenetre/10)/5,  5*LargeurFenetre/6 ,  4*(HauteurFenetre - HauteurFenetre/10)/5);
  int taille;

		couleurCourante(120,138,89);
		taille = tailleChaine("M", 24);
		afficheChaine("M",24, 8*LargeurFenetre/12 - taille/2, 3*(HauteurFenetre - HauteurFenetre/10)/5-5);

 }


}

/**
 * \fn int CheckSynchro (int mode)
 * \brief presse les bonne touches
 *
 * \param variable permetant de savoir si M ou Q sont affiche
 * \return si la bonne touche a bien été pressée
 */
 
int CheckSynchro(int mode){


  int check=0;


  if(mode==4 && (caractereClavier()=='Q'|| caractereClavier()=='q')){
    check=1;
  }
 if(mode==5 && (caractereClavier()=='Q'|| caractereClavier()=='q')){
    check=2;
  }
   if(mode==5 && (caractereClavier()=='M' ||caractereClavier()=='m' )){
    check=1;
  }
   if(mode==4 && (caractereClavier()=='M' ||caractereClavier()=='m' )){
    check=2;
  }
  return check;

}

/**
 * \brief initalisation de tableau avec les mots indiquant les couleurs
 *
 * \param tableau
 * \return none
 */

void initabbleu(char tabbleu[]){
	tabbleu[0]='b';
	tabbleu[1]='l';
	tabbleu[2]='e';
	tabbleu[3]='u';
}

/**
 * \brief initalisation de tableau avec les mots indiquant les couleurs
 *
 * \param tableau
 * \return none
 */

void initabrouge(char tabrouge[]){
	tabrouge[0]='r';
	tabrouge[1]='o';
	tabrouge[2]='u';
	tabrouge[3]='g';
	tabrouge[4]='e';
}

/**
 * \brief initalisation de tableau avec les mots indiquant les couleurs
 *
 * \param tableau
 * \return none
 */

void initabvert(char tabvert[]){
	tabvert[0]='v';
	tabvert[1]='e';
	tabvert[2]='r';
	tabvert[3]='t';
}

/**
 * \brief initalisation de tableau avec les mots indiquant les couleurs
 *
 * \param tableau
 * \return none
 */

void initabnoir(char tabnoir[]){
	tabnoir[0]='n';
	tabnoir[1]='o';
	tabnoir[2]='i';
	tabnoir[3]='r';
}

/**
 * \brief initalisation du tableau avec les données RGB propres a chaques couleur
 *
 * \param tableau avec les données RGB
 * \return none
 */


void initcouleurecrit(coul couleurecrit[]){
	
	couleurecrit[0].b = 255;
	couleurecrit[0].g = 0;
	couleurecrit[0].r = 0;
	
	couleurecrit[1].b = 0;
	couleurecrit[1].g = 255;
	couleurecrit[1].r = 0;
	
	couleurecrit[2].b = 0;
	couleurecrit[2].g = 0;
	couleurecrit[2].r = 255;
	
	couleurecrit[3].b = 0;
	couleurecrit[3].g = 0;
	couleurecrit[3].r = 0;
	
}

/**
 * \brief affichage du mot avec une certaine couleur
 * 
 *
 * \param tableau
 * \return none
 */
 
void affecritcouleur(char ecritcouleur[4][6],int c, int ce, coul couleurecrit[]){
	
	epaisseurDeTrait(3);

	couleurCourante(couleurecrit[ce].r,couleurecrit[ce].g,couleurecrit[ce].b);
	afficheChaine(ecritcouleur[c],100, 400, 400);
	
	
}

/**
 * \brief initalisation du tableau avec les données RGB propres a chaques couleur
 *
 * \param la couleur et le mot
 * \return -1 si faux +1 si vrai
 */
 
int point_duocouleur(int c , int ce){
	int point=0;
	
	if(c==ce && abscisseSouris() <= 150 && abscisseSouris() >= 0 && ordonneeSouris() <= 720 && ordonneeSouris() >=  0){
		point=1;
	}
	
	else if (c!=ce && abscisseSouris() <= 150 && abscisseSouris() >= 0 && ordonneeSouris() <= 720 && ordonneeSouris() >=  0){
		point=-1;
	}
	
	else if (c!=ce && abscisseSouris() <= 1000 && abscisseSouris() >= 850 && ordonneeSouris() <= 720 && ordonneeSouris() >=  0){
		point=1;
	}
	
	else if (c==ce && abscisseSouris() <= 1000 && abscisseSouris() >= 850 && ordonneeSouris() <= 720 && ordonneeSouris() >=  0){
		point=-1;
	}
	
	
	return point;
	
}

/**
 * \brief affichage des boutons "juste" et "faux"
 *
 * \param none
 * \return none
 */
 
void afficheJF(){
	
	couleurCourante(0, 128, 255);
	rectangle(0, 0, 150, 720);
	
	couleurCourante(0, 0, 0);
	epaisseurDeTrait(2);
	afficheChaine("juste", 20, 65, HauteurFenetre/2);
	
	couleurCourante(0, 128, 255);
	rectangle(850, 100, 1000, 720);
	couleurCourante(0, 0, 0);
	
	epaisseurDeTrait(2);
	afficheChaine("faux", 20, 915, HauteurFenetre/2);
	
}

