import java.util.Scanner;

public class Practice
{
	public static void main(String [] args)
	{
		Scanner kb = new Scanner(System.in);
		int n;

		n = kb.nextInt();
		kb.nextLine();//flush \n

		String line;

		for (int i = 0; i < n; i++)
		{
			line = kb.nextLine();
			System.out.println(line.charAt(line.length()-1));
		}

		
	}
}