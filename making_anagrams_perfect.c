#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void remplissage_arr(char *arr, int taille_arr)
{
	for(int i = 0; i < taille_arr; i++)
	{
		arr[i] = rand()%26 + 97;
	}
}

int verifie_si_deja_present(int *indice_deja_utilises, int compteur_indice_deja_utilises, int indice_actuel)
{
	for(int i = 0; i < compteur_indice_deja_utilises; i++)
	{
		if(indice_deja_utilises[i] == indice_actuel)
		{
			return 1;
		}
	}
	return 0;
}

char *retourne_arr_char_anagrame(char *plus_grand_arr, char *plus_petit_arr, int taille_pg_arr, int taille_pt_arr, int *taille_arr_anagrames)
{
	int *indice_deja_utilises = malloc(sizeof(int)*taille_pg_arr);
	char *arr_char_anagrame = malloc(sizeof(char)*taille_pt_arr);
	int compteur_indice_deja_utilises = 0, compteur_arr_char_anagrame = 0;
	for(int i = 0; i < taille_pt_arr; i++)
	{
		for(int j = 0; j < taille_pg_arr; j++)
		{
			if(plus_petit_arr[i] == plus_grand_arr[j])
			{
				if(compteur_indice_deja_utilises == 0)
				{
					arr_char_anagrame[compteur_arr_char_anagrame] = plus_petit_arr[i];
					indice_deja_utilises[compteur_indice_deja_utilises] = j;
					compteur_arr_char_anagrame++;
					compteur_indice_deja_utilises++;
				}
				else if(verifie_si_deja_present(indice_deja_utilises,compteur_indice_deja_utilises,j) == 0)
				{
					arr_char_anagrame[compteur_arr_char_anagrame] = plus_petit_arr[i];
					indice_deja_utilises[compteur_indice_deja_utilises] = j;
					compteur_arr_char_anagrame++;
					compteur_indice_deja_utilises++;
				}
			}
		}
	}
	free(indice_deja_utilises);
	arr_char_anagrame = realloc(arr_char_anagrame,sizeof(char)*(compteur_arr_char_anagrame));
	*taille_arr_anagrames = compteur_arr_char_anagrame;
	return arr_char_anagrame;
}

void affichage_arr(char *arr, int taille_arr)
{
	for(int i = 0; i < taille_arr; i++)
	{
		printf("%c ",arr[i]);
	}
	printf("\n");
}

int main()
{
	srand(time(NULL));
	int taille_arr1= rand()%8 + 3;
	int taille_arr2 = rand()%8 + 3, taille_arr_anagrames;
	char *arr1 = malloc(sizeof(char)*taille_arr1);
	char *arr2 = malloc(sizeof(char)*taille_arr2);
	remplissage_arr(arr1,taille_arr1);
	remplissage_arr(arr2,taille_arr2);
	char *arr_char_anagrame;
	if(taille_arr1 > taille_arr2)
	{
		arr_char_anagrame = retourne_arr_char_anagrame(arr1,arr2,taille_arr1,taille_arr2,&taille_arr_anagrames);
	}
	else
	{
		arr_char_anagrame = retourne_arr_char_anagrame(arr2,arr1,taille_arr2,taille_arr1,&taille_arr_anagrames);
	}
	printf("taille_arr1 : %d\n\n",taille_arr1);
	affichage_arr(arr1,taille_arr1);
	printf("\ntaille_arr2 : %d\n\n",taille_arr2);
	affichage_arr(arr2,taille_arr2);
	printf("\n");
	if(taille_arr_anagrames != 0)
	{
		printf("les/la %d lettre(s) pouvant former un anagrame a partir de arr1 et arr2:\n\n",taille_arr_anagrames);
		affichage_arr(arr_char_anagrame,taille_arr_anagrames);
	}
	else
	{
		printf("Aucunes lettres pouvant former un anagrame n'ont ete trouvees.\n");
	}
	free(arr1);
	free(arr2);
	free(arr_char_anagrame);
	return 0;
}