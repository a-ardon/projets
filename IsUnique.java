import java.util.Scanner;

/*optimized, no additional data structures have been used*/

public class IsUnique
{
	public static boolean unique_characters(String str, int str_length)
	{
		for(int i = 0; i < str_length; i++)
		{
			if(i != 0)
			{
				for(int j = 0; j < i; j++)
				{
					if(str.charAt(j) == str.charAt(i))
					{
						return false;
					}
				}
			}
		}
		return true;
	}

	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		String str = input.next();
		System.out.println("Unique ? " + unique_characters(str,str.length()));
	}
}