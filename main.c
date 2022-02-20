#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include "disease.h"
#define MAX 918
#include "Knn-funcs.c"

int main() {
    depart :
    system("cls");
    FILE *data;
    printHeader();
    Person newPerson = insereUnNouvellePerson();
    int k = 5; // nombre of data points
    int res;
    data = fopen("./heart.csv" , "r");
    res =  classifierPoint(data  , k , newPerson);
    
	printf("\t\t--------------------------------------\n");
    if ( res == 0 ) {
    	printPerson(newPerson);
    	printf("\t\t\tResultat : Il a pas de maladie cardiaque");
	}else {
		printPerson(newPerson);
		printf("\t\t\tResultat : On s'attend à ce qu'il souffre d'une maladie cardiaque");
	}
	
	int num;
	printf("\n\n\t\t\entrer 0 pour entrer un autre personne : ");
	scanf("%d", &num);
	
	if( num == 0 ) goto depart;
	return 0;
}

