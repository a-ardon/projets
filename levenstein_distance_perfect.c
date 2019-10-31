#include <stdio.h>
#include <stdlib.h>

int returns_string_size(char *string)
{
	int i = 0;
	while(string[i] != '\0')
	{
		i = i + 1;
	}
	return i;
}

/*levenstein distance est le nombre de modifications que l'on doit apporter à une string pour que celle-ci
devienne identique à l'autre string*/

int compares_two_strings(char *s1, char *s2, int *levenstein_d)
{
	int returned_value = 0;
	if(returns_string_size(s1) != returns_string_size(s2))
	{
		returned_value = 1;
		*levenstein_d = returns_string_size(s1) - returns_string_size(s2);
		if(*levenstein_d < 0)
		{
			*levenstein_d = *levenstein_d * (-1);
		}
	}
	for(int i = 0; i < returns_string_size(s1); i++)
	{
		if(((int)s1[i] != (int)s2[i]) && ((int)s1[i] - 32 != (int)s2[i]) && ((int)s1[i] + 32 != (int)s2[i]))
		{
			returned_value = 1;
			*levenstein_d = *levenstein_d + 1;
		}
	}
	return returned_value; 
}


int main()
{
	int levenstein_d = 0;
	char *s1 = malloc(sizeof(10));
	char *s2 = malloc(sizeof(10));
	scanf("%s",s1);
	scanf("%s",s2);
	if(compares_two_strings(s1,s2,&levenstein_d) == 0)
	{
		return 0;
	}
	else
	{
		printf("distance : %d\n",levenstein_d);
		return 1;
	}
	free(s1);
	free(s2);
}