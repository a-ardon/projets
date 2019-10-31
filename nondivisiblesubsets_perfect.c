#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int verif_presence(int *tbl, int taille_so_far)
{
	for(int i = 0; i < taille_so_far; i++)
	{
		for(int j = 0; j < taille_so_far; j++)
		{
			if((i != j) && (tbl[i] == tbl[j]))
			{
				return 1;
			}
		}
	}
	return 0;
}

void remplissage_tbl(int *tbl, int taille_tbl)
{
	for(int i = 0; i < taille_tbl; i++)
	{
		tbl[i] = rand()%taille_tbl;
		if(i != 0)
		{
			while(verif_presence(tbl,i + 1) == 1)
			{
				printf("hit (%d)\n",tbl[i]);
				tbl[i] = rand()%taille_tbl;
			}
		}
	}
}

void affichage_tbl(int *tbl, int taille)
{
	printf("\n");
	for(int i = 0; i < taille; i++)
	{
		printf("%d\n",tbl[i]);
	}
}

int verif_presence2(int *tbl, int taille, int element)
{
	for(int i = 0; i < taille; i++)
	{
		if(tbl[i] == element)
		{
			return 1;
		}
	}
	return 0;
}

int remplissage_matrice(int **matrice, int *tbl, int taille_tbl, int *meilleur)
{
	int i,j,k,somme_courante = 0,somme_max,compteur = 1,taille_meilleur;
	for(i = 0; i < taille_tbl; i++)
	{
		matrice[i] = malloc(sizeof(int)*taille_tbl);
		matrice[i][0] = tbl[i];
		somme_courante = matrice[i][0];
		for(j = 0; j < taille_tbl; j++)
		{
			if(((verif_presence2(matrice[i],compteur,tbl[j]) == 0) && ((somme_courante+tbl[j])%2 == 0)))
			{
				matrice[i][compteur] = tbl[j];
				somme_courante = somme_courante + tbl[j];
				compteur = compteur + 1;
			}
		}
		if(i == 0)
		{
			somme_max = somme_courante;
			*meilleur = i;
			taille_meilleur = compteur;
		}
		else if(somme_courante > somme_max)
		{
			somme_max = somme_courante;
			*meilleur = i;
			taille_meilleur = compteur;
		}
		compteur = 1;
	}
	return taille_meilleur;
}

int affichage_special(int **matrice, int taille_meilleur, int meilleur)
{
	int somme = 0;
	for(int i = 0; i < taille_meilleur; i++)
	{
		printf("%d\n",matrice[meilleur][i]);
		somme = somme + matrice[meilleur][i];
	}
	printf("\n");
	return somme;

}

void main()
{
	srand(time(NULL));
	int taille_tbl, meilleur = 0;
	taille_tbl = rand()%4+ 4;
	printf("taille tbl : %d\n\n",taille_tbl);
	int *tbl = malloc(sizeof(int)*taille_tbl);
	remplissage_tbl(tbl,taille_tbl);
	affichage_tbl(tbl,taille_tbl);
	printf("\n\n");
	int **matrice = malloc(sizeof(int*)*taille_tbl);
	int taille_meilleur = remplissage_matrice(matrice,tbl,taille_tbl,&meilleur);
	int somme_divisible_par_2 = affichage_special(matrice,taille_meilleur,meilleur);
	printf("\nsomme divisible par 2 max : %d\n",somme_divisible_par_2);
	free(tbl);
	free(matrice);
}
