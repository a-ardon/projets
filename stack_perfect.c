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
	for(i = 0; i < (nbr_noeuds-1); i++)
	{
		courant->data = i;
		courant->next = malloc(sizeof(noeud));
		courant = courant->next;
	}
	courant->data = i;
	courant->next = NULL;
	return head;
}

void affichage_liste(noeud *head)
{
	noeud *courant = head;
	while(courant != NULL)
	{
		printf("%d\n",courant->data);
		courant = courant->next;
	}
}

noeud *suppression_noeud(noeud *head, int rang_noeud)
{
	if(rang_noeud == 0)
	{
		noeud *new_head = head->next;
		free(head);
		return new_head;
	}
	noeud *now = head, *before;
	for(int i = 0; i < rang_noeud; i++)
	{
		before = now;
		now = now->next;
	}
	before->next = now->next;
	free(now);
	return head;
}

void free_liste_chainee(noeud *head)
{
	 noeud *now = head, *before;
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
	noeud *head = retourne_head(10);
	affichage_liste(head);
	printf("\n");
	int x = scanf("%d",&x);
	head = suppression_noeud(head,x);
	printf("\n");
	affichage_liste(head);
	free_liste_chainee(head);
}
