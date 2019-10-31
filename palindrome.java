import java.util.Scanner;

public class palindrome
{
	public static boolean determines_if_palindrome(String sentence)
	{
		int i = sentence.length() - 1;
		for(int j = 0; i < sentence.length() / 2; i++)
		{
			if(sentence.charAt(i) != sentence.charAt(j))
			{
				return false;
			}
			i--;
		}
		return true;
	}

	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		String sentence = new String(input.nextLine());
		if(determines_if_palindrome(sentence) == true)
		{
			System.out.println(sentence + " is a palindrome.");
		}
		else
		{
			System.out.println(sentence + " isn't a palindrome.");
		}
	}
}