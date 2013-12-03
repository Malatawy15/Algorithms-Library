import java.io.*;
import java.util.*;
import java.math.*;

public class VerySimpleProblem{
	
	public static BigInteger sqrt(BigInteger n) {
		BigInteger a = BigInteger.ONE;
  		BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
	    while(b.compareTo(a) >= 0) {
		    BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
		    if(mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
		    else a = mid.add(BigInteger.ONE);
	    }
		return a.subtract(BigInteger.ONE);
	}

	
	public static void main(String[]args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		BigInteger bi = new BigInteger(s);
		System.out.println(sqrt(bi));
	}
}