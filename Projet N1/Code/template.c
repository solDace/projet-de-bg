/**
 * \file template.c
 * \brief Description des fonctions d'affichages
 * \author Thomas.B
 * \version 1.0
 * \date 20 Juin 2020
 *
 * Fonctions d'affichage servant de template pour les différentes pages de tests
 *
 */

#include "main.h"


/**
 * \fn void Display_TestTop()
 * \brief Création du bandeau d'entête
 *
 * \param none
 * \return none
 */

void Display_TestTop(){

	static float xCoin1, yCoin1, xCoin2, yCoin2;

	xCoin1 = 0;
	yCoin1 = HauteurFenetre;
	xCoin2 = LargeurFenetre;
	yCoin2 = HauteurFenetre - HauteurFenetre/10;

	couleurCourante(220,220,220);

	rectangle( xCoin1,  yCoin1,  xCoin2,  yCoin2);


}

/**
 * \fn void Display_TestName(char* name)
 * \brief Affichage du nom de la page
 *
 * \param name nom de la page actuelle
 * \return none
 */

void Display_TestName(char* name){

		int n=0, taille;

		while (name[n] != '\0') {
			n++;
		}
		epaisseurDeTrait(2);

		couleurCourante(120,138,89);
		taille = tailleChaine(name, 20);
		afficheChaine(name,20, (LargeurFenetre - taille)/2, HauteurFenetre - HauteurFenetre/20 - 5);

}

/**
 * \fn void Display_TestScore(int score)
 * \brief Affichage du Score actuel
 *
 * \param score score actuel
 * \return none
 */

void Display_TestScore(int score){
int taille;
char ScoreText[10], text[20];

sprintf(text, "Score : ");
sprintf(ScoreText, "%d", score);


strcat(text, ScoreText);

	couleurCourante(120,138,89);
	taille = tailleChaine(text, 16);
	afficheChaine(text,16, 8*LargeurFenetre/9 - taille/2, HauteurFenetre/20 - 5);

}

/**
 * \brief Affichage temps en bas a droite
 *
 * \param structure temps
 * \return none
 */
 
void Display_TestTime(struct timeval old, struct timeval new){

int taille;
char ScoreText[10], text[20];
sprintf(text, "Time : ");
sprintf(ScoreText, "%ld s", ((long)(((( new.tv_sec - old.tv_sec) * 1000000) + new.tv_usec) - (old.tv_usec)))/1000000);


strcat(text, ScoreText);

	couleurCourante(120,138,89);
	taille = tailleChaine(text, 16);
	afficheChaine(text,16, 8*LargeurFenetre/9 - taille/2, 2 * HauteurFenetre/20 - 5);

}

/**
 * \brief affichage des conseils et du "cliquer pour commencer"
 *
 * \param nb valeur permatant de connaitre le test
 * \return none
 */
 
void Display_TestBegin(int nb){

	static float xCoin1, yCoin1, xCoin2, yCoin2;

	xCoin1 = LargeurFenetre/8;
	yCoin1 = (HauteurFenetre - HauteurFenetre/10)/6;
	xCoin2 = 7*LargeurFenetre/8;
	yCoin2 = 5*(HauteurFenetre - HauteurFenetre/10)/6;

	couleurCourante(220,220,220);

	rectangle( xCoin1,  yCoin1,  xCoin2,  yCoin2);

	int taille, taille2;

		couleurCourante(120,138,89);
		taille = tailleChaine("Cliquez sur l'ecran pour commencer", 24);
		afficheChaine("Cliquez sur l'ecran pour commencer",24, (LargeurFenetre - taille)/2, 250);
		
	switch(nb){
		
		case 1 :
			taille2= tailleChaine ("Memoriser les emplacements des carres puis les retrouver",15);
			afficheChaine("Memoriser les emplacements des carres puis les retrouver",15,LargeurFenetre/8+(6*LargeurFenetre/8-taille2)/2 , 450);
			break;
			
		case 2 :
			taille2= tailleChaine ("Une suite de couleur a retenir. Soyez pret !",15);
			afficheChaine("Une suite de couleur a retenir. Soyez pret !",15,LargeurFenetre/8+(6*LargeurFenetre/8-taille2)/2 , 450);
			
			break;
		
		case 3 :
			taille2= tailleChaine ("Cliquez sur le cercle le plus de fois possible avant la fin du temps !",15);
			afficheChaine("Cliquer sur le cercle le plus de fois possible avant la fin du temps !",15,LargeurFenetre/8+(6*LargeurFenetre/8-taille2)/2 , 450);
			break;
		case 4 :
			taille2= tailleChaine ("Presser Q ou M au bon moment, attention a ne pas perdre trop de points",15);
			afficheChaine("Presser Q ou M au bon moment, attention à ne pas perdre trop de points",15,LargeurFenetre/8+(6*LargeurFenetre/8-taille2)/2 , 450);
			break;
		case 5 :
			taille2= tailleChaine ("Est ce que la couleur correspond au mot ? Attention, ne tardez pas trop !",15);
			afficheChaine("Est ce que la couleur correspond au mot ? Attention, ne tardez pas trop !",15,LargeurFenetre/8+(6*LargeurFenetre/8-taille2)/2 , 450);
			break;
		case 6 :
			taille2= tailleChaine ("Cliquer le plus vite possible lorsque l ecran change de couleur ",15);
			afficheChaine("Cliquer le plus vite possible lorsque l ecran change de couleur",15,LargeurFenetre/8+(6*LargeurFenetre/8-taille2)/2 , 450);
			break;
		}
}

