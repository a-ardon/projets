import java.util.Random;

public class MaximumStreak
{
	public static Random r = new Random();

	public static char present_ou_pas()
	{
		if(r.nextInt() % 2 == 0)
		{
			return 'P'; //present
		}
		return 'A'; //absent
	}
	
	public static void remplissage_array_of_strings(StringBuilder[] array_of_strings, int nbr_of_days, int nbr_of_employees)
	{
		for(int i = 0; i < nbr_of_days; i++)
		{
			array_of_strings[i] = new StringBuilder();
			for(int j = 0; j < nbr_of_employees; j++)
			{
				array_of_strings[i].append(present_ou_pas());	
			}
		}
	}

	public static void affichage_array_of_strings(StringBuilder[] array_of_strings, int nbr_of_days, int nbr_of_employees)
	{
		for(int i = 0; i < nbr_of_days; i++)
		{
			System.out.println("day "+i+": "+array_of_strings[i] + " " + determine_nbr_present(array_of_strings[i],nbr_of_employees) + " employee(s) present\n");	
		}
	}

	public static int determine_nbr_present(StringBuilder presence_by_day, int nbr_of_employees)
	{
		int nbr_of_employees_present = 0;
		for(int i = 0; i < nbr_of_employees; i++)
		{
			if(presence_by_day.charAt(i) == 'P')
			{
				nbr_of_employees_present++;
			}
		}
		return nbr_of_employees_present;
	}

	public static int[] return_best_consecutive_days(StringBuilder[] array_of_strings, int nbr_of_days, int nbr_of_employees)
	{
		int best_presence_so_far = 0, presence_actuel = 0, presence_precedente = 0;
		int nbr_best_consecutive_days = 0, consecutive_days_actuel = 0;
		for(int i = 0; i < nbr_of_days; i++)
		{
			if(i == 0)
			{
				best_presence_so_far = determine_nbr_present(array_of_strings[i],nbr_of_employees);
				presence_actuel = best_presence_so_far;
				nbr_best_consecutive_days = 1;
				consecutive_days_actuel = nbr_best_consecutive_days;
			}
			else
			{
				presence_precedente = presence_actuel;
				presence_actuel = determine_nbr_present(array_of_strings[i],nbr_of_employees);
				if(presence_actuel > best_presence_so_far)
				{
					best_presence_so_far = presence_actuel;
					nbr_best_consecutive_days = 1;
					consecutive_days_actuel = nbr_best_consecutive_days;
				}
				else if(presence_actuel == presence_precedente && presence_actuel == best_presence_so_far)
				{
					consecutive_days_actuel++;
					if(consecutive_days_actuel > nbr_best_consecutive_days)
					{
						nbr_best_consecutive_days = consecutive_days_actuel;
					}
				}
				else if(presence_actuel != presence_precedente)
				{
					consecutive_days_actuel = 1;
				}
			}
		}
		int informations[] = {best_presence_so_far,nbr_best_consecutive_days};
		return informations;
	}

	public static void main(String[] args)
	{
		int nbr_of_days = r.nextInt(6) + 5;
		int nbr_of_employees = r.nextInt(3) + 3;
		System.out.printf("%d employees for %d days of work:\n\n",nbr_of_employees,nbr_of_days);
		StringBuilder[] array_of_strings = new StringBuilder[nbr_of_days];
		remplissage_array_of_strings(array_of_strings,nbr_of_days,nbr_of_employees);
		affichage_array_of_strings(array_of_strings,nbr_of_days,nbr_of_employees);
		int informations[] = return_best_consecutive_days(array_of_strings,nbr_of_days,nbr_of_employees);
		System.out.println("best number of employees present so far : " + informations[0] + " | best number of consecutive days for this presence : " + informations[1]);
	}
}