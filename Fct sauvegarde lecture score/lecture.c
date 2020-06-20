#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_PLAYERS 50
#define MAX_SCORE 50

int ReadScore(int score[MAX_PLAYERS], char pName[MAX_NAME]);

int ReadScore(int score[MAX_PLAYERS], char pName[MAX_NAME]){
	FILE *fil=NULL;
	fil=fopen("test.txt","rb");
	memset(score,0,MAX_PLAYERS);
	
	char name[MAX_NAME]="";
	char chaine[MAX_NAME] = "";
	
	int i=0, u=0;
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


int main() {
	
	char name[50]="JP";
	char name2[50]="LOL";
	int fc=0;
	int score[MAX_PLAYERS];
	memset(score,0,MAX_PLAYERS);
	
	
	fc=ReadScore(score,name);
	printf("Voici les score de J1 : \n");
	for (int i=0;i<fc;i++){
		printf("%d \n", score[i]);
	}
	
	fc=ReadScore(score,name2);
	printf("Voici les score de J2 : \n");
	for (int i=0;i<fc;i++){
		printf("%d \n", score[i]);
	}
	
	return 0;
}
