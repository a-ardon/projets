import java.util.Scanner;

public class FindTheSubstring
{
	public static int returns_zero_base_index(String str0, int size_str0, String str1, int size_str1)
	{
		int i = 0, j = 0, check = 0, start = 0;
		while(size_str0 - i >= size_str1)
		{
			while(j < size_str1 && check != 1)
			{
				if(str1.charAt(j) != str1.charAt(j) && str0.charAt(j) != '*')
				{
					check = 1;
				}
				if(str1.charAt(i) == str0.charAt(0))
				{
					start = i;
				}
				j++;
			}
			if(j == size_str1)
			{
				return start;
			}
			check = 0;
			start = 0;
			j = 0;
			i++;
		}
		return -1;
	}

	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		String str0 = input.next();
		String str1 = input.next();
		System.out.println(returns_zero_base_index(str0,str0.length(),str1,str1.length()));
	}
}