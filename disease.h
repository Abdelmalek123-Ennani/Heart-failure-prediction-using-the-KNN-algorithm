
#ifndef DESEASE_HEART
   #define DESEASE_HEART
   typedef struct {
   	    int desease;
   	    double distance;
   }Desease;
   
   typedef struct {
   	    int maxHr;
   	    float oldpeak;
   	    char nom[20];
   	    char prenom[20];
   	    int age;
   }Person;
   
   // fonction pour inserer les informations de la personne qu'on va vérifier si il est malade ou non
   Person insereUnNouvellePerson();
   // fonction pour printer les informations sur le projet (header)
   void printHeader();
   // fonction pour printer les information de la personne
   void printPerson(Person);
   // fonction pour Calculer la distance euclidienne
   double Euclidean(Person,int,float);
   //Fonction pour classer le patient et retourner si malade ou non
   int classifierPoint(FILE* , int , Person);
   // fonction pour supprimer les espaces ou autres caractères prédéfinis du côté gauche d'une chaîne
   char *ltrim(char*);
   // fonction pour supprimer les espaces ou autres caractères prédéfinis du côté droite d'une chaîne
   char *ltrim(char*);    
   //fonction pour supprimer les espaces et autres caractères prédéfinis des deux côtés d'une chaîne
   char *trim(char*);
#endif
