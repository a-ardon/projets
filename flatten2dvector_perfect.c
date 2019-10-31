#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void creation_matrice(int **matrice, int nbr_elements_matrice, int *tbl_taille)
{
	int i,j;
	for(i = 0; i < nbr_elements_matrice; i++)
	{
		tbl_taille[i] = rand() % 5 + 1;
		matrice[i] = malloc(sizeof(int)*tbl_taille[i]);
		for(j = 0; j < nbr_elements_matrice; j++)
		{
			matrice[i][j] = rand() % 10;
		}
	}
}

void affichage_matrice(int **matrice, int nbr_elements_matrice, int *tbl_taille)
{
	for(int i = 0; i < nbr_elements_matrice; i++)
	{
		for(int j = 0; j < tbl_taille[i]; j++)
		{
			printf("%d ",matrice[i][j]);
		}
		printf("\n");
	}
}

void affichage_tableau(int *tableau, int taille_tableau)
{
	printf("\n");
	for(int i = 0; i < taille_tableau; i++)
	{
		printf("%d\n",tableau[i]);
	}
}

int retourne_nbr_elements(int *tbl_taille, int nbr_elements_matrice)
{
	int nbr_elements_total = 0;
	for(int i = 0; i < nbr_elements_matrice; i++)
	{
		nbr_elements_total = nbr_elements_total + tbl_taille[i];
	}
	return nbr_elements_total;
}

void flatten_matrice(int **matrice, int nbr_elements_matrice, int *tbl_taille, int *tableau_cible)
{
	int i,j,k = 0;
	for(i = 0; i < nbr_elements_matrice; i++)
	{
		for(j = 0; j < tbl_taille[i]; j++)
		{
			tableau_cible[k] = matrice[i][j];
			k = k + 1;
		}
	}
}

void main()
{
	srand(time(NULL));
	int nbr_elements_matrice = 5;
	int **matrice = malloc(sizeof(int*)*nbr_elements_matrice);
	int *tbl_taille = malloc(sizeof(int)*nbr_elements_matrice);
	creation_matrice(matrice,nbr_elements_matrice,tbl_taille);
	affichage_matrice(matrice,nbr_elements_matrice,tbl_taille);
	int nbr_elements_total = retourne_nbr_elements(tbl_taille,nbr_elements_matrice);
	int *tableau_cible = malloc(sizeof(int)*nbr_elements_total);
	flatten_matrice(matrice,nbr_elements_matrice,tbl_taille,tableau_cible);
	affichage_tableau(tableau_cible,nbr_elements_total);
	free(matrice);
	free(tbl_taille);
	free(tableau_cible);
}