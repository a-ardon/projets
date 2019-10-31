import java.util.Random;
import java.util.ArrayList;

public class RotateMatrix
{
	public static Random r = new Random();

	public static void filling_matrix_randomly(int[][] matrix, int nbr_rows, int nbr_columns)
	{
		for(int i = 0; i < nbr_rows; i++)
		{
			for(int j = 0; j < nbr_columns; j++)
			{
				matrix[i][j] = r.nextInt(10);
			}
		}
	}

	public static void display_matrix(int[][] matrix, int nbr_rows, int nbr_columns)
	{
		System.out.printf("%d x %d\n",nbr_rows,nbr_columns);
		for(int i = 0; i < nbr_rows; i++)
		{
			for(int j = 0; j < nbr_columns; j++)
			{
				System.out.print(matrix[i][j] + " ");
			}
			System.out.println();
		}
	}

	public static ArrayList<Integer> return_column(int[][] matrix, int column_number, int nbr_rows)
	{
		ArrayList<Integer> column = new ArrayList<Integer>();
		for(int i = nbr_rows - 1; i >= 0; i--)
		{
			column.add(matrix[i][column_number]);
		}
		//System.out.println(column);
		return column;
	}
	
	public static int[][] ninety_degree_matrix_rotation(int[][] matrix, int nbr_rows, int nbr_columns)
	{
		int[][] rotated_matrix = new int[nbr_columns][nbr_rows];
		//System.out.println();
		for(int i = 0; i < nbr_columns; i++)
		{
			ArrayList<Integer> new_row = return_column(matrix,i,nbr_rows);
			for(int j = 0; j < nbr_rows; j++)
			{
				rotated_matrix[i][j] = new_row.get(j);
			}
		}
		return rotated_matrix;
	}

	public static void main(String[] args)
	{
		int nbr_rows = r.nextInt(5) + 3;
		int nbr_columns = r.nextInt(5) + 3;
		int[][] matrix = new int[nbr_rows][nbr_columns];
		filling_matrix_randomly(matrix,nbr_rows,nbr_columns);
		display_matrix(matrix,nbr_rows,nbr_columns);
		int[][] rotated_matrix = ninety_degree_matrix_rotation(matrix,nbr_rows,nbr_columns);
		System.out.println();
		display_matrix(rotated_matrix,nbr_columns,nbr_rows);
	}
}