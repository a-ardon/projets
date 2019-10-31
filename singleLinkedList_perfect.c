#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

void rajouter_au_debut(node **head)
{
	node *foo = malloc(sizeof(node));
	foo->data = 100;
	foo->next = (*head);
	(*head) = foo;
}

void rajouter_a_la_fin(node *noeud)
{
	while(noeud->next != NULL)
	{
		noeud = noeud->next;
	}
	node *foo = malloc(sizeof(node));
	foo->data = 200;
	foo->next = NULL;
	noeud->next = foo;
}
void remplissage(node *noeud)
{
	int i = 0;
	while(noeud != NULL)
	{
		noeud->data = i;
		i = i + 1;
		noeud = noeud->next;
	}
}

void affichage(node *noeud)
{
	while(noeud != NULL)
	{
		printf("%d\n",noeud->data);
		noeud = noeud->next;
	}
}

int determine_nbr_noeuds(node *noeud)
{
	int compteur = 0;
	while(noeud != NULL)
	{
		compteur = compteur + 1;
		noeud = noeud->next;
	}
	return compteur;
}

void ajout_noeud_everywhere(node **noeud, int whereTo)
{
	if(whereTo == 1) //rajoute un element au tout début de la single linked list
	{
		node *foo = malloc(sizeof(node)); 
		foo->data = 999;
		foo->next = (*noeud);
		(*noeud) = foo;
	}
	else if(whereTo == determine_nbr_noeuds(*noeud)) //rajoute un element à la toute fin de la single linked list
	{
		node *node_bis = *noeud; 
		while(node_bis->next != NULL)
		{
			node_bis = node_bis->next;
		}
		node *foo = malloc(sizeof(node)); 
		foo->data = 999;
		node_bis->next = foo;
		foo->next = NULL;
	}
	else //rajoute un élement entre le début et la fin (début & fins exclus)
	{
		int i = 0;
		node *node_bis = (*noeud);
		while(i < (whereTo-2))
		{
			node_bis = node_bis->next;
			i = i + 1;
		}
		node *foo = malloc(sizeof(node)); 
		foo->data = 999;
		foo->next = node_bis->next;
		node_bis->next = foo;
	}
}

void main()
{
	node *first = malloc(sizeof(node));
	node *second = malloc(sizeof(node));
	node *third = malloc(sizeof(node));
	first->next = second;
	second->next = third;
	third->next = NULL;
	remplissage(first);
	rajouter_au_debut(&first);
	affichage(first);
	printf("\n");
	rajouter_a_la_fin(first);
	affichage(first);
	printf("\n");
	int whereTo;
	printf("%d\n\n",determine_nbr_noeuds(first));
	scanf("%d",&whereTo);
	while((whereTo < 1) || (whereTo > determine_nbr_noeuds(first)))
	{
		scanf("%d",&whereTo);
	}
	printf("\n");
	ajout_noeud_everywhere(&first,whereTo);
	affichage(first);
	free(first);
	free(second);
	free(third);
}