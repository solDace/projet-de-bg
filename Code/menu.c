#include "main.h"


/**
 * \file menu.c
 * \brief Fonctions affichage des menus et leur hitbox.
 * \author Thomas.B
 * \version 1.0
 * \date 25 Juin 2020
 *
 */
 
 
 /**
 * \fn void traceMenu (char pName [MAX_NAME])
 * \brief Affichage menu principal
 *
 * \param Nom de la personne connectée
 * \return none
 */
 

void traceMenu(char pName[MAX_NAME]) {
	float taille2, taille3, taille4,taille5,taille6,taille7;
	//triangle central
	couleurCourante(213, 136, 120);
	triangle(375, 400, 625, 400, 500, 200);
	//triangle haut
	couleurCourante(175, 170, 169);
	triangle(375, 400, 625, 400, 500, 600);
	//triangle droite
	couleurCourante(183, 248, 125);
	triangle(500, 200, 625, 400, 750, 200);
	//triangle gauche
	couleurCourante(114, 192, 231);
	triangle(500, 200, 375, 400, 250, 200);
	couleurCourante(214, 214, 214);
	//rectangle d'affichage du texte
	rectangle(300, 800, 700, 750);
	//titre
	Display_TestTop();
	Display_TestName("Test Checker");
	//bouton quitter
	couleurCourante(220,220,220);
	rectangle(LargeurFenetre-60,0,LargeurFenetre,40);
	//bouton identification
	couleurCourante(220,220,220);
	rectangle(0,0,80,40);
	//bouton connecté
	couleurCourante(220,220,220);
	rectangle(300,100,700,150);
	//titre triangle haut
	couleurCourante(0, 0, 0);
	taille2 = tailleChaine("Memoire", 24);
	afficheChaine("Memoire", 24, (LargeurFenetre - taille2)/2, 462);
	//titre triangle central
	couleurCourante(0, 0, 0);
	taille3 = tailleChaine("Resultats", 24);
	afficheChaine("Resultats", 24, (LargeurFenetre - taille3)/2, 312);
	//titre triangle droite
	couleurCourante(0, 0, 0);
	afficheChaine("Reflexes", 24, 580, 262);
	//titre triangle gauche
	couleurCourante(0, 0, 0);
	afficheChaine("Synchro", 24, 322, 262);
	//titre quitter
	couleurCourante(0, 0, 0);
	taille4 = tailleChaine("Quitter", 15);
	afficheChaine("Quitter", 15,(LargeurFenetre-60)+(60-taille4)/2, 15);
	//titre identification
	couleurCourante(0, 0, 0);
	taille5 = tailleChaine("Identification", 12);
	afficheChaine("Identification", 12,(80-taille5)/2, 15);
	//titre Connecté
	couleurCourante(0, 0, 0);
	taille6 = tailleChaine("Connecte en tant que :", 15);
	taille7 = tailleChaine(pName, 15);
	afficheChaine("Connecte en tant que :", 15,300+(400-(taille6+taille7+15))/2, 120);
	afficheChaine(pName, 15,(300+(400-(taille6+taille7))/2)+taille6+15, 120);
}

/**
 * \fn int checkMenu ()
 * \brief hitbox menu principal
 *
 * \param none
 * \return adresse de la page choisie
 */
 
int checkMenu() {
	int active = 0;
	//triangle memoire
	if(abscisseSouris() >= 375 && abscisseSouris() <= 625 && ordonneeSouris() >= 400 && ordonneeSouris() <= 600) {
		active = 1;
		printf("Menu Mémoire\n");
	}
	//triangle Reflexes
	if(ordonneeSouris() <= 310 && ordonneeSouris() >= 200 && abscisseSouris() >= 570 && abscisseSouris() <= 750) {
		active = 2;
		printf("Menu Réflexes\n");
	}
	//triangle synchro
	if(ordonneeSouris() <= 310 && ordonneeSouris() >= 200 && abscisseSouris() >= 250 && abscisseSouris() <= 430) {
		active = 3;
		printf("Menu Synchro\n");
	}
	//triangle Resultats
	if(abscisseSouris() >= 440 && ordonneeSouris() >= 300 && abscisseSouris() <= 550 && ordonneeSouris() <= 350){
		active = 4;
		printf("Menu Résultats\n");
	}
	if(abscisseSouris() <= 593 && ordonneeSouris() >= 350 && abscisseSouris() >= 409 && ordonneeSouris() <= 400){
		active = 4;
		printf("Menu Résultats\n");
	}
	//bouton quitter
	if(abscisseSouris() <= LargeurFenetre && ordonneeSouris() >= 0 && abscisseSouris() >= LargeurFenetre-60 && ordonneeSouris() <= 40){
		active = 999;
		printf("Programme fermé\n");
	}
	//bouton identification
	if(abscisseSouris() <= 80 && ordonneeSouris() >= 0 && abscisseSouris() >= 0 && ordonneeSouris() <= 40){
		active = 888;
		printf("Choix d'un nouvel identifiant...\n");
	}
	
	return active;
}

 /**
 * \fn void menuFlex ()
 * \brief Affichage menu reflex
 *
 * \param none
 * \return none
 */
 
