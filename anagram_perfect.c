#include <stdio.h>
#include <stdlib.h>

int *donne_tbl_tailles_elements(char matrice[][20], int nbr_lignes_matrice)
{
	int *tbl_tailles_elements = malloc(sizeof(int)*nbr_lignes_matrice), j = 0;
	for(int i = 0; i < nbr_lignes_matrice; i++)
	{
		while(matrice[i][j] != '\0')
		{
			j++;
		}
		tbl_tailles_elements[i] = j;
		j = 0;
	}
	return tbl_tailles_elements;
}

char *retourne_lettres_uniques(char *mot, int *taille_mot)
{
	int j = 0, taille_precedente_mot = *taille_mot;
	char *lettres_uniques = malloc(sizeof(char)*taille_precedente_mot);
	for(int i = 0; i < taille_precedente_mot; i++)
	{
		if(i == 0)
		{
			lettres_uniques[0] = mot[0];
			*taille_mot = 1;
		}
		else
		{
			while((j < i) && (lettres_uniques[j] != mot[i]))
			{
				j++;
			}
			if(j == i)
			{
				lettres_uniques[*taille_mot] = mot[i];
				*taille_mot = *taille_mot + 1;
			}
			j = 0;
		}
	}
	return lettres_uniques;
}

int anagrame_ou_pas(char *lettres_uniques1, int t_lettres_uniques1, char *lettres_uniques2, int t_lettres_uniques2)
{
	if(t_lettres_uniques1 != t_lettres_uniques2)
	{
		return 0;
	}
	int check = 0;
	for(int i = 0; i < t_lettres_uniques1; i++)
	{
		for(int j = 0; j < t_lettres_uniques2; j++)
		{
			if(lettres_uniques1[i] == lettres_uniques2[j])
			{
				check++;
			}
		}
		if(check == 0)
		{
			return 0;
		}
		check = 0;
	}
	return 1;
}

void affichage_list_of_anagrams(char matrice[][20], char **matrice_lettres_uniques, int nbr_lignes_matrice, int *tbl_tailles_elements, int *tbl_successes)
{
	int check = 0, nbr_groupes_anagrames = 1;
	for(int i = 0; i < nbr_lignes_matrice; i++)
	{
		if(tbl_successes[i] == 0)
		{
			for(int j = 0; j < nbr_lignes_matrice; j++)
			{
				if(anagrame_ou_pas(matrice_lettres_uniques[i],tbl_tailles_elements[i],matrice_lettres_uniques[j],tbl_tailles_elements[j]) == 1)
				{
					check++;
					tbl_successes[j] = nbr_groupes_anagrames;
				}
			}
		}
		if(check != 0)
		{
			tbl_successes[i] = nbr_groupes_anagrames;
			for(int k = 0; k < nbr_lignes_matrice; k++)
			{
				if(tbl_successes[k] == nbr_groupes_anagrames)
				{
					printf("%s ",matrice[k]);
				}
			}
			check = 0;
			nbr_groupes_anagrames++;
			printf("\n");
		}
	}
}

int main(void)
{
	char matrice[][20] = {"pear","amleth","dormitory","tinsel","dirtyroom","hamlet","listen","silnet"};
	int nbr_lignes_matrice = sizeof(matrice)/sizeof(matrice[0]),i;
	int *tbl_tailles_elements = donne_tbl_tailles_elements(matrice,nbr_lignes_matrice);
	int *tbl_successes = malloc(sizeof(int)*nbr_lignes_matrice);
	for(i = 0; i < nbr_lignes_matrice; i++)
	{
		printf("%s : %d\n",matrice[i],tbl_tailles_elements[i]);
		tbl_successes[i] = 0;
	}
	printf("\n\n\n");
	char **matrice_lettres_uniques = malloc(sizeof(char*)*nbr_lignes_matrice);
	for(i = 0; i < nbr_lignes_matrice; i++)
	{
		matrice_lettres_uniques[i] = retourne_lettres_uniques(matrice[i],&tbl_tailles_elements[i]);
		printf("%s : %d\n",matrice_lettres_uniques[i],tbl_tailles_elements[i]);	
	}
	printf("\n");
	affichage_list_of_anagrams(matrice,matrice_lettres_uniques,nbr_lignes_matrice,tbl_tailles_elements,tbl_successes);
	free(tbl_tailles_elements);
	free(tbl_successes);
	for(i = 0; i < nbr_lignes_matrice; i++)
	{
		free(matrice_lettres_uniques[i]);
	}
	free(matrice_lettres_uniques);
	return 0;
}