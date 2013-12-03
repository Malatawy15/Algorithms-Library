import java.awt.Point;
import java.io.File;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Random;
import java.util.Scanner;


public class PartitionGen {
  static Random rnd = new Random(0);
  
  static void genSquare(int w, PrintWriter out) throws Exception {
    if (((w + (w/2) + (w/3) + (w/4)) % 2) == 1) return;
    out.println((w + (w/2) + (w/3) + (w/4)) + " " + (2 * w + 1) + " " + (2 * w + 1));
    for (int i = 0; i < w; i++) out.println((w - i) + " " + (w - i));
    for (int i = 1; i < w; i+=2) out.println((w - i) + " " + (w + i + 1));
    for (int i = 2; i < w; i+=3) out.println((w + i + 1) + " " + (w + i + 1));
    for (int i = 3; i < w; i+=4) out.println((w + i + 1) + " " + (w - i));
  }
  
  static void genRandom(int n, int w, int h, PrintWriter out) {
    HashSet<Point> pts = new HashSet<Point>();
    pts.add(null);
    out.println(n + " " + w + " " + h);
    for (int i = 0; i < n; i++) {
      Point pt = null;
      while (pts.contains(pt)) pt = new Point(rnd.nextInt(w-1) + 1, rnd.nextInt(h-1) + 1);
      pts.add(pt);
      out.println(pt.x + " " + pt.y);
    }
  }
  
  public static void main(String[] args) throws Exception {
    PrintWriter out = new PrintWriter(new File("partition.in"));
    
    Scanner sample = new Scanner(new File("partition-sample.in"));
    while (true) {
      int n = sample.nextInt(), w = sample.nextInt(), h = sample.nextInt();
      if (n == 0) break;
      
      out.println(n + " " + w + " " + h);
      for (int i = 0; i < n; i++) {
        out.println(sample.nextInt() + " " + sample.nextInt());
      }
    }
    
    for (int i = 1; i < 5000; i *= 2) {
      genSquare(i, out);
    }
    
    genRandom(100, 2, 9999, out);
    genRandom(100, 4, 9999, out);
    genRandom(100, 3, 10000, out);
    
    genRandom(200, 9999, 2, out);
    genRandom(200, 9999, 4, out);
    genRandom(200, 10000, 3, out);
    
    for (int i = 10000; i <= 50000; i += 10000) {
      genRandom(i, 9999, 10000, out);
    }
    
    out.println("0 0 0");
    out.close();
  }
}
