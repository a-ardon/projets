#include <stdio.h>
#include <stdlib.h>

void remplissage_matrice1(int matrice[3][3], int nbr_l_c1)
{
	int i,j;
	printf("remplissage matrice 1 (3x3):\n\n");
	for(i = 0; i < nbr_l_c1; i++)
	{
		for(j = 0; j < nbr_l_c1; j++)
		{
			scanf("%d",&matrice[i][j]);
		}
		printf("\n");
	}
}

void affichage_matrice1(int matrice[][3], int nbr_l_c1)
{
	int i,j;
	for(i = 0; i < nbr_l_c1; i ++)
	{
		for(j = 0; j < nbr_l_c1; j++)
		{
			printf("%d ",matrice[i][j]);
		}
		printf("\n");
	}
}

void affichage_matrice2(int matrice[][2], int nbr_l_c2)
{
	int i,j;
	for(i = 0; i < nbr_l_c2; i++)
	{
		for(j = 0; j < nbr_l_c2; j++)
		{
			printf("%d ",matrice[i][j]);
		}
		printf("\n");
	}
}

int is_it_there(int matrice1[][3], int matrice2[][2], int l_courante, int c_courante, int nbr_l_c1, int nbr_l_c2)
{
	if(((l_courante + nbr_l_c2 - 1) < nbr_l_c1) && ((c_courante + nbr_l_c2 - 1) < nbr_l_c1))
	{
		printf(".");
		int i,j,i_bis = 0, j_bis = 0, fix1 = l_courante, fix2 = c_courante;
		for(i = l_courante; i < (fix1 + nbr_l_c2); i++)
		{
			for(j = c_courante; j < (fix2 + nbr_l_c2); j++)
			{
				if(matrice1[i][j] != matrice2[i_bis][j_bis])
				{
					printf("F\n");
					return 0;
				}
				printf("[%d,%d] ",i,j);
				j_bis = j_bis + 1;
			}
			i_bis = i_bis + 1;
			j_bis = 0;
		}
		printf("T\n");
		return 1;
	}
	return 0;
}

int finding_it(int matrice1[][3], int matrice2[][2], int nbr_l_c1, int nbr_l_c2)
{
	int i,j,compteur = 0;
	printf("\n");
	for(i = 0; i < nbr_l_c1; i++)
	{
		for(j = 0; j < nbr_l_c1; j++)
		{
			if(matrice1[i][j] == matrice2[0][0])
			{
				compteur = compteur + is_it_there(matrice1,matrice2,i,j,nbr_l_c1,nbr_l_c2);
			}
		}
	}
	return compteur;
}

void main()
{
	int matrice1[3][3];
	int matrice2[][2] = {{1,1},{3,3}};
	int nbr_l_c1 = 3, nbr_l_c2 = 2;
	affichage_matrice2(matrice2,nbr_l_c2);
	printf("\n");
	remplissage_matrice1(matrice1,nbr_l_c1);
	printf("\n");
	affichage_matrice1(matrice1,nbr_l_c1);
	printf("\n%d\n",finding_it(matrice1,matrice2,nbr_l_c1,nbr_l_c2));
}