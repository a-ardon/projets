#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct noeud
{
	int data;
	struct noeud *next;
}noeud;

void creation_liste_chainee(noeud *head, int nbr_noeuds)
{
	noeud *courant = head;
	for(int i = 1; i < nbr_noeuds; i++)
	{
		if(i == 1)
		{
			courant->data = rand()%9 + 1;
		}
		else
		{
			courant->data = rand()%10;
		}
		courant->next = malloc(sizeof(noeud));
		courant = courant->next;
	}
	courant->data = rand()%8 + 1; 
	courant->next = NULL;
}

void affichage_liste_chainee(noeud *head)
{
	noeud *courant = head;
	while(courant->next != NULL)
	{
		printf("%d->",courant->data);
		courant = courant->next;
	}
	printf("%d\n",courant->data);
}

int donne_taille_et_tbl_liste_chainee(noeud *head,int *tbl)
{
	noeud *courant = head;
	tbl[0] = courant->data;
	int taille = 0;
	while(courant != NULL)
	{
		taille++;
		tbl = realloc(tbl,sizeof(int)*taille);
		tbl[taille-1] = courant->data;
		courant = courant->next;
	}
	return taille;
}

void cleaning_liste_chainee(noeud *head)
{
	noeud *courant = head, *precedent;
	while(courant->next != NULL)
	{
		precedent = courant;
		courant = courant->next;
		free(precedent);
	}
	free(courant);
}

int obtient_nombre(int *tbl, int taille_tbl)
{
	int somme = 0, multiplicateur = 1;
	for(int i = 0; i < taille_tbl; i++)
	{
		somme = somme + tbl[i] * multiplicateur;
		multiplicateur = multiplicateur * 10;
	}
	return somme;
}

int retourne_nbr_noeuds_final(int nbr)
{
	int i = 0;
	while(nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return i;
}

char *retourne_tbl_somme(int nbr)
{
	int nbr_noeuds_final = retourne_nbr_noeuds_final(nbr);
	char *buffer = malloc(sizeof(char)*nbr_noeuds_final);
	sprintf(buffer,"%d",nbr);
	return buffer;
}

void liste_chainee_finale(int nbr, noeud *head)
{
	int nbr_noeuds_final = retourne_nbr_noeuds_final(nbr), i;
	char *buffer = retourne_tbl_somme(nbr);
	noeud *courant = head;
	for(i = 1; i < nbr_noeuds_final; i++)
	{
		courant->data = buffer[i-1] - '0';
		courant->next = malloc(sizeof(noeud));
		courant = courant->next;
	}
	courant->data = buffer[i-1] - '0';
	courant->next = NULL;
}

void main()
{
	srand(time(NULL));
	int nbr_noeuds = rand()%4 + 2, nbr_noeuds_final;
	noeud *head1 = malloc(sizeof(noeud)), *head2 = malloc(sizeof(noeud));
	creation_liste_chainee(head1,nbr_noeuds);
	creation_liste_chainee(head2,nbr_noeuds);
	int *tbl1 = malloc(sizeof(int)*1), *tbl2 = malloc(sizeof(int)*1);
	printf("nbr_noeuds : %d\n\n",nbr_noeuds);
	affichage_liste_chainee(head1);
	int taille1 = donne_taille_et_tbl_liste_chainee(head1,tbl1);
	printf("taille1 : %d\n\n",taille1);
	affichage_liste_chainee(head2);
	int taille2 = donne_taille_et_tbl_liste_chainee(head2,tbl2);
	printf("taille2 : %d\n\n",taille2);
	int somme1 = obtient_nombre(tbl1,taille1), somme2 = obtient_nombre(tbl2,taille2);
	printf("%d + %d ",somme1,somme2);
	somme1 = somme1 + somme2; 
	printf("= %d\n\n",somme1);
	noeud *head3 = malloc(sizeof(noeud));
	liste_chainee_finale(somme1,head3);
	affichage_liste_chainee(head3);
	free(tbl1);
	free(tbl2);
	cleaning_liste_chainee(head1);
	cleaning_liste_chainee(head2);
	cleaning_liste_chainee(head3);
}