/**
 * \brief affichage du score et des boutons rejouer et quitter
 *
 * \param score le score
 * \return none
 */
 
void Display_TestEnd(int score){

	static float xCoin1, yCoin1, xCoin2, yCoin2;
	char ScoreText[10], text[30];

	sprintf(text, "Votre score est de : ");
	sprintf(ScoreText, "%d", score);


	strcat(text, ScoreText);


	xCoin1 = LargeurFenetre/8;
	yCoin1 = (HauteurFenetre - HauteurFenetre/10)/6;
	xCoin2 = 7*LargeurFenetre/8;
	yCoin2 = 5*(HauteurFenetre - HauteurFenetre/10)/6;

	couleurCourante(220,220,220);

	rectangle( xCoin1,  yCoin1,  xCoin2,  yCoin2);

	int taille;

	couleurCourante(120,138,89);
	taille = tailleChaine(text, 24);
	afficheChaine(text,24, (LargeurFenetre - taille)/2, (HauteurFenetre - HauteurFenetre/10)/2-5);

	couleurCourante(240,240,240);
	rectangle( 2*LargeurFenetre/8,  3*(HauteurFenetre - HauteurFenetre/10)/12,   3*LargeurFenetre/8,   5*(HauteurFenetre - HauteurFenetre/10)/12);
	couleurCourante(140,140,140);
	taille = tailleChaine("Quitter", 15);
	afficheChaine("Quitter", 15, 5*LargeurFenetre/16- taille/2,  4*(HauteurFenetre - HauteurFenetre/10)/12);

	couleurCourante(240,240,240);
	rectangle( 5*LargeurFenetre/8,  3*(HauteurFenetre - HauteurFenetre/10)/12,   6*LargeurFenetre/8,   5*(HauteurFenetre - HauteurFenetre/10)/12);
	couleurCourante(140,140,140);
	taille = tailleChaine("Rejouer", 15);
	afficheChaine("Rejouer", 15, 11*LargeurFenetre/16 - taille/2,   4*(HauteurFenetre - HauteurFenetre/10)/12);

}

/**
 * \brief check un clique pour commencer le test
 *
 * \param none
 * \return 1 si clique
 */
 
int Check_TestBegin(){

  int check=0;

  if(abscisseSouris() <= LargeurFenetre && abscisseSouris() >= 0 && ordonneeSouris() <= HauteurFenetre && ordonneeSouris() >= 0){
    check=1;
  }
  return check;
}

/**
 * \brief hitbox bouton quitter
 *
 * \param none
 * \return 1 si cliquer sur bouton
 */

int Check_TestQuitter(){

  int check=0;

  if(abscisseSouris() <= 3*LargeurFenetre/8 && abscisseSouris() >= 2*LargeurFenetre/8 && ordonneeSouris() <= 5*((HauteurFenetre - HauteurFenetre/10)/12) && ordonneeSouris() >=  3*(HauteurFenetre - HauteurFenetre/10)/12){
    check=1;
  }
  return check;
}

/**
 * \brief hitbox bouton rejouer
 *
 * \param none
 * \return 1 si cliquer sur bouton
 */
 
int Check_TestRejouer(){

  int check=0;

  if(abscisseSouris() <= 6*LargeurFenetre/8 && abscisseSouris() >=  5*LargeurFenetre/8 && ordonneeSouris() <= 5*((HauteurFenetre - HauteurFenetre/10)/12) && ordonneeSouris() >=  3*(HauteurFenetre - HauteurFenetre/10)/12){
    check=1;
  }
  return check;
}

