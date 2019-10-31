import java.util.Scanner;

public class URLify
{
	public static StringBuilder returns_modified_string(String str, int size_str)
	{
		StringBuilder new_str = new StringBuilder();
		for(int i = 0; i < size_str; i++)
		{
			if(str.charAt(i) == ' ')
			{
				new_str.append("%20");
			}
			else
			{
				new_str.append(str.charAt(i));
			}
		}
		return new_str;
	}

	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		String str = input.nextLine();
		System.out.println(returns_modified_string(str,str.length()));
	}
}