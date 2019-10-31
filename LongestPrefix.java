import java.util.Scanner;
public class LongestPrefix
{
	public static int donne_petite_taille(String[] tbl_string, int taille_tbl)
	{
		int petite_taille = tbl_string[0].length();
		for(int i = 1; i < taille_tbl; i++)
		{
			if(tbl_string[i].length() < petite_taille)
			{
				petite_taille = tbl_string[i].length();
			}
		}
		return petite_taille;
	}

	public static void affichage_tbl(char[] tbl_char, int taille_tbl)
	{
		for(int i = 0; i < taille_tbl; i++)
		{
			System.out.printf("%c",tbl_char[i]);
		}
		System.out.println();
	}

	public static void prefix(String[] tbl_string, int taille_tbl)
	{
		int petite_taille = donne_petite_taille(tbl_string,taille_tbl), i = 0, j = 0;
		char tbl_char[] = new char[petite_taille];
		char lettre_actuelle;
		int checkeur = 0;
		while((i < petite_taille) && (checkeur != 1))
		{
			lettre_actuelle = tbl_string[0].charAt(i);
			for(j = 1; j < taille_tbl; j++)
			{
				if(tbl_string[j].charAt(i) != lettre_actuelle)
				{
					checkeur = 1;
				}
			}
			if(checkeur != 1)
			{
				tbl_char[i] = lettre_actuelle;
				i = i + 1;
			}
		}
		if(i != 0)
		{
			affichage_tbl(tbl_char,i);
		}
	}

	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		int taille_tbl = input.nextInt();
		String tbl_string[] = new String[taille_tbl];
		for(int i = 0; i < taille_tbl; i++)
		{
			System.out.printf("Element %d\n",i);
			tbl_string[i] = input.next();
		}
		int petite_taille = donne_petite_taille(tbl_string,taille_tbl);
		System.out.println(petite_taille);
		System.out.println();
		prefix(tbl_string,taille_tbl);
	}
}