/**
 * \brief sauvegarde des scores dans un fichier texte
 *
 * \param score le score
 * \param pName nom joueur
 * \param files chemin fichier
 * \return 1 fonctionne correctement, exit failure si pas reussi
 */
 
int SaveScore(int score, char pName[MAX_NAME],char files[MAX_NAME]){
	FILE *fil=NULL;
	fil=fopen(files,"ab");
	if (!fil)
		return EXIT_FAILURE;
	else{
		fseek(fil, 0, SEEK_END);
		fprintf(fil, "%s \t \t %d \n",pName,score);


		fclose(fil);
		return 1;
	}

}

/**
 * \brief permet de lire le fichier sauvegarde et d'en sortir les score
 *
 * \param score tableau avec les score 
 * \param pName nom joueur
 * \param files chemin du fichier sauvegarde 
 * \return tableau avec les score correspondant au noms en param
 */
 
int ReadScore(int score[MAX_PLAYERS], char pName[MAX_NAME],char files[MAX_NAME]){
	FILE *fil=NULL;
	fil=fopen(files,"rb");
	memset(score,0,MAX_PLAYERS);

	char name[MAX_NAME]="";

	int i=0;
	int sc=0;

	if (!fil)
		return EXIT_FAILURE;
	else{
		rewind(fil);


        while (fgetc(fil) != EOF){
			fseek(fil,-1,SEEK_CUR);
			fscanf(fil, "%s", name);
			fseek(fil,5,SEEK_CUR);
			fscanf(fil, "%d \n", &sc);

			if(strcmp(name,pName)==0){
				score[i]=sc;
				i++;
			}
		}

		fclose(fil);
		return i;
	}
}

/**
 * \brief affiche la page résultat
 *
 * \param pName nom joueur
 * \return none
 */
 
void PageResultat(char pName[MAX_NAME]){

	int D1=0,D2=0,D3=0,D4=0;

	D1=tailleChaine("Memoire",30);
	D2=tailleChaine("Reflexes",30);
	D3=tailleChaine("Synchronisation",30);
	D4=tailleChaine("Resultats",30);

	couleurCourante(210,210,210);
	rectangle(50,75,283,725);
	rectangle(383,75,616,575);
	rectangle(383,650,616,725);
	rectangle(716,75,950,725);
	rectangle(0,HauteurFenetre-30,50,HauteurFenetre);
	couleurCourante(175, 170, 169);
	triangle(2, 785, 12, 798, 12, 772);
	rectangle(10, 792, 48, 778);

	couleurCourante(0,0,0);
	afficheChaine("Memoire",30,50+(233-D1)/2,680);
	afficheChaine("Reflexes",30,383+(233-D2)/2,530);
	afficheChaine("Resultats",30,383+(233-D4)/2,680);
	afficheChaine("Synchronisation",30,716+(233-D3)/2,680);

	resTest1(pName);
	resTest2(pName);
	resTest3(pName);
	resTest4(pName);
	resTest5(pName);
	resTest6(pName);


}

/**
 * \brief affiche les résultats du test 1
 *
 * \param pName nom joueur
 * \return none
 */
 
void resTest1(char pName[MAX_NAME]){

	
	int D=tailleChaine("Simon Says",18), Tr=0, hs1=0, hs2=0, hs3=0;
	int score[MAX_TRY];
	char BS1[MAX_SCORE]="",BS2[MAX_SCORE]="",BS3[MAX_SCORE]="";
	
	couleurCourante(170,170,170);
	rectangle(75,400,258,650);

	couleurCourante(0,0,0);
	afficheChaine("Simon Says",18,75+(183-D)/2,625);
	afficheChaine("1.",12,87,575);
	afficheChaine("2.",12,87,508);
	afficheChaine("3.",12,87,442);

	Tr=ReadScore(score,pName,"../Save/TestSimon.txt");
	hs1=HS1(score,Tr);
	hs2=HS2(score,Tr,hs1);
	hs3=HS3(score,Tr,hs1,hs2);

	sprintf(BS1,"%d",hs1);
	sprintf(BS2,"%d",hs2);
	sprintf(BS3,"%d",hs3);

	afficheChaine(BS1,12,107,575);
	afficheChaine(BS2,12,107,508);
	afficheChaine(BS3,12,107,442);
	

}

/**
 * \brief affiche les résultats du test 2
 *
 * \param pName nom joueur
 * \return none
 */
 
