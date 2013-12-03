/*
	Gimme problem for ICPC PacNW 2012 contest
	All teams should solve this one
	No special algorithm needed
	Can use single int vars or arrays to store data

*/
import java.util.Scanner;

public class GoodVersusEvil
{
	public static void main(String [] args)
	{
	
		Scanner kb = new Scanner(System.in);
		//Race [] good = new Race[6];
		//Race [] evil = new Race[7];
		int [] goodWorth = { 1, 2, 3, 3, 4, 10 };
		int [] evilWorth = {1, 2, 2, 2, 3, 5, 10};
		
		//these arrays aren't strictly necessary, but are 
		// handy in case I change the problem specs a little bit
		int [] goodCount = new int[6];
		int [] evilCount = new int[7];
		
		int battles = 0;
		int goodSum, evilSum;
		
		//read in battles
		battles = kb.nextInt();
		for (int battle = 1; battle <= battles; battle++)
		{
			goodSum = evilSum = 0;
			//read in good guys count
			for (int g = 0; g < goodCount.length; g++)
			{
				//could remove first line below and just kb data
				// for calculation...
				goodCount[g] = kb.nextInt();
				goodSum += goodWorth[g]*goodCount[g];
			}
				
			//now read in evil guys' count
			for (int e = 0; e < evilCount.length; e++)
			{
				evilCount[e] = kb.nextInt();
				evilSum += evilWorth[e]*evilCount[e];
			}
			
			System.out.print("Battle " + battle + ": ");
			if (goodSum > evilSum)
				System.out.println("Good triumphs over Evil");
			else if (evilSum > goodSum)
				System.out.println("Evil eradicates all trace of Good");
			else
				System.out.println("No victor on this battle field");
				
			
		
		
		}//end for
	
	
	}//end main
/*	
	private class Race
	{
		int worth, count;
		
		Race(int worth)
		{
			this.worth = worth;
			this.count = 0;
		
		}
		
		int value()
		{
			return worth*count;
		
		}
	
	}
*/


}//end class