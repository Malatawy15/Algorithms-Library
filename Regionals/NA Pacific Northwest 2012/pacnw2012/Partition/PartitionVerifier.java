import java.awt.Point;
import java.awt.geom.Point2D;
import java.io.File;
import java.io.PrintStream;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class PartitionVerifier {
    // what to return as output
    static final String ACCEPTED  = "yes";
    static final String INCORRECT = "Wrong Output";
    static final String INCOMPLETE= "Incomplete Output";
    static final String EXCESSIVE = "Excessive Output";
    static final String UNKNOWN   = "undetermined";
    
  public static class AngleComparator implements Comparator<Point> {
    @Override
    public int compare(Point a, Point b) {
      if (a.x * b.y - b.x * a.y == 0) {
        if (30000 * a.x - a.y < 0 && 30000 * b.x - b.y > 0) return -1;
        if (30000 * a.x - a.y > 0 && 30000 * b.x - b.y < 0) return 1;
      }
      return a.x * b.y - b.x * a.y;
    }
  }
  
  public static class SoftAngleComparator implements Comparator<Point> {
    @Override
    public int compare(Point a, Point b) {
      return a.x * b.y - b.x * a.y;
    }
  }
  
  static AngleComparator cmp = new AngleComparator();
  static SoftAngleComparator softCmp = new SoftAngleComparator();
  
  static int n, w, h;
  
  static Point nextPoint(Scanner s) {return new Point(2 * s.nextInt() - w, 2 * s.nextInt() - h);}
  
  public static void main(String[] args) throws Exception {
    if (args.length != 4) {
      System.out.println("usage: java PartitionVerifier Partition.in program_output Partition.out result_file");
      System.exit(1);
    }
    
    // stuff to report later
    String outcome  = ACCEPTED;
    String message  = "Everything OK";
    PrintStream res = new PrintStream(new File(args[3]));
    
    Scanner output = new Scanner(new File(args[1]));
    Scanner input = new Scanner(new File(args[0]));
    
    int tc = 0;
    boolean ok = true;
    outer: while (true) {
      tc++;
      n = input.nextInt();
      w = input.nextInt();
      h = input.nextInt();
      if (n == 0) break;
      System.out.print("TEST CASE #" + tc + ": ");
      
      Set<Point> allPoints = new HashSet<Point>();
      for (int i = 0; i < n; i++) {
        allPoints.add(nextPoint(input));
      }
      
      Set<Point> half = new HashSet<Point>();
      for (int i = 0; i < n / 2; i++) {
        Point next;
        try {
          next = nextPoint(output);
        } catch (Exception e) {
          System.out.println("ERROR: malformed output");
          ok = false;
          outcome = (output.hasNext() ? INCORRECT : INCOMPLETE);
          message = "TEST CASE #" + tc + ": ERROR: malformed output";
          break outer;
        }
        
        if (half.contains(next)) {
          System.out.println("INCORRECT: duplicate point");
          outcome = INCORRECT;
          message = "TEST CASE #" + tc + ": INCORRECT: duplicate point " + next;
          ok = false;
          break outer;
        }
        
        if (!allPoints.contains(next)) {
          System.out.println("INCORRECT: nonexistent point");
          outcome = INCORRECT;
          message = "TEST CASE #" + tc + ": INCORRECT: nonexistent point " + next;
          ok = false;
          break outer;
        }
        
        half.add(next);
        allPoints.remove(next);
      }
      
      Point firstA = null;
      Point lastA = null;
      for (Point p : half) {
        if (firstA != null && softCmp.compare(firstA, p) == 0 && cmp.compare(firstA, p) != 0) {lastA = p; break;}
        if (lastA != null && softCmp.compare(lastA, p) == 0 && cmp.compare(lastA, p) != 0) {firstA = p; break;}
        if (firstA == null || cmp.compare(firstA, p) < 0) firstA = p;
        if (lastA == null || cmp.compare(lastA, p) > 0) lastA = p;
      }
      
      boolean aLine = softCmp.compare(firstA, lastA) == 0;
      if (aLine && cmp.compare(firstA, lastA) != 0) {
        for (Point p : half) {
          if (softCmp.compare(firstA, p) < 0 || softCmp.compare(lastA, p) > 0) {
            Point tmp = firstA; firstA = lastA; lastA = tmp;
            aLine = false;
            break;
          }
          if (softCmp.compare(firstA, p) > 0 || softCmp.compare(lastA, p) < 0) {
            aLine = false;
            break;
          }
        }
      }
      
      for (Point p : half) {
        if (softCmp.compare(firstA, p) < 0 || softCmp.compare(lastA, p) > 0) {
          System.out.println("INCORRECT: given points not all in one half");
          outcome = INCORRECT;
          message = "TEST CASE #" + tc + ": INCORRECT: given points not all in one half";
          ok = false;
          break outer;
        }
      }
      
      Point firstB = null;
      Point lastB = null;
      for (Point p : allPoints) {
        if (firstB != null && softCmp.compare(firstB, p) == 0 && cmp.compare(firstB, p) != 0) {lastB = p; break;}
        if (lastB != null && softCmp.compare(lastB, p) == 0 && cmp.compare(lastB, p) != 0) {firstB = p; break;}
        if (firstB == null || cmp.compare(firstB, p) < 0) firstB = p;
        if (lastB == null || cmp.compare(lastB, p) > 0) lastB = p;
      }
      
      boolean bLine = softCmp.compare(firstB, lastB) == 0;
      if (bLine && cmp.compare(firstB, lastB) != 0) {
        for (Point p : allPoints) {
          if (softCmp.compare(firstB, p) < 0 || softCmp.compare(lastB, p) > 0) {
            Point tmp = firstB; firstB = lastB; lastB = tmp;
            bLine = false;
            break;
          }
          if (softCmp.compare(firstB, p) > 0 || softCmp.compare(lastB, p) < 0) {
            bLine = false;
            break;
          }
        }
      }
      
      for (Point p : allPoints) {
        if (softCmp.compare(firstB, p) < 0 || softCmp.compare(lastB, p) > 0) {
          System.out.println("INCORRECT: remaining points not all in one half");
          outcome = INCORRECT;
          message = "TEST CASE #" + tc + ": INCORRECT: remaining points not all in one half";
          ok = false;
          break outer;
        }
      }
      
      if ((softCmp.compare(firstA, firstB) > 0 && softCmp.compare(lastA, firstB) < 0) ||
          (softCmp.compare(firstA, lastB) > 0 && softCmp.compare(lastA, lastB) < 0)) {
        System.out.println("INCORRECT: halves overlap");
        outcome = INCORRECT;
        message = "TEST CASE #" + tc + ": INCORRECT: halves overlap";
        ok = false;
        break outer;
      }
      
      if (!aLine && !bLine && ((cmp.compare(firstA, firstB) > 0 && cmp.compare(lastA, firstB) < 0) ||
          (cmp.compare(firstA, lastB) > 0 && cmp.compare(lastA, lastB) < 0))) {
        System.out.println("INCORRECT: halves overlap");
        outcome = INCORRECT;
        message = "TEST CASE #" + tc + ": INCORRECT: halves overlap";
        ok = false;
        break outer;
      }
      
      System.out.println("OK");
    }
    
    if (ok && output.hasNext()) {
      System.out.println("ERROR: extra output at end of file");
      outcome = EXCESSIVE;
      message = "ERROR: extra output at end of file";
      ok = false;
    }
    
    if (!ok) {
      System.out.println("REJECT");
    } else {
      System.out.println("ACCEPT");
    }
    
    if (res != null)
    {
        // write the result to the result file
        res.println("<?xml version=\"1.0\"?>");
        res.println("<result outcome=\"" + outcome +
                    "\" security=\"" + args[3] +
                    "\"> " + message + " </result>");
        res.close();
    }
  }
}