void resTest2(char pName[MAX_NAME]){

	int D=tailleChaine("Pattern",18), Tr=0, hs1=0, hs2=0, hs3=0;
	int score[MAX_TRY];
	char BS1[MAX_SCORE]="",BS2[MAX_SCORE]="",BS3[MAX_SCORE]="";
	
	couleurCourante(170,170,170);
	rectangle(75,100,258,350);
	
	couleurCourante(0,0,0);
	afficheChaine("Pattern",18,75+(183-D)/2,325);
	afficheChaine("1.",12,87,275);
	afficheChaine("2.",12,87,208);
	afficheChaine("3.",12,87,142);

	Tr=ReadScore(score,pName,"../Save/TestPattern.txt");
	hs1=HS1(score,Tr);
	hs2=HS2(score,Tr,hs1);
	hs3=HS3(score,Tr,hs1,hs2);

	sprintf(BS1,"%d",hs1);
	sprintf(BS2,"%d",hs2);
	sprintf(BS3,"%d",hs3);

	afficheChaine(BS1,12,107,275);
	afficheChaine(BS2,12,107,208);
	afficheChaine(BS3,12,107,142);
}

/**
 * \brief affiche les résultats du test 3
 *
 * \param pName nom joueur
 * \return none
 */
 
void resTest3(char pName[MAX_NAME]){

	int D=tailleChaine("Fast click",18), Tr=0, hs1=0, hs2=0, hs3=0;
	int score[MAX_TRY];
	char BS1[MAX_SCORE]="",BS2[MAX_SCORE]="",BS3[MAX_SCORE]="";

	couleurCourante(170,170,170);
	rectangle(408,325,591,500);

	couleurCourante(0,0,0);
	afficheChaine("Fast click",18,408+(183-D)/2,475);
	afficheChaine("1.",12,420,435);
	afficheChaine("2.",12,420,395);
	afficheChaine("3.",12,420,350);

	Tr=ReadScore(score,pName,"../Save/TestBoule.txt");
	hs1=HS1(score,Tr);
	hs2=HS2(score,Tr,hs1);
	hs3=HS3(score,Tr,hs1,hs2);

	sprintf(BS1,"%d",hs1);
	sprintf(BS2,"%d",hs2);
	sprintf(BS3,"%d",hs3);

	afficheChaine(BS1,12,440,435);
	afficheChaine(BS2,12,440,395);
	afficheChaine(BS3,12,440,350);


}

/**
 * \brief affiche les résultats du test 4
 *
 * \param nom joueur
 * \return none
 */
 
void resTest4(char pName[MAX_NAME]){

	int D=tailleChaine("Reaction",18), Tr=0, hs1=0, hs2=0, hs3=0;
	int score[MAX_TRY];
	char BS1[MAX_SCORE]="",BS2[MAX_SCORE]="",BS3[MAX_SCORE]="";
	
	couleurCourante(170,170,170);
	rectangle(408,100,591,275);
	
	couleurCourante(0,0,0);
	afficheChaine("Reaction",18,408+(183-D)/2,250);
	afficheChaine("1.",12,420,210);
	afficheChaine("2.",12,420,170);
	afficheChaine("3.",12,420,130);
	
	Tr=ReadScore(score,pName,"../Save/TestReact.txt");
	hs1=MS1(score,Tr);
	hs2=MS2(score,Tr,hs1);
	hs3=MS3(score,Tr,hs1,hs2);

	sprintf(BS1,"%d",hs1);
	sprintf(BS2,"%d",hs2);
	sprintf(BS3,"%d",hs3);

	afficheChaine(BS1,12,440,210);
	afficheChaine(BS2,12,440,170);
	afficheChaine(BS3,12,440,130);
}

/**
 * \brief affiche les résultats du test 5
 *
 * \param nom joueur
 * \return none
 */
 
 
void resTest5(char pName[MAX_NAME]){
	
	int D=tailleChaine("Text Couleur",18), Tr=0, hs1=0, hs2=0, hs3=0;
	int score[MAX_TRY];
	char BS1[MAX_SCORE]="",BS2[MAX_SCORE]="",BS3[MAX_SCORE]="";
	
	couleurCourante(170,170,170);
	rectangle(741,400,924,650);
	
	couleurCourante(0,0,0);
	afficheChaine("Text Couleur",18,741+(183-D)/2,625);
	afficheChaine("1.",12,753,575);
	afficheChaine("2.",12,753,508);
	afficheChaine("3.",12,753,442);

	Tr=ReadScore(score,pName,"../Save/TestTextCouleur.txt");
	hs1=HS1(score,Tr);
	hs2=HS2(score,Tr,hs1);
	hs3=HS3(score,Tr,hs1,hs2);

	sprintf(BS1,"%d",hs1);
	sprintf(BS2,"%d",hs2);
	sprintf(BS3,"%d",hs3);

	afficheChaine(BS1,12,783,575);
	afficheChaine(BS2,12,783,508);
	afficheChaine(BS3,12,783,442);

}
/**
 * \brief affiche les résultats du test 6
 *
 * \param nom joueur
 * \return none
 */
 
