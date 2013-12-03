import java.util.Scanner;


public class SarumansLevelUp {
  static long[][] choose = new long[64][64];
  
  public static void main(String[] args) {
    for (int i = 0; i < 64; i++) {
      choose[i][0] = choose[i][i] = 1;
      for (int j = 1; j < i; j++) {
        choose[i][j] = choose[i-1][j] + choose[i-1][j-1];
      }
    }
    
    Scanner s = new Scanner(System.in);
    while (s.hasNext()) {
      long n = s.nextLong();
      long answer = 0;
      int bitCount = Long.bitCount(n);
      if (bitCount % 3 == 0) answer++;
      for (int curBit = 0; (1L << curBit) <= n; curBit++) {
        if (((1L << curBit) & n) == 0) continue;
        
        bitCount--;
        for (int i = 0; i <= curBit; i++) if ((i + bitCount) % 3 == 0 && i + bitCount > 0) answer += choose[curBit][i];
      }
      
      System.out.println("Day " + n + ": Level = " + answer);
    }
  }
}
