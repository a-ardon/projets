#include <stdio.h>
#include <stdlib.h>

int donne_valeur_lettre(char *alphabet, char lettre)
{
	for(int i = 0; i < 26; i++)
	{
		if(alphabet[i] == lettre)
		{
			return (i+1);
		}
	}
}

int retourne_taille_string(char *string)
{
	int i = 0;
	while(string[i] != '\0')
	{
		i++;
	}
	return i;
}

long donne_score_string(char *string, char *alphabet)
{
	long score = 0;
	int i, j = 1, taille_string = retourne_taille_string(string);
	for(i = taille_string - 1; i >= 0; i--)
	{
		score = score + donne_valeur_lettre(alphabet,string[i]) * j;
		j = j * 10;
	}
	return score;
}

int next_worst(char *string, char *alphabet)
{
	int taille_string = retourne_taille_string(string);
	if(taille_string == 1 || taille_string == 0)
	{
		return 1;
	}
	char temp;
	int i = taille_string - 2, j = taille_string - 1;
	while(i >= 0)
	{
		if(donne_valeur_lettre(alphabet,string[i]) < donne_valeur_lettre(alphabet,string[j]))
		{
			temp = string[i];
			string[i] = string[j];
			string[j] = temp;
			return 0;
		}
		j = j - 1;
		i = i - 1;
	}
	return 1;
}

void main()
{
	char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char *foo = malloc(sizeof(char)*10), *foo_bis = malloc(sizeof(char)*10);
	scanf("%s",foo);
	scanf("%s",foo_bis);
	printf("\n%ld\n%ld\n",donne_score_string(foo,alphabet),donne_score_string(foo_bis,alphabet));
	printf("\n%s : %d\n%s : %d\n",foo,next_worst(foo,alphabet),foo_bis,next_worst(foo_bis,alphabet));
	free(foo);
	free(foo_bis);
}