void resTest6(char pName[MAX_NAME]){
	
	int D=tailleChaine("Q and M",18), Tr=0, hs1=0, hs2=0, hs3=0;
	int score[MAX_TRY];
	char BS1[MAX_SCORE]="",BS2[MAX_SCORE]="",BS3[MAX_SCORE]="";

	couleurCourante(170,170,170);
	rectangle(741,100,924,350);
	
	couleurCourante(0,0,0);
	afficheChaine("Q and M",18,741+(183-D)/2,325);
	afficheChaine("1.",12,753,275);
	afficheChaine("2.",12,753,208);
	afficheChaine("3.",12,753,142);

	Tr=ReadScore(score,pName,"../Save/TestSynchro.txt");
	hs1=HS1(score,Tr);
	hs2=HS2(score,Tr,hs1);
	hs3=HS3(score,Tr,hs1,hs2);

	sprintf(BS1,"%d",hs1);
	sprintf(BS2,"%d",hs2);
	sprintf(BS3,"%d",hs3);

	afficheChaine(BS1,12,783,275);
	afficheChaine(BS2,12,783,208);
	afficheChaine(BS3,12,783,142);

}

/**
 * \brief calcul le meilleur score parmis les score
 *
 * \param score tableau avec les scores
 * \param nb taille tableau score
 * \return meilleur score
 */
 
 
int HS1(int score[MAX_TRY],int nb){
	int hs=0;
	for(int i=0;i<nb;i++){
		if(hs<score[i]){
			hs=score[i];
		}
	}
	return hs;
}

/**
 * \brief calcul le 2nd meilleur score parmis les score
 *
 * \param hs1 meilleur score 1
 * \param nb taille tableau score
 * \param score tableau avec les scores
 * \return 2nd meilleur score
 */
 
int HS2(int score[MAX_TRY],int nb,int hs1){
	int hs=0;
	for(int i=0;i<nb;i++){
		if (score[i]!=hs1){
			if(hs<score[i]){
				hs=score[i];
			}
		}
	}
	return hs;
}

/**
 * \brief calcul le 3em meilleur score parmis les score
 *
 * \param score tableau avec les scores
 * \param hs1 meilleur score 1
 * \param hs2 meilleur score 2
 * \param nb taille tableau score
 * \return 3em meilleur score
 */
 
int HS3(int score[MAX_TRY],int nb,int hs1, int hs2){
	int hs=0;
	for(int i=0;i<nb;i++){
		if (score[i]!=hs1 && score[i]!=hs2){
			if(hs<score[i]){
				hs=score[i];
			}
		}
	}
	return hs;
}

int MS1(int score[MAX_TRY],int nb){
	int hs=9999999;
	for(int i=0;i<nb;i++){
		if(hs>score[i]){
			hs=score[i];
		}
	}
	return hs;
}

/**
 * \brief calcul le 2nd meilleur score parmis les score
 *
 * \param hs1 meilleur score 1
 * \param nb taille tableau score
 * \param score tableau avec les scores
 * \return 2nd meilleur score
 */
 
int MS2(int score[MAX_TRY],int nb,int hs1){
	int hs=9999999;
	for(int i=0;i<nb;i++){
		if (score[i]!=hs1){
			if(hs>score[i]){
				hs=score[i];
			}
		}
	}
	return hs;
}

/**
 * \brief calcul le 3em meilleur score parmis les score
 *
 * \param score tableau avec les scores
 * \param hs1 meilleur score 1
 * \param hs2 meilleur score 2
 * \param nb taille tableau score
 * \return 3em meilleur score
 */
 
int MS3(int score[MAX_TRY],int nb,int hs1, int hs2){
	int hs=9999999;
	for(int i=0;i<nb;i++){
		if (score[i]!=hs1 && score[i]!=hs2){
			if(hs>score[i]){
				hs=score[i];
			}
		}
	}
	return hs;
}
