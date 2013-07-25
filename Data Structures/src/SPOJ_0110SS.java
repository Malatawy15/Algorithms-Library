import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;


public class SPOJ_0110SS {
	
	static int N;
	static BigInteger [][] dp;
	
	static BigInteger count(int n, int bit){
		if (n==N-1)
			return BigInteger.ONE;
		if (dp[n][bit]!=null)
			return dp[n][bit];
		dp[n][bit] = BigInteger.ZERO;
		if (bit==1)
			dp[n][bit] = dp[n][bit].add(count(n+1,0));
		dp[n][bit] = dp[n][bit].add(count(n+1,1));
		return dp[n][bit];
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		dp = new BigInteger[N+10][2];
		System.out.println(count(0,0).add(count(0,1)));
	}

}
