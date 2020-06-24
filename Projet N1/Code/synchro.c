/*
*/

#include "main.h"


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



void initabbleu(char tabbleu[]){
	tabbleu[0]='b';
	tabbleu[1]='l';
	tabbleu[2]='e';
	tabbleu[3]='u';
}

void initabrouge(char tabrouge[]){
	tabrouge[0]='r';
	tabrouge[1]='o';
	tabrouge[2]='u';
	tabrouge[3]='g';
	tabrouge[4]='e';
}

void initabvert(char tabvert[]){
	tabvert[0]='v';
	tabvert[1]='e';
	tabvert[2]='r';
	tabvert[3]='t';
}

void initabnoir(char tabnoir[]){
	tabnoir[0]='n';
	tabnoir[1]='o';
	tabnoir[2]='i';
	tabnoir[3]='r';
}


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


void affecritcouleur(char ecritcouleur[4][6],int c, int ce, coul couleurecrit[]){
	
	epaisseurDeTrait(3);

	couleurCourante(couleurecrit[ce].r,couleurecrit[ce].g,couleurecrit[ce].b);
	afficheChaine(ecritcouleur[c],100, 400, 400);
	
	
}

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

void afficheJF(){
	
	couleurCourante(0, 128, 255);
	rectangle(0, 0, 150, 720);
	
	couleurCourante(0, 0, 0);
	epaisseurDeTrait(2);
	afficheChaine("just", 20, 65, HauteurFenetre/2);
	
	couleurCourante(0, 128, 255);
	rectangle(850, 100, 1000, 720);
	couleurCourante(0, 0, 0);
	
	epaisseurDeTrait(2);
	afficheChaine("faux", 20, 915, HauteurFenetre/2);
	
}

