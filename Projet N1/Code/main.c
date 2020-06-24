#include "main.h"






/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement);



int main(int argc, char **argv)
{
	srand(time(NULL));
	initialiseGfx(argc, argv);

	prepareFenetreGraphique("GfxLib", LargeurFenetre, HauteurFenetre);

	/* Lance la boucle qui aiguille les evenements sur la fonction gestionEvenement ci-apres,
		qui elle-meme utilise fonctionAffichage ci-dessous */
	lanceBoucleEvenements();

	return 0;
}

/* variable désignant la page active
-2 = Connexion
0 = Menu principal
1 = Menu Mémoire
2 = Menu Réflex
21 = Test Cercle
3 = Menu Syncrhonisation
4 = Menu Résultats
*/
int page = -2;

struct timeval time_debut;
struct timeval time_actuel;
struct timeval time_niveau;


coord circle;
int check = 0; // Check:  0=pas cliqué
int score=-1;
int partie=0;
int saving=0;

int listen=1;

char name[MAX_NAME]="";
char text;

int pattern[MAX_PATTERN];
int niveau = 1;
int avancee;

coul couleurecrit[4];
char tabbleu[4];
char tabrouge[5];
char tabvert[4];
char tabnoir[4];
char ecritcouleur[4][6]={"bleu","vert","rouge","noir"};
int c , ce;

int active;

