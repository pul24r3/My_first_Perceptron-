#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 typedef struct 
{
    float poids[2];
    float TauxDapprentissage;
    float biais;
} perceptron;

//Initialisation du perceptron 
void perceptron_init(perceptron* myson){
    srand(time(NULL));
    for (int  i = 0; i < 2; i++)
    {
        myson->poids[i]=(float)rand()/RAND_MAX;
    }
    myson->biais=(float)rand()/RAND_MAX;   
    myson->TauxDapprentissage = 0.1;  // Définir un taux d'apprentissage
}

// Fonction d'activation . Ici, j'utilise une fonction sueil
void fonction_d_activation(perceptron* myson,int DonnéesDentrainement[4][2],int *perceptron_output ){
    float somme;

    for (int i = 0; i < 4; i++)
    {
        somme=0;
        for (int  j = 0; j < 2; j++)
        {
          somme+= DonnéesDentrainement[i][j]*myson->poids[j];
        }
          somme+= myson->biais;// Ajout du biais 

        // Application de la fonction d'activation (sueil)
        if (somme>=0)
        {
            perceptron_output[i]=1;
        }else
        {
            perceptron_output[i]=0;
        }
        
        
    }
}

//Fonction d'apprentissage 
void apprentissage(perceptron* myson, int perceptron_output[4], int DonnéesDentrainement[4][2], int sortie[4])
{
    int erreur;
    for (int  i = 0; i < 4; i++)
    {
        erreur=sortie[i]- perceptron_output[i];
        for ( int j = 0; j < 2; j++)
        {
        //ajuster les poids 
            myson->poids[j]+= myson->TauxDapprentissage*erreur*DonnéesDentrainement[i][j];
        }
       // ajuster le biais 
        myson->biais+=myson->TauxDapprentissage*erreur;
    }
}


int main(){
    perceptron monperceptron;

   //initialisation du perceptron 
   perceptron_init(&monperceptron);

   // Données d'entrainements AND
   int DonnéesAND[4][2] = 
   {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1}
   };
   //Sortie attendue pour la porte AND 
   int sorties[4] = {0, 0, 0, 1};
   int perceptron_output[4];
   
   //Boucle d'entrainement 
   for (int  epoque  = 0; epoque  < 100; epoque++)
   {
    //Calcule de la sortie du pperceptron pour chaque exemple 
    fonction_d_activation(&monperceptron,DonnéesAND,perceptron_output);
   
    //mettre à jours le perceptron en fonction de l'erreur 
    apprentissage(&monperceptron,perceptron_output,DonnéesAND,sorties);
   }

   //Affichage des resultats apres l'apprentissage 
    printf("Sorties du perceptron après apprentissage :\n");
    for (int i = 0; i < 4; i++) 
    {
        printf("Entrée : (%d, %d) -> Sortie calculée : %d (attendue : %d)\n", DonnéesAND[i][0], DonnéesAND[i][1], perceptron_output[i], sorties[i]);
    }

    return 0;
}