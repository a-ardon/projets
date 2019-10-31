#include <stdio.h>
#include <stdlib.h>

int determine_taille(char *string)
{
	int i = 0;
	while(string[i] != '\0')
	{
		i++;
	}
	return i;
}

void setup(char *heure, int cas, int *saxad1, int *saxad2)
{
	if(cas == 0)
	{
		*saxad1 = heure[0] - '0';
		*saxad2 = heure[2] - '0';
		*saxad2 = *saxad2 * 10 + (heure[3] - '0'); 
	}
	else
	{
		*saxad1 = heure[0] - '0';
		*saxad1 = *saxad1 * 10 + (heure[1] - '0');
		*saxad2 = heure[3] - '0';
		*saxad2 = *saxad2 * 10 + (heure[4] - '0');
	}
}

void translation(char hours[][7], int saxad1, int saxad2)
{
	if(saxad2 == 0)
	{
		printf("%s o'clock\n",hours[saxad1-1]);
	}
	else if(saxad2 < 30)
	{
		if(saxad2 == 1)
		{
			printf("%d minute past %s\n",saxad2,hours[saxad1-1]);
		}
		else
		{
			printf("%d minutes past %s\n",saxad2,hours[saxad1-1]);
		}
	}
	else if(saxad2 == 30)
	{
		printf("half past %s\n",hours[saxad1-1]);
	}
	else
	{
		if(saxad1 == 12)
		{
			if(saxad2 == 59)
			{
				printf("one minute to one\n");
			}
			else
			{
				int minutes_restantes = 60 - saxad2;
				printf("%d minutes to one\n",minutes_restantes);
			}
		}
		else
		{
			if(saxad2 == 59)
			{
				printf("one minute to %s\n",hours[saxad2]);
			}
			else
			{
				int minutes_restantes = 60 - saxad2;
				printf("%d minutes to %s\n",minutes_restantes,hours[saxad1]);
			}
		}
	}
}

int main()
{
	char hours[][7] = {"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve"};
	char heure[5];
	scanf("%s",heure);
	int saxad1, saxad2;
	if(determine_taille(heure) < 4 || determine_taille(heure) > 5)
	{
		return 1;
	}
	else if(determine_taille(heure) == 4)
	{
		setup(heure,0,&saxad1,&saxad2);
	}
	else
	{
		setup(heure,1,&saxad1,&saxad2);
	}
	if(saxad1 < 1 || saxad1 > 12 || saxad2 > 59)
	{
		return 1;
	}
	translation(hours,saxad1,saxad2);
	return 0;
}