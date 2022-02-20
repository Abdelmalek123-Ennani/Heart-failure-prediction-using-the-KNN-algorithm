//print header
void printHeader() {
	system("COLOR 0A");
	printf("\t\t\t\t ------------------------------------------------ \n");
	Sleep(600);
	system("COLOR 3");
	printf("\t\t\t\t | Ecole normale d'enseignement technique ENSET | \n");
	Sleep(600);
	system("COLOR 5");
	printf("\t\t\t\t |                 Mohammedia                   | \n");
	Sleep(600);
	system("COLOR 6");
	printf("\t\t\t\t |          Annee Scolaire :  2021/2022         | \n");
	Sleep(600);
	system("COLOR 7");
	printf("\t\t\t\t |          Langage C : KNN project             | \n");
	Sleep(600);
	system("COLOR 8");
	printf("\t\t\t\t |                Realise par:                  | \n");
	Sleep(600);
	system("COLOR 9");
	printf("\t\t\t\t |             ENNANI Abdelmalek                | \n");
	Sleep(600);
	system("COLOR B");
    printf("\t\t\t\t |             DOUHI Chaimae                    | \n");
	Sleep(600);
	system("COLOR E");
    printf("\t\t\t\t |                GLSID-1                       | \n");
	Sleep(600);
	system("COLOR 0A");
	printf("\t\t\t\t ------------------------------------------------ \n");
	Sleep(600);
	printf("\n\n");
	printf("\t\t--------------------------------------------------------------------------------------\n");
	Sleep(600);
	printf("\t\tEnsemble de donnees de prediction d'insuffisance cardiaque utilisant l'algorithme KNN\n");
	Sleep(600);
	printf("\t\t-------------------------------------------------------------------------------------\n\n");
	Sleep(600);
	printf("\t\t------------------------------------ Informations -----------------------------------\n");
	Sleep(600);
	printf("\t\tLe programme vous demandera des informations sur la personne, pour vérifier si il est \n\
	\tmalade ou non, y compris ces informations suivants : \n\n");
	Sleep(600);
	printf("\t\t\t->maxHr : La frequence cardiaque maximale\n");
	Sleep(600);
	printf("\t\t\t->oldPeak : depression induced by exercise relative to rest (must be between -2.6 and 6.2)\n");
	Sleep(600);
	printf("\t\t--------------------------------------------------------------------------------------\n\n");
	
	Sleep(1000);
}

// fonction pour inserer les données de la patient
	Person insereUnNouvellePerson() {
	Person newPerson;
	char nom[20] , prenom[20];
	int maxHr , age;
	float oldPeak;
	printf("\t\t---------------------------------------------------------------------------------------\n");
	printf("\t\t------------------- Veilluez entrer les information de la personne :------------------ \n");
	printf("\t\t---------------------------------------------------------------------------------------\n");
	printf("\t\t\tEntrer Le nom de la person : ");
	scanf("%s" , nom);
    
   	printf("\t\t\tEntrer Le prenom de la person : ");
	scanf("%s" , prenom);
	
	printf("\t\t\tEntrer L'age de la personne : ");
	scanf("%d" , &age);
    
    printf("\t\t--------------------------------------------- \n"); 
    printf("\t\t\tEntrer Oldpeak (Depression induite par l'exercice par rapport au repos (-2.6 - 6.2)) : ");
    scanf("%f" , &oldPeak);
    
    printf("\t\t\tEntrer maxHr (maximum heart rate achieved) : ");
    scanf("%d" , &maxHr);

    strcpy(newPerson.nom , nom);
    strcpy(newPerson.prenom , prenom);
    newPerson.age = age;
    newPerson.oldpeak = oldPeak;
    newPerson.maxHr = maxHr;
    
    return newPerson;
}


// print newPers information
void printPerson(Person newPerson) {
	printf("\t\tLa personne evec les informations suivant : \n");
	printf("\t\t\tNom : %s\n", newPerson.nom);
	printf("\t\t\tPrenom : %s\n", newPerson.prenom);
	printf("\t\t\tAge : %d\n", newPerson.age);
	printf("\t\t\tmaxHr : %d\n", newPerson.maxHr);
	printf("\t\t\toldPeak : %.1f\n", newPerson.oldpeak);
}

// Euclidean function pour calculer la distance
double Euclidean(Person newPers ,int maxHr , float oldpeak) {
	return sqrt(
	    (maxHr - newPers.maxHr) * (maxHr - newPers.maxHr) +
	    (oldpeak - newPers.oldpeak) * (oldpeak - newPers.oldpeak)
	);
}

// function for ltrim
char *ltrim(char *s)
{
    while(isspace(*s)) s++;
    return s;
}

// fnction for rtrim
char *rtrim(char *s)
{
    char* back = s + strlen(s);
    while(isspace(*--back));
    *(back+1) = '\0';
    return s;
}

// function trim
char *trim(char *s)
{
    return rtrim(ltrim(s)); 
}


// classifier le patient et retourner si il est malade ou non
int classifierPoint(FILE *data , int k,Person newPers) {
	char test[255];   //pour stocker le contenue de chaque ligne de fichier
	Desease arr[MAX]; //Pour stocker chaque personne et la distance entre lui et la personne que nous étudions
	Desease Point;    
	fgets(test , 255 , data);  // sauter la première ligne du fichier
	int j=0;
	while(fgets(test , 255 , data)) {
		char *piece = strtok(test , ","); // divise la chaîne de caractères en une série de jetons à l'aide du délimiteur delim ","
		int i=0;
		int maxHr , yesNo; // yesNo : 1 => malade || 0 => n'est pas malade
		float oldpeak;   
	    while (piece = strtok(NULL , ",")) {
	    	i++;
	    	if( i == 7) {
	    	   maxHr = atoi(piece);
			} else if ( i == 9 ) {
			   oldpeak = (float)atof(piece);
			} else if ( i == 11) {
			   yesNo = atoi(trim(piece));
//			   printf("la distance est : %f\n" , Euclidean(newPers , maxHr , oldpeak));
			   Point.desease = yesNo;
			   Point.distance = Euclidean(newPers , maxHr , oldpeak);
			   arr[j] = Point;
			   j++;
			}
		}
	}
	
	// trier le tableaux
	int h , c;
	Desease valTemp;
	for ( h=0 ; h<MAX ; h++ ) {
		for( c=1 ; c<MAX ; c++) {
			if ( arr[h].distance < arr[c].distance ) {
				valTemp = arr[c];
				arr[c] = arr[h];
				arr[h] = valTemp;
			}
		}
	}

	
	// get le nombre dominant
	int fre1= 0 ,fre2 = 0 , i;
	for ( i=0 ; i<k ; i++ ) {
		if(arr[i].desease == 0) {
			fre1++;
		}
	}
	
	// return a number (0: n'est pas un patient cardiaque 1:patient cardiaque)
	return fre1 >= 3 ? 0 : 1;
}
