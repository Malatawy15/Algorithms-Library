import java.util.HashSet;
import java.util.Scanner;


public class MagicMultiple {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    while (s.hasNext()) {
      long n = s.nextLong();
      long k = 0;
      HashSet<Character> digits = new HashSet<Character>();
      while (digits.size() < 10) {
        k++;
        for (char c : Long.valueOf(n * k).toString().toCharArray()) digits.add(c);
      }
      System.out.println(k);
    }
  }
}
