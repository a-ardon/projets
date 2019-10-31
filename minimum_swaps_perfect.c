#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int verifie_presence_indice(int *tbl, int indice_courant, int nbr_element_pris_en_charge)
{
	for(int i = 0; i < nbr_element_pris_en_charge; i++)
	{
		if(tbl[i] == indice_courant)
		{
			return 1;
		}
	}
	return 0;
}

void affichage_tbl(int *tbl, int taille_tab)
{
	for(int i = 0; i < taille_tab; i++)
	{
		printf("%d ",tbl[i]);
	}
	printf("\n");
}

void remplissage_hasard_tbl(int *tbl, int taille_tab)
{
	int *tbl_indices = malloc(sizeof(taille_tab));
	int val_courante = 1, ind_courant = rand()%taille_tab;
	tbl_indices[val_courante-1] = ind_courant;
	tbl[ind_courant] = val_courante;
	val_courante++;
	for(int i = 1; i < taille_tab; i++)
	{
		ind_courant = rand()%taille_tab;
		while(verifie_presence_indice(tbl_indices,ind_courant,val_courante-1) == 1)
		{
			ind_courant = rand()%taille_tab;
		}
		tbl_indices[val_courante-1] = ind_courant;
		tbl[ind_courant] = val_courante;
		val_courante++;
	}
	free(tbl_indices);
}

int retourne_indice_ayant_valeur(int *tbl, int taille_tab, int valeur_recherche)
{
	int i = 0;
	while(tbl[i] != valeur_recherche)
	{
		i++;
	}
	return i;
}

void swap(int *tbl, int ind_swap1, int ind_swap2)
{
	int temp = tbl[ind_swap1];
	tbl[ind_swap1] = tbl[ind_swap2];
	tbl[ind_swap2] = temp;
}

void minimum_swaps(int *tbl, int taille_tab)
{
	int nbr_swaps = 1;
	for(int i = 0; i < taille_tab; i++)
	{
		if(tbl[i] != (i+1))
		{
			swap(tbl,i,retourne_indice_ayant_valeur(tbl,taille_tab,(i+1)));
			printf("swap #%d:\n\n",nbr_swaps);
			affichage_tbl(tbl,taille_tab);
			printf("\n");
			nbr_swaps++;
		}
	}
	printf("FIN:\n\n");
}

int main()
{
	srand(time(NULL));
	int taille_tab = rand()%8 + 3;
	printf("taille tab : %d\n\n",taille_tab);
	int *tbl = malloc(sizeof(int)*taille_tab);
	remplissage_hasard_tbl(tbl,taille_tab);
	affichage_tbl(tbl,taille_tab);
	printf("\n");
	minimum_swaps(tbl,taille_tab);
	affichage_tbl(tbl,taille_tab);
	free(tbl);
	return 0;
}