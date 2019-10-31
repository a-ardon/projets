#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void remplissage_str_hasard(char *str, int taille_str)
{
	for(int i = 0; i < taille_str; i++)
	{
		str[i] = rand()%5 + 97;
		printf("%c ",str[i]);
	}
	printf("\n\n");
}

void affichage_tbl_int(int *tbl, int taille_tbl)
{
	for(int i = 0; i < taille_tbl; i++)
	{
		printf("%d ",tbl[i]);
	}
	printf("\n\n");
}

int determine_si_lettre_deja_vu(char *arr_lettres_uniques, int compteur_lettres_uniques, char lettre_actuel)
{
	for(int i = 0; i < compteur_lettres_uniques; i++)
	{
		if(arr_lettres_uniques[i] == lettre_actuel)
		{
			return 1;
		}
	}
	return 0;
}

int retourne_nbr_occurence(char *str, int taille_str, int lettre_recherche)
{
	int compteur_lettre_courante = 0;
	for(int i = 0; i < taille_str; i++)
	{
		if(str[i] == lettre_recherche)
		{
			compteur_lettre_courante++;
		}
	}
	return compteur_lettre_courante;
}

char *retourne_arr_lettres_uniques(char *str, int taille_str, int *taille_arr_lettres_uniques, int *tbl_occurences_lettres_uniques)
{
	int compteur_lettres_uniques = 0, compteur_lettre_courante = 0;
	char *arr_lettres_uniques = malloc(sizeof(char)*taille_str);
	for(int i = 0; i < taille_str; i++)
	{
		if(i == 0)
		{
			arr_lettres_uniques[compteur_lettres_uniques] = str[i];
			compteur_lettre_courante = retourne_nbr_occurence(str,taille_str,str[i]);
			tbl_occurences_lettres_uniques[compteur_lettres_uniques] = compteur_lettre_courante;
			compteur_lettres_uniques++;
		}
		else
		{
			if(determine_si_lettre_deja_vu(arr_lettres_uniques,compteur_lettres_uniques,str[i]) == 0)
			{
				arr_lettres_uniques[compteur_lettres_uniques] = str[i];
				compteur_lettre_courante = retourne_nbr_occurence(str,taille_str,str[i]);
				tbl_occurences_lettres_uniques[compteur_lettres_uniques] = compteur_lettre_courante;
				compteur_lettres_uniques++;
			}
		}
	}
	*taille_arr_lettres_uniques = compteur_lettres_uniques;
	arr_lettres_uniques = realloc(arr_lettres_uniques,sizeof(char)*compteur_lettres_uniques);
	tbl_occurences_lettres_uniques = realloc(tbl_occurences_lettres_uniques,sizeof(int)*compteur_lettres_uniques);
	return arr_lettres_uniques;
}


void affichage_special(char *arr_lettres_uniques, int taille_arr_lettres_uniques, int *tbl_occurences_lettres_uniques)
{
	for(int i = 0; i < taille_arr_lettres_uniques; i++)
	{
		if(i != taille_arr_lettres_uniques - 1)
		{
			printf("%c : %d | ",arr_lettres_uniques[i],tbl_occurences_lettres_uniques[i]);
		}
		else
		{
			printf("%c : %d\n",arr_lettres_uniques[i],tbl_occurences_lettres_uniques[i]);
		}
	}
}

int determine_si_sherlock_valid_string(int *tbl, int taille_tbl)
{
 	int	min = tbl[0], max = tbl[taille_tbl-1], i;
	if((max - min) > 1)
	{
		return 1;
	}
	int nbr_tailles_diff = 1, check_supplementaire = 0;
	for(i = 0; i < taille_tbl - 1; i++)
	{
		if(tbl[i] < tbl[i+1])
		{
			nbr_tailles_diff++;
			if(check_supplementaire == 0)
			{
				check_supplementaire = 1;
			}
		}
		if(check_supplementaire > 0 && tbl[i] == tbl[i+1])
		{
			check_supplementaire++;
		}
	}
	if(nbr_tailles_diff < 2 || (check_supplementaire + 1) == taille_tbl || check_supplementaire == 1)
	{
		return 0;
	}
	return 1;
}

void swap(int *a, int *b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}

int partition(int *arr, int low, int high) 
{ 
    int pivot = arr[high]; 
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++;
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
}

void quickSort(int *arr, int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

int main()
{
	srand(time(NULL));
	int taille_str = rand()%6 + 5;
	printf("taille_str : %d\n\n",taille_str);
	char *str = malloc(sizeof(char)*taille_str);
	remplissage_str_hasard(str,taille_str);
	int taille_arr_lettres_uniques;
	int *tbl_occurences_lettres_uniques = malloc(sizeof(int)*taille_str);
	char *arr_lettres_uniques = retourne_arr_lettres_uniques(str,taille_str,&taille_arr_lettres_uniques,tbl_occurences_lettres_uniques);
	affichage_special(arr_lettres_uniques,taille_arr_lettres_uniques,tbl_occurences_lettres_uniques);
	quickSort(tbl_occurences_lettres_uniques,0,taille_arr_lettres_uniques-1);
	printf("\n");
	affichage_tbl_int(tbl_occurences_lettres_uniques,taille_arr_lettres_uniques);
	if(determine_si_sherlock_valid_string(tbl_occurences_lettres_uniques,taille_arr_lettres_uniques) == 0)
	{
		printf("%s est une string sherlock valide\n",str);
	}
	else
	{
		printf("%s n'est pas une string sherlock valide\n",str);
	}
	free(str);
	free(tbl_occurences_lettres_uniques);
	free(arr_lettres_uniques);
	return 0;
}