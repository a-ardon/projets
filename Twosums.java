import java.util.Scanner;
public class Twosums
{
	public static void remplissage(int[] tbl, int taille_tbl)
	{
		for(int i = 0; i < taille_tbl; i++)
		{
			tbl[i] = i;
		}
	}

	public static void affichage(int[] tbl, int taille_tbl)
	{
		for(int i = 0; i < taille_tbl; i++)
		{
			System.out.println(tbl[i]);
		}
		System.out.println();
	}

	public static void fct(int[] tbl, int taille_tbl, int target)
	{
		int check = 0;
		for(int i = 0; i < taille_tbl; i++)
		{
			for(int j = 0; j < taille_tbl; j++)
			{
				if(j != i)
				{
					if((tbl[i] + tbl[j]) == target)
					{
						check = 1;
						System.out.printf("%d , %d\n",i,j,tbl[i],tbl[j]);
					}
				}
			}
		}
		if(check == 0)
		{
			System.out.println("No solutions.");
		}
	}

	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		int taille_tbl = input.nextInt();
		System.out.printf("\n");
		int tbl[] = new int[taille_tbl];
		remplissage(tbl,taille_tbl);
		affichage(tbl,taille_tbl);
		int target = input.nextInt();
		System.out.println();
		fct(tbl,taille_tbl,target);
	}
}