import java.util.Scanner;
import java.util.Arrays;

public class meeting_roomsII
{
	public static Scanner input = new Scanner(System.in);

	public static int compteur = 1;

	public static void remplissage_matrice(int matrice[][], int nbr_lignes)
	{
		for(int i = 0; i < nbr_lignes; i++)
		{
			for(int j = 0; j < 2; j++)
			{
				matrice[i][j] = input.nextInt();
			}
		}
	}

	public static void affichage_matrice(int matrice[][], int nbr_lignes)
	{
		for(int i = 0; i < nbr_lignes; i++)
		{
			for(int j = 0; j < 2; j++)
			{
				System.out.println(matrice[i][j] + " ");
			}
			System.out.println();
		}
		System.out.println();
	}

	public static boolean is_it_included(int[] intervalle1, int[] intervalle2)
	{
		System.out.printf("%d - %d\n",intervalle1[0],intervalle1[1]);
		System.out.printf("%d - %d\n",intervalle2[0],intervalle2[1]);
		if(intervalle1[0] <= intervalle2[0] && intervalle2[0] <= intervalle1[1])
		{
			System.out.println("inclu\n");
			return true;
		}
		else if(intervalle2[0] <= intervalle1[0] && intervalle1[0] <= intervalle2[1])
		{
			System.out.println("inclu\n");
			return true;
		}
		System.out.println("exclu\n");
		compteur++;
		return false;
	}

	public static void checker(int[][] matrice, int nbr_lignes)
	{
		for(int i = 0; i < nbr_lignes; i++)
		{
			for(int j = i; j < nbr_lignes; j++)
			{
				if(i != j)
				{
					is_it_included(matrice[i],matrice[j]);
				}
			}
		}
	}

	public static void main(String[] args)
	{
		int nbr_lignes = input.nextInt();
		int[][] matrice = new int[nbr_lignes][2];
		remplissage_matrice(matrice,nbr_lignes);
		System.out.println();
		affichage_matrice(matrice,nbr_lignes);
		checker(matrice,nbr_lignes);
		System.out.println(compteur);
	}
}