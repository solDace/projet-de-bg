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
 * \param score score ectuel
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

void Display_TestTime(time_t old, time_t new){

int taille;
char ScoreText[10], text[20];
sprintf(text, "Time : ");
unsigned long secondes = (unsigned long) difftime( new, old );
sprintf(ScoreText, "%ld s", secondes);


strcat(text, ScoreText);

	couleurCourante(120,138,89);
	taille = tailleChaine(text, 16);
	afficheChaine(text,16, 8*LargeurFenetre/9 - taille/2, 2 * HauteurFenetre/20 - 5);

}

void Display_TestBegin(){

	static float xCoin1, yCoin1, xCoin2, yCoin2;

	xCoin1 = LargeurFenetre/8;
	yCoin1 = (HauteurFenetre - HauteurFenetre/10)/6;
	xCoin2 = 7*LargeurFenetre/8;
	yCoin2 = 5*(HauteurFenetre - HauteurFenetre/10)/6;

	couleurCourante(220,220,220);

	rectangle( xCoin1,  yCoin1,  xCoin2,  yCoin2);

	int taille;

		couleurCourante(120,138,89);
		taille = tailleChaine("Cliquez sur l'ecran pour commencer", 24);
		afficheChaine("Cliquez sur l'ecran pour commencer",24, (LargeurFenetre - taille)/2, (HauteurFenetre - HauteurFenetre/10)/2-5);
}

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

int Check_TestBegin(){

  int check=0;

  if(abscisseSouris() <= LargeurFenetre && abscisseSouris() >= 0 && ordonneeSouris() <= HauteurFenetre && ordonneeSouris() >= 0){
    check=1;
  }
  return check;
}


int Check_TestQuitter(){

  int check=0;

  if(abscisseSouris() <= 3*LargeurFenetre/8 && abscisseSouris() >= 2*LargeurFenetre/8 && ordonneeSouris() <= 5*((HauteurFenetre - HauteurFenetre/10)/12) && ordonneeSouris() >=  3*(HauteurFenetre - HauteurFenetre/10)/12){
    check=1;
  }
  return check;
}

int Check_TestRejouer(){

  int check=0;

  if(abscisseSouris() <= 6*LargeurFenetre/8 && abscisseSouris() >=  5*LargeurFenetre/8 && ordonneeSouris() <= 5*((HauteurFenetre - HauteurFenetre/10)/12) && ordonneeSouris() >=  3*(HauteurFenetre - HauteurFenetre/10)/12){
    check=1;
  }
  return check;
}

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

			//~ strcat(name," \n");

			if(strcmp(name,pName)==0){
				score[i]=sc;
				i++;
			}
		}

		fclose(fil);
		return i;
	}
}

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

void resTest1(char pName[MAX_NAME]){

	couleurCourante(170,170,170);
	rectangle(75,400,258,650);

}

void resTest2(char pName[MAX_NAME]){

	couleurCourante(170,170,170);
	rectangle(75,100,258,350);

}

void resTest3(char pName[MAX_NAME]){

	int D=tailleChaine("Boules",18), Tr=0, hs1=0, hs2=0, hs3=0;
	int score[MAX_TRY];
	char BS1[MAX_SCORE]="",BS2[MAX_SCORE]="",BS3[MAX_SCORE]="";

	couleurCourante(170,170,170);
	rectangle(408,325,591,500);

	couleurCourante(0,0,0);
	afficheChaine("Boules",18,408+(183-D)/2,475);
	afficheChaine("1.",12,420,435);
	afficheChaine("2.",12,420,395);
	afficheChaine("3.",12,420,350);

	Tr=ReadScore(score,pName,"SaveTestBoule.txt");
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

void resTest4(char pName[MAX_NAME]){

	couleurCourante(170,170,170);
	rectangle(408,100,591,275);

}

void resTest5(char pName[MAX_NAME]){

	couleurCourante(170,170,170);
	rectangle(741,400,924,650);

}

void resTest6(char pName[MAX_NAME]){

	couleurCourante(170,170,170);
	rectangle(741,100,924,350);

}

int HS1(int score[MAX_TRY],int nb){
	int hs=0;
	for(int i=0;i<nb;i++){
		if(hs<score[i]){
			hs=score[i];
		}
	}
	return hs;
}

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
