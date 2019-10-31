#include <stdio.h>
#include <stdlib.h>

typedef struct noeud
{
	int data;
	struct noeud *next;
}noeud;

noeud *retourne_head(int nbr_noeuds)
{
	int i;
	noeud *head = malloc(sizeof(noeud));
	noeud *courant = head;
	for(i = 0; i < nbr_noeuds - 1; i++)
	{
		courant->data = i;
		courant->next = malloc(sizeof(noeud));
		courant = courant->next;
	}
	courant->data = i;
	courant->next = NULL;
	return head;
}

void affichage(noeud *head)
{
	noeud *courant = head;
	while(courant != NULL)
	{
		printf("%d\n",courant->data);
		courant = courant->next;
	}
	printf("\n");
}

int determine_nbr_noeuds(noeud *head)
{
	int i = 0;
	noeud *courant = head;
	while(courant != NULL)
	{
		i++;
		courant = courant->next;
	}
	return i;
}

noeud *reverse_linked_list(noeud *head)
{
	int *tbl = malloc(sizeof(int)*determine_nbr_noeuds(head)), i = 0;
	noeud *new_head = malloc(sizeof(noeud));
	noeud *courant = head, *new_courant = new_head; 
	while(courant != NULL)
	{
		tbl[i] = courant->data;
		courant = courant->next;
		i++;
	}
	for(i = i - 1; i >= 0; i--)
	{
		new_courant->data = tbl[i];
		if(i == 0)
		{
			new_courant->next = NULL;
		}
		else
		{
			new_courant->next = malloc(sizeof(noeud));
			new_courant = new_courant->next;
		}
	}
	free(tbl);
	return new_head;
}

void liberation_memoire(noeud *head)
{
	noeud *before, *now = head;
	while(now->next != NULL)
	{
		before = now;
		now = now->next;
		free(before);
	}
	free(now);
}

void main()
{
	int nbr_noeuds;
	scanf("%d",&nbr_noeuds);
	printf("\n");
	noeud *head = retourne_head(nbr_noeuds);
	noeud *new_head = reverse_linked_list(head);
	affichage(head);
	affichage(new_head);
	liberation_memoire(head);
	liberation_memoire(new_head);
}