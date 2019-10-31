import java.util.Scanner;
import java.util.ArrayList;

/*
Vérifie si 2 Strings sont permutables sans utiliser d'algorithme de tri,
utilise une ArrayList comptant l'occurence de chaque caractere de notre premier String
et compare l'occurence de ces caractères là à celles des caractères du second String.
*/


public class CheckPermutation
{
	public static int which_index(char the_character, ArrayList<Character> str1_chars, int size_str1_chars)
	{
		for(int i = 0; i < size_str1_chars; i++)
		{
			if(the_character == str1_chars.get(i))
			{
				return i;
			}
		}
		return -1;
	}

	public static int fills_str_chars(String str1, int str1_length, ArrayList<Character> str1_chars, ArrayList<Integer> str1_chars_int)
	{
		int size_str1_chars = 0, check = 0;
		for(int i = 0; i < str1_length; i++)
		{
			char char_courant = str1.charAt(i);
			if(i == 0)
			{
				str1_chars.add(char_courant);
				str1_chars_int.add(1);
				size_str1_chars = size_str1_chars + 1;
			}
			else
			{
				for(int j = 0; j < size_str1_chars; j++)
				{
					if(str1_chars.get(j) == char_courant)
					{		
						int index_to_update = which_index(char_courant,str1_chars,size_str1_chars);
						int value_to_update = (int)str1_chars_int.get(index_to_update) + 1;
						str1_chars_int.set(index_to_update,value_to_update);
						check = 1;
					}
				}
				if(check == 0)
				{
					str1_chars.add(char_courant);
					str1_chars_int.add(1);
					size_str1_chars = size_str1_chars + 1;
				}
				check = 0;
			}
		}
		return size_str1_chars;
	}

	public static boolean check_if_permutation(String str2, int size_str2, ArrayList<Character> str1_chars, ArrayList<Integer> str1_chars_int, int size_str1_chars)
	{
		for(int i = 0; i < size_str1_chars; i++)
		{
			char char_courant = (char)str1_chars.get(i);
			int nbr_occurences = 0;
			for(int j = 0; j < size_str2; j++)
			{
				if(str2.charAt(j) == char_courant)
				{
					nbr_occurences = nbr_occurences + 1;
				}
			}
			if(nbr_occurences != (int)str1_chars_int.get(i))
			{
				return false;
			}
		}
		return true;
	}

	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		String str1 = input.next();
		String str2 = input.next();
		if(str1.length() != str2.length())
		{
			System.out.println("Permutation ? " + (str1.length() == str2.length()));
			return;
		}
		ArrayList<Character> str1_chars = new ArrayList<Character>();
		ArrayList<Integer> str1_chars_int = new ArrayList<Integer>();
		int size_str1_chars = fills_str_chars(str1,str1.length(),str1_chars,str1_chars_int);
		System.out.println(str1_chars);
		System.out.println(str1_chars_int);
		System.out.println("Permutation ? " + check_if_permutation(str2,str2.length(),str1_chars,str1_chars_int,size_str1_chars));
	}
}