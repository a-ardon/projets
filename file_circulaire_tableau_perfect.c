#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

#define TAILLE_MAX 10

/* implémentation d'une file circulaire à l'aide d'un tableau qui comporte une multitude de tests
attestant du bon fonctionnement de cette implémentation */

typedef struct queue
{
	int tab[TAILLE_MAX];
	int size, front, end;
}queue;

int IsEmptyQueue(queue *ma_pile)
{
	if(ma_pile->size)
	{
		return 0;
	}
	return 1;
}

int IsFullQueue(queue *ma_pile)
{
	if(ma_pile->size >= TAILLE_MAX)
	{
		return 1;
	}
	return 0;
}

void EnQueue(queue *ma_pile, int element)
{
	if(IsFullQueue(ma_pile))
	{
		printf("Queue overflow\n");
	}
	ma_pile->tab[ma_pile->end] = element;
	ma_pile->end++;
	ma_pile->end = ma_pile->end % TAILLE_MAX;
	ma_pile->size++;
}

int DeQueue(queue *ma_pile)
{
	if(IsEmptyQueue(ma_pile))
	{
		return -99;
	}
	int element_a_retourner = ma_pile->tab[ma_pile->front];
	ma_pile->front++;
	ma_pile->front = ma_pile->front % TAILLE_MAX;
	ma_pile->size--;
	return element_a_retourner;
}

int donne_END_intelligible(int mon_end)
{
	if(mon_end == 0)
	{
		return TAILLE_MAX-1;
	}
	return mon_end - 1;
}

void affichageQueue(queue *ma_pile)
{
	int i = ma_pile->front ,j = 0;
	printf("DEBUT\n");
	while(j < ma_pile->size)
	{
		printf("[%d] : [%d]\n",i,ma_pile->tab[i]);
		i++;
		i = i % TAILLE_MAX;
		j++;
	}
	printf("FIN\nSIZE : %d | FRONT : %d | END : %d\n",ma_pile->size,ma_pile->front,donne_END_intelligible(ma_pile->end));
}

void random_dequeue(queue *ma_pile, int nbr_elements_a_supprimer)
{
	if(nbr_elements_a_supprimer > 0)
	{
		printf("OUT = %d\n",nbr_elements_a_supprimer);
		for(int i = 0; i < nbr_elements_a_supprimer; i++)
		{
			if(DeQueue(ma_pile) == -99)
			{
				printf("Fatal error\n");
				exit(1);
			}
		}
	}
	else
	{
		printf("OUT <= 0\n");
	}
}

void remplissage_queue(queue *ma_pile)
{
	while(!IsFullQueue(ma_pile))
	{
		EnQueue(ma_pile,rand()%10);
	}
}

void test_bon_fonctionnement(queue *ma_pile, int nbr_tests)
{
	for(int i = 0; i < nbr_tests; i++)
	{
		if(i != 0)
		{
			printf("\n");
		}
		random_dequeue(ma_pile,rand()%ma_pile->size-2);
		affichageQueue(ma_pile);
		printf("\n");
		remplissage_queue(ma_pile);
		printf("FIX\n");
		affichageQueue(ma_pile);
	}
}

void initialisation_queue(queue *ma_pile)
{
	for(int i = 0; i < TAILLE_MAX; i++)
	{
		EnQueue(ma_pile,rand()%10);
	}
}

void main()
{
	srand(time(NULL));
	queue *ma_pile = malloc(sizeof(queue));
	ma_pile->size = ma_pile->front = ma_pile->end = 0;
	initialisation_queue(ma_pile);
	printf("START\n\n");
	affichageQueue(ma_pile);
	printf("\n");
	test_bon_fonctionnement(ma_pile,3);
	free(ma_pile);
}