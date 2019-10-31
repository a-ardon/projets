#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void remplissage_tbl(int *tbl, int taille_tbl)
{
	for(int i = 0; i < taille_tbl; i++)
	{
		tbl[i] = rand() % 10 + 1;
	}
}

void badsort(int *tbl, int taille_tbl)
{
	int i,j,rang_max,temp;
	for(i = 0; i < taille_tbl; i++)
	{
		rang_max = i;
		for(j = i + 1; j < taille_tbl; j++)
		{
			if(tbl[j] > tbl[rang_max])
			{
				rang_max = j;
			}
		}
		temp = tbl[i];
		tbl[i] = tbl[rang_max];
		tbl[rang_max] = temp;
	}
}

void affichage_tbl(int *tbl, int taille_score)
{
	for(int i = 0; i < taille_score; i++)
	{
		printf("%d\n",tbl[i]);
	}
	printf("\n");
}

void determine_position(int *tbl, int *tbl_score_alice, int taille_tbl)
{
	int i,j, meilleur_rang_obtenu;
	for(i = 0; i < taille_tbl; i++)
	{
		for(j = taille_tbl - 1; j >= 0; j--)
		{
			if(tbl[j] < tbl_score_alice[i])
			{
				meilleur_rang_obtenu = j;
			}
		}
		printf("%d\n",meilleur_rang_obtenu);
	}
}

void main()
{
	srand(time(NULL));
	int taille_tbl;
	scanf("%d",&taille_tbl);
	printf("\n");
	int *tbl = malloc(sizeof(int)*taille_tbl), *tbl_score_alice = malloc(sizeof(int) * taille_tbl);
	remplissage_tbl(tbl,taille_tbl);
	remplissage_tbl(tbl_score_alice,taille_tbl);
	badsort(tbl,taille_tbl);
	affichage_tbl(tbl,taille_tbl);
	affichage_tbl(tbl_score_alice,taille_tbl);
	determine_position(tbl,tbl_score_alice,taille_tbl);
	free(tbl);
	free(tbl_score_alice);
}