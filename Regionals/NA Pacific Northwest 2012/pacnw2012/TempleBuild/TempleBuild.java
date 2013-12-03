import java.util.Arrays;
import java.util.Scanner;


public class TempleBuild {
  static long[] dp = new long[1 << 20];
  
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    while (s.hasNext()) {
      long height = s.nextLong();
      long base = s.nextLong();
      long top = s.nextLong();
      
      long c1 = s.nextLong();
      long c2 = s.nextLong();
      long c3 = s.nextLong();
      
      Arrays.fill(dp, 0);
      long answer = 0;
      for (int i = 1; i <= height; i++) {
        long width = ((height - i) * base + i * top) / height;
        if (i >= c1) dp[i] = Math.max(dp[i], dp[i-(int)c1] + c1 * c1 * c1 * (width / c1) * (width / c1));
        if (i >= c2) dp[i] = Math.max(dp[i], dp[i-(int)c2] + c2 * c2 * c2 * (width / c2) * (width / c2));
        if (i >= c3) dp[i] = Math.max(dp[i], dp[i-(int)c3] + c3 * c3 * c3 * (width / c3) * (width / c3));
        
        answer = Math.max(answer, dp[i]);
      }
      
      System.out.println(answer);
    }
  }
}
