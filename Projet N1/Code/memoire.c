#include "main.h"



void Display_ColorButtons(int carre){

  couleurCourante(100, 0, 0);
  rectangle(2*LargeurFenetre/15, 6*(HauteurFenetre - HauteurFenetre/10)/7,5*LargeurFenetre/15,4*(HauteurFenetre - HauteurFenetre/10)/7 );
  couleurCourante(0, 100, 0);
  rectangle(6*LargeurFenetre/15, 6*(HauteurFenetre - HauteurFenetre/10)/7,9*LargeurFenetre/15,4*(HauteurFenetre - HauteurFenetre/10)/7 );
  couleurCourante(0, 0, 100);
  rectangle(10*LargeurFenetre/15, 6*(HauteurFenetre - HauteurFenetre/10)/7,13*LargeurFenetre/15,4*(HauteurFenetre - HauteurFenetre/10)/7);


  couleurCourante(100, 100, 0);
  rectangle(2*LargeurFenetre/15, 3*(HauteurFenetre - HauteurFenetre/10)/7,5*LargeurFenetre/15,(HauteurFenetre - HauteurFenetre/10)/7 );
  couleurCourante(0, 100, 100);
  rectangle(6*LargeurFenetre/15, 3*(HauteurFenetre - HauteurFenetre/10)/7,9*LargeurFenetre/15,(HauteurFenetre - HauteurFenetre/10)/7 );
  couleurCourante(100, 0, 100);
  rectangle(10*LargeurFenetre/15, 3*(HauteurFenetre - HauteurFenetre/10)/7,13*LargeurFenetre/15,(HauteurFenetre - HauteurFenetre/10)/7 );


  switch (carre) {
    case 1:
    couleurCourante(200, 0, 0);
    rectangle(2*LargeurFenetre/15, 6*(HauteurFenetre - HauteurFenetre/10)/7,5*LargeurFenetre/15,4*(HauteurFenetre - HauteurFenetre/10)/7 );
    break;
    case 2:
    couleurCourante(0, 200, 0);
    rectangle(6*LargeurFenetre/15, 6*(HauteurFenetre - HauteurFenetre/10)/7,9*LargeurFenetre/15,4*(HauteurFenetre - HauteurFenetre/10)/7 );
    break;
    case 3:
    couleurCourante(0, 0, 200);
    rectangle(10*LargeurFenetre/15, 6*(HauteurFenetre - HauteurFenetre/10)/7,13*LargeurFenetre/15,4*(HauteurFenetre - HauteurFenetre/10)/7);
    break;
    case 4:
    couleurCourante(200, 200, 0);
    rectangle(2*LargeurFenetre/15, 3*(HauteurFenetre - HauteurFenetre/10)/7,5*LargeurFenetre/15,(HauteurFenetre - HauteurFenetre/10)/7 );
    break;
    case 5:
    couleurCourante(0, 200, 200);
    rectangle(6*LargeurFenetre/15, 3*(HauteurFenetre - HauteurFenetre/10)/7,9*LargeurFenetre/15,(HauteurFenetre - HauteurFenetre/10)/7 );
    break;
    case 6:
    couleurCourante(200, 0, 200);
    rectangle(10*LargeurFenetre/15, 3*(HauteurFenetre - HauteurFenetre/10)/7,13*LargeurFenetre/15,(HauteurFenetre - HauteurFenetre/10)/7 );
    break;
  }


}


void Display_TestMemoire(int mode){
  int taille;
	couleurCourante(140,140,140);
  if(mode ==1){
	taille = tailleChaine("Memorisez", 15);
	afficheChaine("Memorisez", 15, (LargeurFenetre - taille)/2, 4*(HauteurFenetre - HauteurFenetre/10)/7 -(HauteurFenetre - HauteurFenetre/10)/14);
}
else if(mode ==2){
  taille = tailleChaine("A ton tour", 15);
  afficheChaine("A ton tour", 15, (LargeurFenetre - taille)/2, 4*(HauteurFenetre - HauteurFenetre/10)/7 - (HauteurFenetre - HauteurFenetre/10)/14);
}
}



void Create_Random_Pattern(int tab[MAX_PATTERN], int dif){

  for(int i=0; i<dif; i++){
    tab[i]=rand()%6+1;
  }
  for(int i=dif; i<MAX_PATTERN; i++){
    tab[i]=0;
  }

}

int check_Pattern(int carre){
  int check=0;
  switch (carre) {
    case 1:
    if(abscisseSouris() >= (2*LargeurFenetre/15) && abscisseSouris() <= 5*LargeurFenetre/15 && ordonneeSouris() >= 4*(HauteurFenetre - HauteurFenetre/10)/7 && ordonneeSouris() <= 6*(HauteurFenetre - HauteurFenetre/10)/7) {
      check = 1;
    }
    break;
    case 2:
    if(abscisseSouris() >= (6*LargeurFenetre/15) && abscisseSouris() <= 9*LargeurFenetre/15 && ordonneeSouris() >= 4*(HauteurFenetre - HauteurFenetre/10)/7 && ordonneeSouris() <= 6*(HauteurFenetre - HauteurFenetre/10)/7) {
      check = 1;
    }
    break;
    case 3:
    if(abscisseSouris() >= (10*LargeurFenetre/15) && abscisseSouris() <= 13*LargeurFenetre/15 && ordonneeSouris() >= 4*(HauteurFenetre - HauteurFenetre/10)/7 && ordonneeSouris() <= 6*(HauteurFenetre - HauteurFenetre/10)/7) {
      check = 1;
    }
    break;
    case 4:
    if(abscisseSouris() >= (2*LargeurFenetre/15) && abscisseSouris() <= 5*LargeurFenetre/15 && ordonneeSouris() >= (HauteurFenetre - HauteurFenetre/10)/7 && ordonneeSouris() <= 3*(HauteurFenetre - HauteurFenetre/10)/7) {
      check = 1;
    }
    break;
    case 5:
    if(abscisseSouris() >= (6*LargeurFenetre/15) && abscisseSouris() <= 9*LargeurFenetre/15 && ordonneeSouris() >= (HauteurFenetre - HauteurFenetre/10)/7 && ordonneeSouris() <= 3*(HauteurFenetre - HauteurFenetre/10)/7) {
      check = 1;
    }
    break;
    case 6:
    if(abscisseSouris() >= (10*LargeurFenetre/15) && abscisseSouris() <= 13*LargeurFenetre/15 && ordonneeSouris() >= (HauteurFenetre - HauteurFenetre/10)/7 && ordonneeSouris() <= 3*(HauteurFenetre - HauteurFenetre/10)/7) {
      check = 1;
    }
    break;
    case 0:
      check = 2;
     break;
  }

  return check;
}
