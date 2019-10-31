#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void remplissage_tbl(int *tbl, int taille_tbl)
{
	for(int i = 0; i < taille_tbl; i++)
	{
		tbl[i] = i + 1;
	}
}

void affichage_tbl(int *tbl, int taille_tbl)
{
	for(int i = 0; i < taille_tbl; i++)
	{
		printf("%d ",tbl[i]);
	}
	printf("\n");
}

void effectue_swap(int *tbl, int taille_tbl, int rang_element1, int rang_element2)
{
	int temp = tbl[rang_element1];
	tbl[rang_element1] = tbl[rang_element2];
	tbl[rang_element2] = temp;
}

void effectue_permutations(int *tbl, int taille_tbl, int nbr_permutations)
{
	for(int i = 0; i < nbr_permutations; i++)
	{
		if(i != 0)
		{
			printf("\n");
			affichage_tbl(tbl,taille_tbl);
			printf("\n");
		}
		int element_a_permuter = rand()%(taille_tbl-2) + 2, size_swap = rand()%2 + 1;
		printf("permutation element rang %d (%d) avec element rang %d (%d) | size_swap : %d\n",element_a_permuter,tbl[element_a_permuter],element_a_permuter - size_swap,tbl[element_a_permuter-size_swap],size_swap);
		effectue_swap(tbl,taille_tbl,element_a_permuter,element_a_permuter-size_swap);	
	}
	printf("\n");
}

/* 
   retourne le distance_swap le plus petit pour obtenir un array tel qu'obtenu en fin de programme
   il se peut donc que le distance_swap soit plus petit que le nombre de swaps effectuees au total par la
   fonction effectue permutations.

   ex :

   tableau d'origine     : 1 2 3 4 5
   
   swap de tbl[2] (=3) avec tbl[0] (=1) => 2 swaps necessaires

   tableau intermediaire : 3 2 1 4 5

   swap de tbl[2] (=1) avec tbl[1] (=2) => 1 swap necessaire

   tableau final         : 3 1 2 4 5

   on aurait pu obtenir le meme resultat en effectuant un swap de tbl[2] avec tbl[0] puis de tbl[1] avec le nouveau tbl[2] (2 swaps)

   tableau obtenu :      : 3 1 2 4 5 (== au tableau final) 

   d'ou on distance_swap == 2

*/

int determine_et_retourne_distance_swap(int *tbl, int taille_tbl)
{
	int distance_swap = 0;
	for(int i = 0; i < taille_tbl; i++)
	{
		if(tbl[i] > (i+1))
		{
			distance_swap = distance_swap + ((tbl[i]) - (i+1));
		}
	}
	return distance_swap;
}

int main()
{
	srand(time(NULL));
	int taille_tbl, nbr_permutations;
	scanf("%d",&taille_tbl);
	nbr_permutations = (rand()%taille_tbl) / 2;
	printf("\ntaille_tbl : %d\n\nNBR PERMUTATIONS : %d\n\n",taille_tbl,nbr_permutations);
	int *tbl = malloc(sizeof(int)*taille_tbl);
	remplissage_tbl(tbl,taille_tbl);
	affichage_tbl(tbl,taille_tbl);
	printf("\n");
	effectue_permutations(tbl,taille_tbl,nbr_permutations);
	affichage_tbl(tbl,taille_tbl);
	printf("\nDISTANCE SWAPS FINALE : %d\n",determine_et_retourne_distance_swap(tbl,taille_tbl));
	free(tbl);
	return 0;
}