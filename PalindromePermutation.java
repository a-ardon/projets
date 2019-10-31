import java.util.Scanner;

public class PalindromePermutation
{
	public static boolean checks_if_palindrome(StringBuilder str_b, int size_str)
	{
		int j = size_str - 1;
		for(int i = 0; i < size_str / 2; i++)
		{
			if(str_b.charAt(i) != str_b.charAt(j))
			{
				return false;
			}
			j = j - 1;
		}
		return true;
	}

	public static void displays_its_palindromes(String str, int size_str)
	{
		StringBuilder potential_palindrome = new StringBuilder();
		
	}

	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		String str = input.nextLine();

	}
}