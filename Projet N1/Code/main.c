#include "main.h"






/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement);



int main(int argc, char **argv)
{
	initialiseGfx(argc, argv);

	prepareFenetreGraphique("GfxLib", LargeurFenetre, HauteurFenetre);

	/* Lance la boucle qui aiguille les evenements sur la fonction gestionEvenement ci-apres,
		qui elle-meme utilise fonctionAffichage ci-dessous */
	lanceBoucleEvenements();

	return 0;
}

/* variable désignant la page active
0 = Menu principal
1 = Menu Mémoire
2 = Menu Réflex
21 = Test Cercle
3 = Menu Syncrhonisation
4 = Menu Résultats
*/
int page = 0;

time_t time_debut = 0;
time_t time_actuel= 0;

coord circle;
int check = 0; // Check:  0=pas cliqué
int score=-1;
int partie=0;
int saving=0;

/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement)
{
	static bool pleinEcran = false; // Pour savoir si on est en mode plein ecran ou pas
	static DonneesImageRGB *image = NULL; // L'image a afficher au centre de l'ecran



	switch (evenement)
	{
		case Initialisation:

			/* Le message "Initialisation" est envoye une seule fois, au debut du
			programme : il permet de fixer "image" a la valeur qu'il devra conserver
			jusqu'a la fin du programme : soit "image" reste a NULL si l'image n'a
			pas pu etre lue, soit "image" pointera sur une structure contenant
			les caracteristiques de l'image "imageNB.bmp" */

			// Configure le systeme pour generer un message Temporisation
			// toutes les 20 millisecondes
			demandeTemporisation(20);
			break;

		case Temporisation:

			// il faut redessiner la fenetre :
			rafraichisFenetre();
			break;

		case Affichage:

			// On part d'un fond d'ecran blanc
			effaceFenetre (255, 255, 255);
			//~ PageResultat();

			switch (page) {
				case 0:
					traceMenu();
					break;
				case 1:
					
					break;
				case 2:

					break;
				case 4:
					PageResultat();
					break;
				case 21:
	Display_TestTop();
					Display_TestName("Test du cercle");
					if(partie==0){
						Display_TestBegin();
					}
					else if(partie==1){
						time_actuel = time(NULL);
						if(check ==0)
						circle = Display_Circle (circle);
						else{
							circle.x = 0;
							circle.y = 0;
							circle = Display_Circle (circle);
							check=0;
							score ++;
						}
						Display_TestScore(score);
						Display_TestTime(time_debut, time_actuel);
						if( (unsigned long) difftime( time_actuel, time_debut ) >= 15){
							partie++;
						}
					}
					else{
						Display_TestEnd(score);
						if(saving==0){
						SaveScore(score,"JP","SaveTestBoule.txt");
						saving=1;
					}
						

					}
					break;
				case 22:

					break;
				case 23:

					break;

				case 31:

					break;
				case 32:

					break;
				case 33:

					break;
			}


			break;

		case Clavier:
			printf("%c : ASCII %d\n", caractereClavier(), caractereClavier());

			switch (caractereClavier())
			{
				case 'Q': /* Pour sortir quelque peu proprement du programme */
				case 'q':
					libereDonneesImageRGB(&image); /* On libere la structure image,
					c'est plus propre, meme si on va sortir du programme juste apres */
					termineBoucleEvenements();
					break;

				case 'F':
				case 'f':
					pleinEcran = !pleinEcran; // Changement de mode plein ecran
					if (pleinEcran)
						modePleinEcran();
					else
						redimensionneFenetre(LargeurFenetre, HauteurFenetre);
					break;

				case 'R':
				case 'r':
					// Configure le systeme pour generer un message Temporisation
					// toutes les 20 millisecondes (rapide)
					demandeTemporisation(20);
					break;

				case 'L':
				case 'l':
					// Configure le systeme pour generer un message Temporisation
					// toutes les 100 millisecondes (lent)
					demandeTemporisation(100);
					break;

				case 'S':
				case 's':
					// Configure le systeme pour ne plus generer de message Temporisation
					demandeTemporisation(-1);
					break;
				case 't':
                    if(page==2){
                    page=21;
                }
                    else if(page ==21)
                    page=2;
                    break;
			}
			break;

		case ClavierSpecial:
			printf("ASCII %d\n", toucheClavier());
			break;

		case BoutonSouris:
			if (etatBoutonSouris() == GaucheAppuye)
			{
				printf("Bouton gauche appuye en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());

				//Switch pour les différentes fonctions check

				switch (page) {
					case 0:
						page = checkMenu();
						break;
					case 1:

						break;
					case 2:

						break;
					case 21:
						check = Check_Circle(circle);


					if(partie==0){
						check = Check_TestBegin();
						if (check==1) {
							partie++;
							time_debut = time(NULL);
						}
					}
					else if(partie==1){
						check = Check_Circle(circle);

					}
					else{
						if (Check_TestQuitter()==1) {
							page = 2;
							partie = 0;
							score = -1;
							saving=0;
						}
						else if (Check_TestRejouer()==1) {
							partie = 1;
							score = 0;
							time_debut = time(NULL);
							saving=0;

						}
						
					}
						break;
					case 22:
	
						break;
					case 23:

						break;

					case 31:

						break;
					case 32:

						break;
					case 33:

						break;
				}
			}
			else if (etatBoutonSouris() == GaucheRelache)
			{
				printf("Bouton gauche relache en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
			}
			break;

		case Souris: // Si la souris est deplacee
			break;

		case Inactivite: // Quand aucun message n'est disponible
			break;

		case Redimensionnement: // La taille de la fenetre a ete modifie ou on est passe en plein ecran
			// Donc le systeme nous en informe

			printf("Largeur : %d\t", largeurFenetre());
			printf("Hauteur : %d\n", hauteurFenetre());
			break;
	}
}
