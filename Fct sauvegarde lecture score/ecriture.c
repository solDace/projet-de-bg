#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_NAME 50
#define MAX_PLAYERS 50
#define MAX_SCORE 50

/*typedef struct Players{
	char name[MAX_NAME];
	int score[MAX_SCORE];
}players;*/


int SaveScore(int score, char pName[MAX_NAME]);



int SaveScore(int score, char pName[MAX_NAME]){
	FILE *fil=NULL;
	fil=fopen("test.txt","ab");
	if (!fil)
		return EXIT_FAILURE;
	else{
		fseek(fil, 0, SEEK_END);
		fprintf(fil, "%s \t \t %d \n",pName,score);

		
		fclose(fil);
		return 1;
	}

}




int main() {
	
	char name[50]="JP";
	int sc=35;
	int fc=0;
	int score[MAX_PLAYERS];
	memset(score,0,MAX_PLAYERS);
	
	
	fc=SaveScore(sc,name);
	
	sc=478;
	char name2[50]="LOL";
	
	fc=SaveScore(sc,name2);
	
	
	return 0;
}
