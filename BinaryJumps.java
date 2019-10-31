import java.util.Random;

public class BinaryJumps
{
	public static Random r = new Random();

	public static remplissage_arr(int[] arr, int taille_arr)
	{
		for(int i = 0; i < taille_arr; i++)
		{
			arr[i] = r.nextInt(2);
		}
	}

	public static int affichage(int[] arr, int taille_arr)
	{
		for(int i = 0; i < taille_arr; i++)
		{
			System.out.printf("%d ",arr[i]);
		}
		System.out.println("\n");
	}

	
	
	public static void main(String[] args)
	{
		int taille_arr = r.nextInt(5) + 6;
		int arr = new int[taille_arr];
	}
}