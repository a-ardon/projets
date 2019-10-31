import java.util.Scanner;

public class StringCompression
{
	public static StringBuilder returns_compressed_string(String str, int str_size)
	{
		StringBuilder compressed_string = new StringBuilder();
		int compteur_char_courant = 0;
		char char_courant = str.charAt(0);
		for(int i = 0; i < str_size; i++)
		{
			if(i == 0)
			{
				compressed_string.append(char_courant);
				compteur_char_courant = 1;
			}
			else if(str.charAt(i) != char_courant)
			{
				compressed_string.append(compteur_char_courant);
				char_courant = str.charAt(i);
				compressed_string.append(char_courant);
				compteur_char_courant = 1;
			}
			else
			{
				compteur_char_courant = compteur_char_courant + 1;
			}
		}
		compressed_string.append(compteur_char_courant);
		return compressed_string;
	}

	public static void better_displaying(StringBuilder compressed_string, int compressed_string_size)
	{
		for(int i = 0; i < compressed_string_size; i++)
		{
			if(i != compressed_string_size - 1)
			{
				System.out.print(compressed_string.charAt(i) + " ");				
			}
			else
			{
				System.out.println(compressed_string.charAt(i));
			}
		}
	}

	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		String str = input.next();
		better_displaying(returns_compressed_string(str,str.length()),str.length());
	}
}