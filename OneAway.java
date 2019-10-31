import java.util.Scanner;

public class OneAway
{
	public static void insert_remove_or_replace(String str1, String str2, int str1_size, int str2_size)
	{
		System.out.println();
		if(str1_size < str2_size)
		{
			System.out.println(str1 + " " + str2 + " -> insert.");
		}
		else if(str1_size >str2_size)
		{
			System.out.println(str1 + " " + str2 + " -> remove.");
		}
		else
		{
			for(int i = 0; i < str1_size; i++)
			{
				if(str1.charAt(i) != str2.charAt(i))
				{
					System.out.println(str1 + " " + str2 + " -> replace - index : " + i + " | character : " + str2.charAt(i));
					return;
				}
			}
		}
		return;
	}

	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		String str1 = input.next();
		String str2 = input.next();
		insert_remove_or_replace(str1,str2,str1.length(),str2.length());
	}
}