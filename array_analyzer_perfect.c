#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void remplissage_tbl(int *tbl, int taille_tbl)
{
	for(int i = 0; i < taille_tbl; i++)
	{
		tbl[i] = rand()%20;
	}
}

void affichage_generaliste(int *tbl, int taille_tbl, int target)
{
	printf("target : %d\n\n",target);
	for(int i = 0; i < taille_tbl; i++)
	{
		printf("%d\n",tbl[i]);
	}
	printf("\n");
}

int presence_target(int *tbl, int taille_tbl, int target, int *rang1, int *rang2)
{
	int value_so_far;
	for(int i = 0; i < taille_tbl; i++)
	{
		value_so_far = tbl[i];
		for(int j = 0; j < taille_tbl; j++)
		{
			if((value_so_far + tbl[j]) == target)
			{
				*rang1 = i;
				*rang2 = j;
				return 1;
			}
		}
	}
	return 0;
}


int main(void)
{
	srand(time(NULL));
	int taille_tbl = rand()%10+7, target = rand()%8+15, rang1, rang2;
	int *tbl = malloc(sizeof(int)*taille_tbl);
	remplissage_tbl(tbl,taille_tbl);
	affichage_generaliste(tbl,taille_tbl,target);
	if(presence_target(tbl,taille_tbl,target,&rang1,&rang2) == 1)
	{
		printf("present : rangs %d (%d), %d (%d)\n",rang1,rang2,tbl[rang1],tbl[rang2]);
	}
	else
	{
		printf("absent\n");
	}
	free(tbl);
	return 0;
}