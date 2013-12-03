import java.util.Random;
import java.io.*;

public class GoodVersusEvilInputGen
{

	public static void main(String [] args) throws FileNotFoundException
	{
	
		PrintStream output = new PrintStream("GoodVersusEvilInputGen.in");
		//Random number from 0 through 1000
		int max = 1001;
		Random rand = new Random();
		
		//number of battles
		int battles = 100;
		
		for (int i = 0; i < battles; i++)
		{
			//generate good guys -6 categories
			output.println(rand.nextInt(max) + " " + rand.nextInt(max) + " " + rand.nextInt(max)
								+ " " + rand.nextInt(max) + " " + rand.nextInt(max) + " " + rand.nextInt(max));
			//now generate the bad guys - 7 categories
			output.println(rand.nextInt(max) + " " + rand.nextInt(max) + " " + rand.nextInt(max)
								+ " " + rand.nextInt(max) + " " + rand.nextInt(max) + " " + rand.nextInt(max)
								+ " " + rand.nextInt(max));
		
		}//end for
		
		output.close();
	
	
	}//end main


}//end class