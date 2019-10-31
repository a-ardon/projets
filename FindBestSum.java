import java.util.Random; 

/*
		finds the group with the least amount of elements whose sum is either equal to the target or
		is as close as possible
 */

public class FindBestSum
{
	public static Random r = new Random();

	public static void remplissage(int[] arr, int taille_arr)
	{
		for(int i = 0; i < taille_arr; i++)
		{
			arr[i] = r.nextInt(20);
		}
	}

	public static int retourne_random_value(int[] arr, int taille_arr)
	{
		int nbr_fois = r.nextInt(1) + 4;
		int valeur = 0;
		for(int i = 0; i < nbr_fois; i++)
		{
			valeur = valeur + arr[r.nextInt(taille_arr)];
		}
		return valeur;
	}

	public static void affichage(int[] arr, int taille_arr, int valeur)
	{
		System.out.println("valeur : "+valeur);
		for(int i = 0; i < taille_arr; i++)
		{
			System.out.print(arr[i] + " ");
		}
		System.out.println("\n");
	}

	public static int retourne_le_meilleur_max(int[]arr, int taille_arr, int limite)
	{
		int max = -1;
		for(int i = 0; i < taille_arr; i++)
		{
			if(arr[i] > max && arr[i] <= limite)
			{
				max = arr[i];
			}
		}
		return max; 
	}

	public static void find_best_group(int[] arr, int taille_arr, int valeur)
	{
		int score_so_far = 0;
		int best_max = retourne_le_meilleur_max(arr,taille_arr,valeur);
		int limite = valeur - best_max, check = 0;
		while(limite > 0 && best_max > 0)
		{
			if(check == 0)
			{
				check = 1;
			}
			System.out.print(best_max + " ");
			score_so_far = score_so_far + best_max;
			best_max = retourne_le_meilleur_max(arr,taille_arr,limite);
			limite = limite - best_max;
		}
		if(check == 0 && best_max == 0)
		{
			System.out.print(best_max + " ");
		}
		else if(check == 0 && best_max == -1)
		{
			System.out.print("No match found for ");
		}
		if(best_max > 0)
		{
			score_so_far = score_so_far + best_max;
			System.out.print(best_max + " ");
		}
		System.out.println(": "+score_so_far);
	}

	public static void main(String[] args)
	{
		int taille_arr = r.nextInt(3) + 5;
		int[] arr = new int[taille_arr];
		remplissage(arr,taille_arr);
		int valeur = retourne_random_value(arr,taille_arr);
		affichage(arr,taille_arr,valeur);
		find_best_group(arr,taille_arr,valeur);
	}
}