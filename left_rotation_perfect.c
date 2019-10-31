#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void affichage_tbl(int *tbl, int taille_tbl)
{
	for(int i = 0; i < taille_tbl; i++)
	{
		printf("%d\n",tbl[i]);
	}
}

void effectue_rotation(int *tbl, int taille_tbl)
{
	int temp1, temp2;
	for(int i = taille_tbl - 1; i >= 0; i--)
	{
		if(i == taille_tbl - 1)
		{
			temp1 = tbl[i];
			tbl[i] = tbl[0];
		}
		else
		{
			temp2 = tbl[i];
			tbl[i] = temp1;
			temp1 = temp2;
		}
	}
}

void remplissage_tbl(int *tbl, int taille_tbl)
{
	for(int i = 0; i < taille_tbl; i++)
	{
		tbl[i] = i + 1;
	}
}

void effectue_N_rotations(int *tbl, int taille_tbl, int nbr_rotations)
{
	int nbr_rotations_optimise = nbr_rotations % taille_tbl;
	if(nbr_rotations_optimise != 0)
	{
		for(int i = 0; i < nbr_rotations; i++)
		{
			effectue_rotation(tbl,taille_tbl);
			if(i != nbr_rotations - 1)
			{
				printf("rotation #%d :\n\n",i+1);
				affichage_tbl(tbl,taille_tbl);
				printf("\n");
			}
			else
			{
				printf("rotation #%d (FINALE):\n\n",i+1);
				affichage_tbl(tbl,taille_tbl);
			}
		}
	}
	else
	{
		printf("résultat pour %d rotations déjà obtenu.\n",nbr_rotations);
	}
}

int main()
{
	srand(time(NULL));
	int taille_tbl = rand()%4 + 6;
	int *tbl = malloc(sizeof(int)*taille_tbl);
	remplissage_tbl(tbl,taille_tbl);
	printf("taille tbl : %d\n\n",taille_tbl);
	affichage_tbl(tbl,taille_tbl);
	printf("\n");  
	int nbr_rotations = taille_tbl / 2;
	effectue_N_rotations(tbl,taille_tbl,nbr_rotations);
	free(tbl);
	return 0;
}