import java.io.*;
import java.util.*;
import java.math.*;

public class AtoB_BtoA{	

	public static void main(String[]args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		BigInteger b1 = new BigInteger(st.nextToken());
		int a = b1.intValue();
		BigInteger b2 = new BigInteger(st.nextToken());
		int b = b2.intValue();
		System.out.println((b1.pow(b)).subtract(b2.pow(a)));
	}
}