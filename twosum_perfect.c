#include <stdio.h> 
#include <time.h>
#include <stdlib.h>

void remplissage_tbl(int *tbl, int taille)
{
	for(int i = 0; i < taille; i++)
	{
		tbl[i] = rand() % 10;
	}
}

void affichage_tbl(int *tbl, int taille)
{
	for(int i = 0; i < taille; i++)
	{
		printf("%d\n",tbl[i]);
	}
	printf("\n");
}


void main()
{
	srand(time(NULL));
	int taille = 10, random_number = rand() % 10;
	int *tbl_1 = malloc(sizeof(int)*taille);
	int *tbl_2 = malloc(sizeof(int)*taille);
	remplissage_tbl(tbl_1,taille);
	remplissage_tbl(tbl_2,taille);
	affichage_tbl(tbl_1,taille);
	affichage_tbl(tbl_2,taille);
	free(tbl_1);
	free(tbl_2);
}

