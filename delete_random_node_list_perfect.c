#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *previous;
	struct node *next;
}node;

node *return_head(int nbr_nodes)
{
	int i, val = 0;
	node *current = malloc(sizeof(node)), *before;
	node *head = current;
	for(i = 0; i < (nbr_nodes - 1); i++)
	{
		if(i != 0)
		{
			current->previous = before;
		}
		current->data = val;
		val = val + 10;
		current->next = malloc(sizeof(node));
		before = current;
		current = current->next;
	}
	current->data = val; 
	current->previous = before;
	current->next = head;
	head->previous = current;
	return head;
}

void lecture_file_circulaire(node *head, int nbr_tours)
{
	printf("\n");
	int i = 0, j = 0, rang_noeud = 0;
	node *current = head;
	while(j < nbr_tours)
	{
		printf("tour #%d:\n",j);
		while(i < 2)
		{
			if(current == head)
			{
				i++;
			}
			if(i < 2)
			{
				printf("noeud #%d: %d\n",rang_noeud,current->data);
				current = current->next;
				rang_noeud++;
			}
		}
		i = 0;
		rang_noeud = 0;
		j++;
		printf("\n");
	}
}

node *suppression_certain_noeud(node *head, int rang_noeud)
{
	if(rang_noeud == 0)
	{
		head->previous->next = head->next;
		head->next->previous = head->previous;
		node *new_head = head->next;
		free(head);
		return new_head;
	}
	node *current = head;
	for(int i = 0; i < rang_noeud; i++)
	{
		current = current->next;
	}
	current->previous->next = current->next;
	current->next->previous = current->previous;
	free(current);
	return head;
}

void cleaning_file_circulaire(node *head)
{
	node *current = head->next, *before;
	while(current != head)
	{
		before = current;
		current = current->next;
		free(before);
	}
	free(current);
}

void maj_nbr_nodes(node *head,int *nbr_nodes)
{
	int i = 0;
	node *current = head->next;
	while(current != head)
	{
		i = i + 1;
		current = current->next;
	}
	*nbr_nodes = i + 1;
}

int main()
{
	/*int nbr_nodes,nbr_tours,rang_noeud_a_supprimer;
	printf("nbr nodes: ");
	scanf("%d",&nbr_nodes);
	printf("nbr tours: ");
	scanf("%d",&nbr_tours);*/
	int nbr_nodes = 10,nbr_tours = 1,rang_noeud_a_supprimer;
	node *head = return_head(nbr_nodes);
	lecture_file_circulaire(head,nbr_tours);
	printf("noeud_a_supprimer : ");
	scanf("%d",&rang_noeud_a_supprimer);
	if(rang_noeud_a_supprimer < 0 || rang_noeud_a_supprimer >= nbr_nodes)
	{
		printf("usage: nbr_nodes\n");
		return 1;
	}
	head = suppression_certain_noeud(head,rang_noeud_a_supprimer);
	lecture_file_circulaire(head,1);
	cleaning_file_circulaire(head);
	return 0;
}