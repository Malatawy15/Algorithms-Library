import java.io.*;
import java.util.*;
import java.math.*;

public class Calendar1{

	
	public static void main(String[]args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int d = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
		GregorianCalendar c = new GregorianCalendar(2001,m,d);
		c.setLenient(false);
		try{
			c.getTime();
			c.computeFields();
			if (c.DAY_OF_WEEK==Calendar.MONDAY){
				System.out.println(1);
			}
			if (c.DAY_OF_WEEK==Calendar.TUESDAY){
				System.out.println(2);
			}
			if (c.DAY_OF_WEEK==Calendar.WEDNESDAY){
				System.out.println(3);
			}
			if (c.DAY_OF_WEEK==Calendar.THURSDAY){
				System.out.println(4);
			}
			if (c.DAY_OF_WEEK==Calendar.FRIDAY){
				System.out.println(5);
			}
			if (c.DAY_OF_WEEK==Calendar.SATURDAY){
				System.out.println(6);
			}
			if (c.DAY_OF_WEEK==Calendar.SUNDAY){
				System.out.println(7);
			}
		}
		catch(Exception e){
			System.out.println("Impossible");
		}
	}
}