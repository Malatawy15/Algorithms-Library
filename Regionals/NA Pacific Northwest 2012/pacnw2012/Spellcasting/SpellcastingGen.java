import java.io.File;
import java.io.PrintWriter;
import java.util.Random;
import java.util.Scanner;


public class SpellcastingGen {
  static Random rnd = new Random(0);
  static int max = 1000000000;
  
  static void genBalancedRandom(int n, PrintWriter out) throws Exception {
    out.println(n + " " + (1 + rnd.nextInt(10)) + " " + (1 + rnd.nextInt(max)));
    for (int i = 1; i <= n; i++) out.println((1000000+rnd.nextInt(100000)) + " 50 " + rnd.nextInt(i));
  }
  
  static void genRandomChain(int n, PrintWriter out) throws Exception {
    out.println(n + " " + (1 + rnd.nextInt(10)) + " " + (1 + rnd.nextInt(max)));
    for (int i = 1; i <= n; i++) out.println((1 + rnd.nextInt(max)) + " " + (1 + rnd.nextInt(1000)) + " " + (i-1));
  }
  
  static void genBalancedRandomChain(PrintWriter out) throws Exception {
    out.println("1000 1 1000000000");
    out.println("10000000 0 2");
    for (int i = 1; i < 999; i++) {
      out.println((1000000+rnd.nextInt(100000)) + " 50 " + (i+2));
    }
    out.println("10000000 0 0");
  }
  
  static void genSpecial(PrintWriter out) throws Exception {
    out.println("1 1 1000000000");
    out.println("1000000000 1 0");
    out.println("1 1000 1");
    out.println("1 1 0");
    out.println("2 1 1000000000");
    out.println("10000000 500 2");
    out.println("1000000 50 0");
    out.println("1000 1 1000000000");
    out.println("10000000 500 2");
    for (int i = 1; i < 999; i++) {
      out.println((1000000+i) + " 50 " + (i+2));
    }
    out.println("30000 2 0");
  }
  
  public static void main(String[] args) throws Exception {
    PrintWriter out = new PrintWriter(new File("spellcasting.in"));
    
    Scanner sample = new Scanner(new File("spellcasting-sample.in"));
    while (true) {
      int n = sample.nextInt(), e = sample.nextInt(), p = sample.nextInt();
      if (n == 0) break;
      
      out.println(n + " " + e + " " + p);
      for (int i = 0; i < n; i++) {
        out.println(sample.nextInt() + " " + sample.nextInt() + " " + sample.nextInt());
      }
    }
    
    for (int n = 1; n < 1000; n *= 2) genBalancedRandom(n, out);
    for (int n = 1; n < 1000; n *= 2) genRandomChain(n, out);
    
    for (int i = 0; i < 5; i++) genBalancedRandom(1000, out);
    for (int i = 0; i < 5; i++) genRandomChain(1000, out);
    
    for (int i = 0; i < 5; i++) genBalancedRandomChain(out);
    genSpecial(out);
    
    out.println("0 0 0");
    
    out.close();
  }
}
