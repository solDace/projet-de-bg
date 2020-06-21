#include "main.h"

void traceMenu() {
	float taille1, taille2, taille3;
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
	couleurCourante(0, 0, 0);
	taille1 = tailleChaine("Test Checker", 32);
	afficheChaine("Test Checker", 32, (LargeurFenetre - taille1)/2, 762);
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
}

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
	return active;
}
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
	afficheChaine("Test 3", 24, 682, 262);
	//bouton retour
	couleurCourante(210, 210, 210);
	rectangle(0, 710, 50, 680);
	couleurCourante(175, 170, 169);
	triangle(2, 695, 12, 708, 12, 682);
	rectangle(10, 702, 48, 688);
}

int checkFlex() {
	int active = 0;
	//triangle central
	if(abscisseSouris() >= 375 && abscisseSouris() <= 625 && ordonneeSouris() <= 500 && ordonneeSouris() >= 300) {
		active = 21;
		printf("Vers Fast Click\n");
	}
	//triangle gauche
	if(ordonneeSouris() <= 310 && ordonneeSouris() >= 200 && abscisseSouris() >= 570 && abscisseSouris() <= 750) {
		active = 2;
		printf("Vers Test 2\n");
	}
	//triangle droite
	if(ordonneeSouris() <= 310 && ordonneeSouris() >= 200 && abscisseSouris() >= 250 && abscisseSouris() <= 430) {
		active = 3;
		printf("Vers Test 3\n");
	}
	//bouton retour
	if(abscisseSouris() <= 50 && abscisseSouris() >= 0 && ordonneeSouris() <= 710 && ordonneeSouris() >= 680){
		active = 0;
		printf("Vers Menu");
	}
	return active;
}
