
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
   
   // fonction pour inserer les informations de la personne qu'on va v�rifier si il est malade ou non
   Person insereUnNouvellePerson();
   // fonction pour printer les informations sur le projet (header)
   void printHeader();
   // fonction pour printer les information de la personne
   void printPerson(Person);
   // fonction pour Calculer la distance euclidienne
   double Euclidean(Person,int,float);
   //Fonction pour classer le patient et retourner si malade ou non
   int classifierPoint(FILE* , int , Person);
   // fonction pour supprimer les espaces ou autres caract�res pr�d�finis du c�t� gauche d'une cha�ne
   char *ltrim(char*);
   // fonction pour supprimer les espaces ou autres caract�res pr�d�finis du c�t� droite d'une cha�ne
   char *ltrim(char*);    
   //fonction pour supprimer les espaces et autres caract�res pr�d�finis des deux c�t�s d'une cha�ne
   char *trim(char*);
#endif