/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement)
{
	static bool pleinEcran = false; // Pour savoir si on est en mode plein ecran ou pas
	static DonneesImageRGB *image = NULL; // L'image a afficher au centre de l'ecran



	switch (evenement)
	{
		case Initialisation:
			active =rand()%2 +4;
			/* Le message "Initialisation" est envoye une seule fois, au debut du
			programme : il permet de fixer "image" a la valeur qu'il devra conserver
			jusqu'a la fin du programme : soit "image" reste a NULL si l'image n'a
			pas pu etre lue, soit "image" pointera sur une structure contenant
			les caracteristiques de l'image "imageNB.bmp" */

			// Configure le systeme pour generer un message Temporisation
			// toutes les 20 millisecondes
			demandeTemporisation(20);
			//initecritcouleur(ecritcouleur, tabbleu, tabrouge, tabvert, tabnoir);
			initcouleurecrit(couleurecrit);
			break;

		case Temporisation:

			// il faut redessiner la fenetre :
			rafraichisFenetre();
			break;

		case Affichage:

			// On part d'un fond d'ecran blanc
			effaceFenetre (255, 255, 255);

			switch (page) {

				case -2:
						if(partie==0){
							Display_MsgAccueil();
						}
						if(partie==1){

							Display_MsgBienvenue(name);
						}
				break;
				case 0:
					traceMenu(name);
					break;
				case 1:
					menuMem();
					break;
				case 11:
gettimeofday(&time_actuel, NULL);

			Display_TestTop();
			Display_TestName("Test du Pattern");
			if(partie==0){
				Display_TestBegin();
			}
			else if(partie==1){

				Display_TestMemoire(partie);


				if (pattern[avancee]!=0) {
					Display_ColorButtons(pattern[avancee]);
				}
				else{
					partie++;
					avancee=0;
}
				if(/* (unsigned long) difftime( time_actuel, time_niveau )*/ (long)(  ((( time_actuel.tv_sec - time_niveau.tv_sec) * 1000000) + time_actuel.tv_usec) - (time_niveau.tv_usec))/1000000 >= 1){
					Display_ColorButtons(0);




				if((long)(  ((( time_actuel.tv_sec - time_niveau.tv_sec) * 1000000) + time_actuel.tv_usec) - (time_niveau.tv_usec)) >= 1200000 ){
					if(avancee!=MAX_PATTERN){
						avancee++;
					}
					else{
						partie++;
						avancee = 0;
					}
					gettimeofday(&time_niveau, NULL);
				}
			}


				Display_TestScore(score);

			}
			else if(partie==2){



				Display_ColorButtons(0);

				Display_TestScore(score);

			}
			else{
				Display_TestEnd(score);
				if(saving==0){
					SaveScore(score,name,"../Save/TestPattern.txt");
					saving=1;
				}

			}
			Display_TestMemoire(partie);
					break;
				case 12:

					break;
				case 13:

					break;
				case 2:
					menuFlex();
					break;
				case 21:
					Display_TestTop();
					Display_TestName("Test du cercle");
					if(partie==0){
						Display_TestBegin();
					}
					else if(partie==1){
				gettimeofday(&time_actuel, NULL);
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
				if(  (long)(  ((( time_actuel.tv_sec - time_debut.tv_sec) * 1000000) + time_actuel.tv_usec) - (time_debut.tv_usec))/1000000 >= 15){
							partie++;
						}
					}
					else{
						Display_TestEnd(score);
						if(saving==0){
						SaveScore(score,name,"../Save/TestBoule.txt");
						saving=1;
					}


					}
					break;
				case 22:

					break;
				case 23:

					break;
				case 3:
					menuSync();
					break;

				case 31:
		gettimeofday(&time_actuel, NULL);

			Display_TestTop();
			Display_TestName("Test de synchro");

			switch (partie) {
				case 0:
				Display_TestBegin();
				break;
				case 1:
				Display_TestScore(score);
					display_command(partie);
				if(  (long)(  ((( time_actuel.tv_sec - time_debut.tv_sec) * 1000000) + time_actuel.tv_usec) - (time_debut.tv_usec))/1000000 >= 3){
					partie++;
					gettimeofday(&time_debut, NULL);
				}
				break;
				case 2:
					display_command(active);
	listen=1;
	time_actuel.tv_sec = time_actuel.tv_sec -10;
				Display_TestTime(time_actuel, time_debut);
					time_actuel.tv_sec = time_actuel.tv_sec +10;

				Display_TestScore(score);
if(  (long)(  ((( time_actuel.tv_sec - time_debut.tv_sec) * 1000000) + time_actuel.tv_usec) - (time_debut.tv_usec))/1000000 >= 10){
	partie++;
}
				break;
				case 3:
				listen=0;
					Display_TestEnd(score);
					
						if(saving==0){
						SaveScore(score,name,"../Save/Synchro.txt");
						saving=1;
					}
				break;
			}
					break;
				case 32:
				
				Display_TestTop();
					Display_TestName("Test du TextCouleur");
					if(partie==0){
						Display_TestBegin();
					}
					else if(partie==1){
				gettimeofday(&time_actuel, NULL);
				afficheJF();
				affecritcouleur(ecritcouleur,c,ce,couleurecrit);	
					
						
						if(  (long)(  ((( time_actuel.tv_sec - time_niveau.tv_sec) * 1000000) + time_actuel.tv_usec) - (time_niveau.tv_usec))/1000000 >= 2){
							ce=rand()%4;
							c=rand()%4;
						
						gettimeofday(&time_niveau, NULL);
							
						}
						
						
						Display_TestScore(score);
						Display_TestTime(time_debut, time_actuel);
				if(  (long)(  ((( time_actuel.tv_sec - time_debut.tv_sec) * 1000000) + time_actuel.tv_usec) - (time_debut.tv_usec))/1000000 >= 30){
							partie++;
						}
					}
					else{
						Display_TestEnd(score);
						if(saving==0){
						SaveScore(score,name,"../Save/TextCouleur.txt");
						saving=1;
					}


					}

					break;
				case 33:

					break;
				case 4:
					PageResultat(name);
					break;
				case 888:
					page=-2;
					listen=1;
					strcpy(name,"");
					break;
					
				case 999:
				
					libereDonneesImageRGB(&image); /* On libere la structure image,
					c'est plus propre, meme si on va sortir du programme juste apres */
					termineBoucleEvenements();
					break;
			}


			break;

		case Clavier:
			printf("%c : ASCII %d\n", caractereClavier(), caractereClavier());

		if(listen!=1){
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
				
			}
		}
		else{
			if(page == -2){
				if(partie==0){
					text = caractereClavier();
					if(caractereClavier()==13){
						partie++;
					}
					else
					strncat(name, &text, 1);
				}

				else if(partie ==1){
					page=0;
					partie=0;
					listen=0;
				}
			}
			if(page==31){
				if(CheckSynchro(active)==1){
					 score++;
					 active = rand()%2 +4;
				 }
				else if(CheckSynchro(active)==2){
					 score= score-2;
					 active = rand()%2 +4;
				 }
			}
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
						page = checkMem();
						break;
					case 11:
						if(partie==0){
					check = Check_TestBegin();
					if (check==1) {
						partie++;
						gettimeofday(&time_debut, NULL);
						gettimeofday(&time_niveau, NULL);
						score = 0;
						niveau = 1;
						Create_Random_Pattern(pattern, niveau);
						avancee=0;
					}
				}
				else if(partie==1){

				}
				else if(partie ==2){
					printf("niveau = %d\n",niveau );
					printf("partie = %d\n",partie );
					printf("avancee = %d\n",avancee );
					printf("pattern[avancee] = %d\n", pattern[avancee]);
					if(check_Pattern(pattern[avancee])==1){
						score++;
						avancee++;
						if(pattern[avancee]==0){
	 							partie--;
	 							avancee=0;
	 							niveau ++;
	 							Create_Random_Pattern(pattern, niveau);
	 							gettimeofday(&time_niveau, NULL);
	 					}
					}
					else{
						partie++;
						niveau=1;
						avancee=0;
						Create_Random_Pattern(pattern, niveau);

					}

				}
				else{
					if (Check_TestQuitter()==1) {
						page = 2;
						partie = 0;
						score = -1;
						saving=0;
						avancee=0;
						niveau=1;
					}
					else if (Check_TestRejouer()==1) {
						partie = 1;
						score = 0;
						gettimeofday(&time_niveau, NULL);
						gettimeofday(&time_debut, NULL);

						saving=0;
						avancee=0;
						niveau=1;
					}

				}
						break;
					case 2:
						page = checkFlex();
						break;
					case 21:
						check = Check_Circle(circle);


					if(partie==0){
						check = Check_TestBegin();
						if (check==1) {
							partie++;
						gettimeofday(&time_debut, NULL);
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
						gettimeofday(&time_debut, NULL);
							saving=0;

						}

					}
						break;
					case 22:

						break;
					case 23:

						break;
					case 3:
						page = checkSync();
						partie=0;
						score=0;
						break;

					case 31:
	if(partie==0){
					check = Check_TestBegin();
					if (check==1) {
						partie ++;
						gettimeofday(&time_debut, NULL);
						score=0;
					}
				}
				else if(partie==1){


				}
				else if(partie==2){

 				


				}
				else{
					if (Check_TestQuitter()==1) {
						page = 3;
						partie = 0;
						score = -1;
						saving=0;
					}
					else if (Check_TestRejouer()==1) {
						partie = 1;
						score = 0;
						gettimeofday(&time_debut, NULL);
						saving=0;

					}

				}
						break;
					case 32:
					
					if(partie==0){
						check = Check_TestBegin();
						if (check==1) {
							partie++;
							ce=rand()%4;
							c=rand()%4;
						gettimeofday(&time_debut, NULL);
						gettimeofday(&time_niveau, NULL);
						}
					}
					else if(partie==1){
						if (point_duocouleur( c , ce)==1) {
							score++;
							gettimeofday(&time_niveau, NULL);
							ce=rand()%4;
							c=rand()%4;
						}
						else if (point_duocouleur( c , ce)==-1) {
							score--;
							gettimeofday(&time_niveau, NULL);
							ce=rand()%4;
							c=rand()%4;
						}
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
						gettimeofday(&time_debut, NULL);
							saving=0;

						}

					}

						break;
					case 33:

						break;
					case 4:
						page = CheckLeave();
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