void menuFlex() {
	float taille;
	//bandeau
	Display_TestTop();
	Display_TestName("Menu Reflexes");
	//triangle central
	couleurCourante(213, 136, 120);
	triangle(375, 500, 625, 500, 500, 300);
	//triangle gauche
	couleurCourante(175, 170, 169);
	triangle(400, 200, 275, 400, 150, 200);
	//triangle droite
	couleurCourante(183, 248, 125);
	triangle(600, 200, 725, 400, 850, 200);
	//titre triangle central
	couleurCourante(0, 0, 0);
	taille = tailleChaine("Fast Click", 24);
	afficheChaine("Fast Click", 24, (LargeurFenetre - taille)/2, 422);
	//titre triangle gauche
	couleurCourante(0, 0, 0);
	afficheChaine("Test 2", 24, 232, 262);
	//titre triangle droite
	couleurCourante(0, 0, 0);
	afficheChaine("Resultats", 24, 682, 262);
	//bouton retour
	couleurCourante(210, 210, 210);
	rectangle(0, 710, 50, 680);
	couleurCourante(175, 170, 169);
	triangle(2, 695, 12, 708, 12, 682);
	rectangle(10, 702, 48, 688);
}

 /**
 * \fn int checkFlex()
 * \brief hitbox menu reflex
 *
 * \param none
 * \return adresse page choisie
 */
 
int checkFlex() {
	int active = 2;
	//triangle central
	if(abscisseSouris() >= 375 && abscisseSouris() <= 625 && ordonneeSouris() <= 500 && ordonneeSouris() >= 300) {
		active = 21;
		printf("Vers Fast Click\n");
	}
	//triangle gauche
	if(ordonneeSouris() <= 310 && ordonneeSouris() >= 200 && abscisseSouris() >= 570 && abscisseSouris() <= 750) {
		active = 4;
		printf("Vers Résultats\n");
	}
	//triangle droite
	if(ordonneeSouris() <= 310 && ordonneeSouris() >= 200 && abscisseSouris() >= 250 && abscisseSouris() <= 430) {
		active = 22;
		printf("Vers Test 2\n");
	}
	//bouton retour
	if(abscisseSouris() <= 50 && abscisseSouris() >= 0 && ordonneeSouris() <= 710 && ordonneeSouris() >= 680){
		active = 0;
		printf("Vers Menu");
	}
	return active;
}

/**
 * \fn int CheckLeave ()
 * \brief hitbox boutton quitter page resultat
 *
 * \param none
 * \return adresse menu principal
 */
 
int CheckLeave() {
	int active = 4;
	//Bouton quitter
	if(abscisseSouris() >= 0 && abscisseSouris() <= 50 && ordonneeSouris() >= HauteurFenetre-30 && ordonneeSouris() <= HauteurFenetre) {
		active = 0;
		printf("Retour Menu principal\n");
	}
	return active;
}

 /**
 * \fn void menuMem ()
 * \brief Affichage menu memoire
 *
 * \param none
 * \return none
 */
 
void menuMem() {
	float taille;
	//bandeau
	Display_TestTop();
	Display_TestName("Menu Memoire");
	//triangle central
	couleurCourante(213, 136, 120);
	triangle(375, 500, 625, 500, 500, 300);
	//triangle gauche
	couleurCourante(175, 170, 169);
	triangle(400, 200, 275, 400, 150, 200);
	//triangle droite
	couleurCourante(183, 248, 125);
	triangle(600, 200, 725, 400, 850, 200);
	//titre triangle central
	couleurCourante(0, 0, 0);
	taille = tailleChaine("Simon Says", 24);
	afficheChaine("Simon Says", 24, (LargeurFenetre - taille)/2, 422);
	//titre triangle gauche
	couleurCourante(0, 0, 0);
	afficheChaine("Pattern", 24, 232, 262);
	//titre triangle droite
	couleurCourante(0, 0, 0);
	afficheChaine("Resultats", 24, 682, 262);
	//bouton retour
	couleurCourante(210, 210, 210);
	rectangle(0, 710, 50, 680);
	couleurCourante(175, 170, 169);
	triangle(2, 695, 12, 708, 12, 682);
	rectangle(10, 702, 48, 688);
}

/**
 * \fn int checkFlex()
 * \brief hitbox menu memoire
 *
 * \param none
 * \return adresse test choisie
 */
 
 
int checkMem() {
	int active = 1;
	//triangle central
	if(abscisseSouris() >= 375 && abscisseSouris() <= 625 && ordonneeSouris() <= 500 && ordonneeSouris() >= 300) {
		active = 11;
		printf("Vers Test 1\n");
	}
	//triangle gauche
	if(ordonneeSouris() <= 310 && ordonneeSouris() >= 200 && abscisseSouris() >= 570 && abscisseSouris() <= 750) {
		active = 4;
		printf("Vers Résultats\n");
	}
	//triangle droite
	if(ordonneeSouris() <= 310 && ordonneeSouris() >= 200 && abscisseSouris() >= 250 && abscisseSouris() <= 430) {
		active = 12;
		printf("Vers Pattern\n");
	}
	//bouton retour
	if(abscisseSouris() <= 50 && abscisseSouris() >= 0 && ordonneeSouris() <= 710 && ordonneeSouris() >= 680){
		active = 0;
		printf("Vers Menu");
	}
	return active;
}

/**
 * \fn void menuSync()
 * \brief Affichage menu synchro
 *
 * \param none
 * \return none
 */
 
void menuSync() {
	float taille;
	//bandeau
	Display_TestTop();
	Display_TestName("Menu Synchronisation");
	//triangle central
	couleurCourante(213, 136, 120);
	triangle(375, 500, 625, 500, 500, 300);
	//triangle gauche
	couleurCourante(175, 170, 169);
	triangle(400, 200, 275, 400, 150, 200);
	//triangle droite
	couleurCourante(183, 248, 125);
	triangle(600, 200, 725, 400, 850, 200);
	//titre triangle central
	couleurCourante(0, 0, 0);
	taille = tailleChaine("Text Couleur", 24);
	afficheChaine("Text Couleur", 24, (LargeurFenetre - taille)/2, 422);
	//titre triangle gauche
	couleurCourante(0, 0, 0);
	afficheChaine("Q et M", 24, 228, 262);
	//titre triangle droite
	couleurCourante(0, 0, 0);
	afficheChaine("Resultats", 24, 682, 262);
	//bouton retour
	couleurCourante(210, 210, 210);
	rectangle(0, 710, 50, 680);
	couleurCourante(175, 170, 169);
	triangle(2, 695, 12, 708, 12, 682);
	rectangle(10, 702, 48, 688);
}

/**
 * \fn int checkSynch ()
 * \brief hitbox menu Synchro
 *
 * \param none
 * \return adresse test choisie
 */
 
int checkSync() {
	int active = 3;
	//triangle central
	if(abscisseSouris() >= 375 && abscisseSouris() <= 625 && ordonneeSouris() <= 500 && ordonneeSouris() >= 300) {
		active = 32;
		printf("Q et M\n");
	}
	//triangle gauche
	if(ordonneeSouris() <= 310 && ordonneeSouris() >= 200 && abscisseSouris() >= 570 && abscisseSouris() <= 750) {
		active = 4;
		printf("Vers Résultats\n");
	}
	//triangle droite
	if(ordonneeSouris() <= 310 && ordonneeSouris() >= 200 && abscisseSouris() >= 250 && abscisseSouris() <= 430) {
		active = 31;
		printf("Text Couleur\n");
	}
	//bouton retour
	if(abscisseSouris() <= 50 && abscisseSouris() >= 0 && ordonneeSouris() <= 710 && ordonneeSouris() >= 680){
		active = 0;
		printf("Vers Menu");
	}
	return active;
}
